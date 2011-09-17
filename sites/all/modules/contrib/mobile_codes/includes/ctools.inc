<?php
/**
 * @file
 * CTools module integration.
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mobile_codes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "mobile_codes" && in_array($api, array("default_mobile_codes_presets", "default_mobile_codes_providers"))) {
    return array("version" => 2);
  }
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function mobile_codes_ctools_plugin_directory($module, $plugin) {
  if ($module == 'ctools' && $plugin == 'export_ui') {
    return "plugins/{$plugin}";
  }
}

/**
 * Implements hook_mobile_codes_theme_alter() on behalf of ctools.module.
 */
function ctools_mobile_codes_theme_alter(&$items) {
  $items['mobile_codes_providers_export_ui_form_parameters'] = array(
    'render element' => 'element',
    'file' => 'includes/ctools.inc',
  );
}

/**
 * Presets form.
 */
function mobile_codes_presets_export_ui_form(&$form, &$form_state) {
  $providers = ctools_export_crud_load_all('mobile_codes_providers');

  $form['info']['#type'] = 'container';
  $form['info']['#attributes'] = array(
    'class' => array('clearfix'),
  );

  $form['info']['provider'] = array(
    '#type' => 'select',
    '#title' => t('Provider'),
    '#options' => array(),
    '#default_value' => $form_state['item']->provider,
    '#ajax' => array(
      'callback' => 'mobile_codes_presets_export_ui_form_js',
      'wrapper' => 'defaults-wrapper',
    ),
  );
  foreach ($providers as $provider) {
    if (!$provider->disabled) {
      $form['info']['provider']['#options'][$provider->name] = $provider->name;
    }
  }
  asort($form['info']['provider']['#options']);

  $form['preset']['defaults'] = array(
    '#type' => 'fieldset',
    '#title' => t('Defaults'),
    '#prefix' => '<div id="defaults-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  $provider = isset($form_state['values']) ? $form_state['values']['provider'] : $form_state['item']->provider;
  $provider = isset($provider) ? $provider : current($form['info']['provider']['#options']);
  $provider = ctools_export_crud_load('mobile_codes_providers', $provider);

  $defaults = isset($form_state['values']) ? $form_state['values']['defaults'] : $form_state['item']->defaults;

  foreach (element_children($provider->parameters) as $parameter) {
    switch ($provider->parameters[$parameter]['type']) {
      case 'select':
        $provider->parameters[$parameter]['value'] = explode("\n", $provider->parameters[$parameter]['value']);
        $options = array();
        foreach ($provider->parameters[$parameter]['value'] as $value) {
          $value = explode('|', $value);
          $options[$value[0]] = isset($value[1]) ? $value[1] : $value[0];
        }
        $form['preset']['defaults'][$parameter] = array(
          '#type' => 'select',
          '#title' => isset($provider->parameters[$parameter]['label']) ? $provider->parameters[$parameter]['label'] : $parameter,
          '#options' => $options,
          '#default_value' => isset($defaults[$parameter]) ? $defaults[$parameter] : current($options),
        );
        break;

      case 'text':
        $form['preset']['defaults'][$parameter] = array(
          '#type' => 'textfield',
          '#title' => isset($provider->parameters[$parameter]['label']) ? $provider->parameters[$parameter]['label'] : $parameter,
          '#size' => 5,
          '#default_value' => isset($defaults[$parameter]) ? $defaults[$parameter] : '',
          '#required' => TRUE,
        );
        break;
    }
  }
}

/**
 * Presets form submit callback.
 */
function mobile_codes_presets_export_ui_form_submit(&$form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Presets form AJAX calback.
 */
function mobile_codes_presets_export_ui_form_js($form, $form_state) {
  return $form['preset']['defaults'];
}

/**
 * Providers form.
 */
function mobile_codes_providers_export_ui_form(&$form, &$form_state) {
  $form['provider']['url'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('clearfix'),
    ),
  );

  $form['provider']['url']['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => isset($form_state['item']->url) ? $form_state['item']->url : '',
    '#ajax' => array(
      'callback' => 'mobile_codes_providers_export_ui_form_js',
      'wrapper' => 'parameters-wrapper',
    ),
    '#required' => TRUE,
  );

  $form['provider']['parameters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Parameters'),
    '#theme' => 'mobile_codes_providers_export_ui_form_parameters',
    '#prefix' => '<div id="parameters-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  $url = !empty($form_state['values']) ? $form_state['values']['url'] : $form_state['item']->url;
  $parameters = !empty($form_state['values']) ? $form_state['values']['parameters'] : $form_state['item']->parameters;

  preg_match_all('/\[(.*?)\]/', $url, $tokens, PREG_SET_ORDER);
  foreach ($tokens as $token) {
    $form['provider']['parameters'][$token[1]]['token'] = array(
      '#type' => 'value',
      '#value' => $token[1],
    );

    if ($parameters[$token[1]]['type'] != 'data') {
      $form['provider']['parameters'][$token[1]]['label'] = array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#size' => 30,
        '#default_value' => isset($parameters[$token[1]]) ? $parameters[$token[1]]['label'] : '',
      );
    }

    $form['provider']['parameters'][$token[1]]['type'] = array(
      '#type' => 'select',
      '#options' => array(
        'data' => t('Data'),
        'select' => t('Selectbox'),
        'text' => t('Textfield'),
      ),
      '#default_value' => isset($parameters[$token[1]]) ? $parameters[$token[1]]['type'] : 'text',
      '#ajax' => array(
        'callback' => 'mobile_codes_providers_export_ui_form_js',
        'wrapper' => 'parameters-wrapper',
      ),
      '#prefix' => '<div class="clearfix">',
      '#suffix' => '</div>',
    );

    if (isset($parameters[$token[1]]) && $parameters[$token[1]]['type'] == 'select') {
      $form['provider']['parameters'][$token[1]]['value'] = array(
        '#type' => 'textarea',
        '#title' => t('Values'),
        '#default_value' => isset($parameters[$token[1]]) ? $parameters[$token[1]]['value'] : '',
      );
    }
  }
}

/**
 *
 */
function theme_mobile_codes_providers_export_ui_form_parameters($variables) {
  $element = $variables['element'];

  $headers = array(t('Token'), t('Label'), t('Type'), t('Values'));
  $rows = array();
  foreach (element_children($element) as $child) {
    foreach (element_children($element[$child]) as $field) {
      unset($element[$child][$field]['#title']);
    }

    $rows[] = array(
      array('data' => drupal_render($element[$child]['token']) . "[{$element[$child]['token']['#value']}]"),
      array('data' => drupal_render($element[$child]['label'])),
      array('data' => drupal_render($element[$child]['type'])),
      array('data' => drupal_render($element[$child]['value'])),
    );
  }

  return theme('table', array('header' => $headers, 'rows' => $rows));
}

/**
 * Providers form submit callback.
 */
function mobile_codes_providers_export_ui_form_submit(&$form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Providers form AJAX calback.
 */
function mobile_codes_providers_export_ui_form_js($form, $form_state) {
  return $form['provider']['parameters'];
}
