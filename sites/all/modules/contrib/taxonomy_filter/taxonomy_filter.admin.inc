<?php

/**
 * @file
 * The administration settings pages for the Taxonomy Filter module.
 */

// TODO: are we overusing variable_get and variable_set? Is clearing the variable cache too costly?

/**
 * Menu callback for module settings form.
 *//*
function taxonomy_filter_admin_list() {
  // should menu settings get processed here instead of the form generator?
  return drupal_get_form('taxonomy_filter_admin_list_form');
}*/

/**
 * Form builder.
 */
function taxonomy_filter_admin_templates_form($form, &$form_state) {
  $templates = _taxonomy_filter_menu_templates(FALSE);
  $vars = array();
  $description = 'Menu templates provide for different ways of:<ol><li>selecting the taxonomy terms to display.</li><li>displaying the selected taxonomy terms.</li></ol>';
  if (count($templates) < 5) {
    $description .= 'There are five filter menu templates available with this module. To enable other templates, install some of the other modules !here.';
    $vars = array('!here' => l('here', 'admin/modules'));
  }

  $form = array();

  // Menu template summary.
  $form['templates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu templates'),
    '#description' => t($description, $vars),
  );
  $form['templates']['table'] = array(
    '#theme' => 'taxonomy_filter_templates_table',
  );
  foreach ($templates as $key => $template) {
    $form['templates']['table'][$key] = array(
      'name' => array('#value' => $template['name']), // NOTE: In D7, to use drupal_render(), change '#value' to '#markup'
      'desc' => array('#value' => $template['desc']),
      'module' => array('#value' => $template['module name']),
      'status' => array('#value' => ucfirst($template['status']), '#class' => $template['status']),
    );
  }

  return $form;
}

/**
 * Form builder.
 *
 * @todo Display reminder to enable blocks.
 */
function taxonomy_filter_admin_list_form($form, &$form_state) {
  _taxonomy_filter_block_check();

  $templates = _taxonomy_filter_menu_templates(FALSE);
  $template_names = array();
  foreach ($templates as $name => $template) {
    $template_names[$name] = $name;
  }
  $menus = _taxonomy_filter_menu_list(FALSE, FALSE);

  $form = array();

  // Menu summary.
  $form['menus'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menus'),
    '#description' => t('The following filter menus have been defined for use with the indicated vocabularies.'),
  );
  $form['menus']['table'] = array(
    '#theme' => 'taxonomy_filter_menus_table',
  );
  foreach ($menus as $key => $menu) {
    if ($menu['status'] == 'enabled') {
      $edit = l(t('edit'), "admin/config/user-interface/taxonomy_filter/menus/$key/edit");
    }
    else {
      $edit = t('edit');
    }
    $vocabs = (is_array($menu['vocabs'])) ? implode(', ', $menu['vocabs']) : '';
    $form['menus']['table'][$key] = array(
      'name' => array('#value' => check_plain($menu['name'])), // NOTE: In D7, to use drupal_render(), change '#value' to '#markup'
      'template' => array('#value' => $menu['template']),
      'edit' => array('#value' => $edit),
      'delete' => array('#value' => l(t('delete'), "admin/config/user-interface/taxonomy_filter/$key/delete")),
      'vocabs' => array('#value' => $vocabs),
      'status' => array('#value' => ucfirst($menu['status']), '#class' => $menu['status']),
    );
  }

  // Add menu.
  $form['add'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add menu'),
    '#description' => t('Add a filter menu based on a menu template.'),
  );
  $form['add']['new_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#size' => 40,
    '#required' => TRUE,
  );
  $form['add']['new_template'] = array(
    '#type' => 'select',
    '#title' => t('Menu template'),
    '#default_value' => 'base',
    '#options' => $template_names,
    '#required' => TRUE,
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add menu'),
  );

  return $form;
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_list_form_submit($form, &$form_state) {
  $name = $form_state['values']['new_name'];
  $template = $form_state['values']['new_template'];

  $all_templates = _taxonomy_filter_menu_templates(FALSE);
  $module = $all_templates[$template]['module'];
  _taxonomy_filter_menu_create($name, $template, $module);
}

/**
 * Form builder.
 */
function taxonomy_filter_admin_general_form($form, &$form_state) {
  _taxonomy_filter_block_check();

  $settings = variable_get('taxonomy_filter_general', array());
  $settings += array(
    'current_block_title' => TAXONOMY_FILTER_CURRENT_BLOCK_TITLE,
    'refine_block_title' => TAXONOMY_FILTER_REFINE_BLOCK_TITLE,
    'display_current_atop_content' => FALSE,
  );

  $form = array();
  $form['tf_admin'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block titles'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['tf_admin']['current_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Current criteria block title'),
    '#default_value' => $settings['current_block_title'],
    '#description' => t('Title to display for "Taxonomy filter - current criteria" block.'),
  );
  $form['tf_admin']['refine_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Refine criteria block title'),
    '#default_value' => $settings['refine_block_title'],
    '#description' => t('Title to display for "Taxonomy filter - refine criteria" block.'),
  );
  $form['tf_admin']['display_current_atop_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display current criteria block above content'),
    '#default_value' => $settings['display_current_atop_content'],
    '#description' => t('By default, this block will display the links inline as opposed to a list, cloud, etc.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#weight' => 20,
  );

  return $form;
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_general_form_submit($form, &$form_state) {
  $settings = variable_get('taxonomy_filter_general', array());

  $settings['current_block_title'] = $form_state['values']['tf_admin']['current_block_title'];
  $settings['refine_block_title'] = $form_state['values']['tf_admin']['refine_block_title'];
  $settings['display_current_atop_content'] = $form_state['values']['tf_admin']['display_current_atop_content'];

  variable_set('taxonomy_filter_general', $settings);
  drupal_set_message(t('Updated the general settings.'));
}

/**
 * Menu callback for module settings form.
 *//*
function taxonomy_filter_admin_mappings() {
  taxonomy_filter_update_mappings(); // TODO Is this necessary??? It sets default values for all vocabulary mappings.
  return drupal_get_form('taxonomy_filter_admin_mappings_form');
}*/

/**
 * Form builder.
 */
function taxonomy_filter_admin_mappings_form($form, $form_state) {
  _taxonomy_filter_block_check();
  taxonomy_filter_update_mappings(); // TODO Is this necessary??? It sets default values for all vocabulary mappings.

  $names = /* array('None') + */ _taxonomy_filter_menu_list(FALSE, TRUE, TRUE);
  $menus = _taxonomy_filter_menu_list(FALSE, FALSE);
  $mappings = variable_get('taxonomy_filter_mappings', array());
  $vocabs = _taxonomy_filter_get_vocabs();

  $form = array();
  $form['mappings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu mappings'),
    '#description' => t('For each vocabulary, you can specify:' .
      '<ol><li>which menu type is used to render it in the "Taxonomy filter" blocks (refine and current criteria).</li>' .
      '<li>which taxonomy listings this menu should appear on.</li></ol>'),
  );
  $form['mappings']['table'] = array(
    '#theme' => 'taxonomy_filter_mappings_table',
  );
  foreach ($mappings as $row_vid => $row_settings) {
    $form['mappings']['table']['vocab' . $row_vid] = array('#value' => check_plain($row_settings['vocab']));
    $form['mappings']['table']['refine_menu' . $row_vid] = array(
      '#type' => 'select',
      '#default_value' => $row_settings['refine_menu'],
      '#options' => array('None') + $names,
    );
    $form['mappings']['table']['current_menu' . $row_vid] = array(
      '#type' => 'select',
      '#default_value' => $row_settings['current_menu'],
      '#options' => array('Same') + $names,
    );
    $vocab_names = array();
    if (isset($row_settings['mappings'])) {
      foreach ($row_settings['mappings'] as $mapping) {
        $vocab_names[] = $vocabs[$mapping];
      }
    }
    $vocab_names = (is_array($vocab_names)) ? implode(', ', $vocab_names) : '';

    $form['mappings']['table']['vocabs' . $row_vid] = array('#value' => check_plain($vocab_names));
    $edit = l(t('edit'), "admin/config/user-interface/taxonomy_filter/mappings/$row_vid/edit");
    $form['mappings']['table']['edit' . $row_vid] = array('#title' => t('Menu mappings'), '#value' => $edit);
  }
  if (!$mappings) {
    drupal_set_message(t('No vocabularies have been defined to be mapped. Add vocabularies <b><a href="@url">here</a></b> and then return to this page to define mappings.', array('@url' => '/admin/structure/taxonomy/add')), 'warning');
  }
  if (!$menus) {
    drupal_set_message(t('No menus have been defined to be mapped. Add menus <b><a href="@url">here</a></b> and then return to this page to define mappings.', array('@url' => '/admin/config/user-interface/taxonomy_filter')), 'warning');
  }
  if ($mappings && $menus) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
    );
  }
  return $form;
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_mappings_form_submit($form, &$form_state) {
  $mappings = variable_get('taxonomy_filter_mappings', array());
  foreach ($mappings as $vid => &$mapping) {
    $mapping['refine_menu'] = $form_state['values']['refine_menu' . $vid];
    $mapping['current_menu'] = $form_state['values']['current_menu' . $vid];
  }
  variable_set('taxonomy_filter_mappings', $mappings);
  drupal_set_message(t('Updated the criteria menus.'));
}

/**
 * Form builder.
 */
function taxonomy_filter_admin_mappings_edit_form($form, $form_state, $vid) {
  if (!is_numeric($vid)) {
    drupal_not_found();
    exit;
  }
  $vocabs = _taxonomy_filter_get_vocabs();
  if (!array_key_exists($vid, $vocabs)) {
    drupal_not_found();
    exit;
  }

  $mappings = variable_get('taxonomy_filter_mappings', array());

  drupal_set_title(t('Edit mappings for %vocabulary vocabulary', array('%vocabulary' => $mappings[$vid]['vocab'])), PASS_THROUGH);

  $form = array();
  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $vid,
  );
  $multiple = TRUE;
  $description = 'Display the filter menu for this vocabulary on term listings from the selected vocabularies. To clear the mappings for this vocabulary, select "None" and click "Save settings" or click the "Clear settings" button.';
  $form['vocabs'] = array(
    '#type' => 'select',
    '#title' => 'Vocabularies',
    '#default_value' => isset($mappings[$vid]['mappings']) ? $mappings[$vid]['mappings'] : array(),
    '#options' => array(0 => '<None>') + $vocabs,
    '#description' => $description,
    '#multiple' => $multiple,
    '#size' => $multiple ? min(12, count($vocabs) + 1) : 0,
    '#weight' => -15,
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  $form['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear settings'),
  );
  return $form;
}

/**
 * Validation handler.
 */
function taxonomy_filter_admin_mappings_edit_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] == $form_state['values']['save']) {
    if (count($form_state['values']['vocabs']) == 0) {
      form_set_error('vocabs', t('Please select an item in the list before clicking the "Save settings" button.'));
    }
    if (count($form_state['values']['vocabs']) > 1 && in_array(0, $form_state['values']['vocabs'])) {
      form_set_error('vocabs', t('You have selected "None" along with one or more vocabularies.'));
    }
  }
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_mappings_edit_form_submit($form, &$form_state) {
  $vid = $form_state['values']['vid'];

  $mappings = variable_get('taxonomy_filter_mappings', array());
  if ($form_state['values']['op'] == $form_state['values']['clear'] || in_array(0, $form_state['values']['vocabs'])) {
    $mappings[$vid]['mappings'] = array();
  }
  else {
    $mappings[$vid]['mappings'] = array_values($form_state['values']['vocabs']);
  }
  variable_set('taxonomy_filter_mappings', $mappings);

  $form_state['redirect'] = 'admin/config/user-interface/taxonomy_filter/mappings';
  drupal_set_message(t('Updated the vocabulary mappings.'));
}

/**
 * Form builder.
 */
function taxonomy_filter_admin_advanced_form($form, &$form_state) {
  _taxonomy_filter_block_check();

  $form = array();
  $form['urls'] = array(
    '#type' => 'fieldset',
    '#title' => t('URL settings'),
  );
  $form['urls']['intro'] = array(
    '#value' => t('<p>You should only need to change these settings ' .
    'if this module\'s blocks are to integrate with URLs from other taxonomy modules ' .
    '- see the README.txt file for more information. The default values should work well for most sites.</p>'),
  );
  $form['urls']['taxonomy_filter_input'] = array(
    '#type' => 'textarea',
    '#title' => t('URLs to listen on'),
    '#default_value' => variable_get('taxonomy_filter_input', TAXONOMY_FILTER_INPUT),
    '#required' => TRUE,
    '#description' => t('<p>A list of taxonomy listing URL patterns to listen for. ' .
      'You will only need to change this if you have configured non-standard ' .
      'taxonomy listings (e.g. with the Taxonomy Menu or Views modules).</p>'),
    );
  $form['urls']['taxonomy_filter_output'] = array(
    '#type' => 'textfield',
    '#title' => t('URL format to output in links'),
    '#default_value' => variable_get('taxonomy_filter_output', TAXONOMY_FILTER_OUTPUT),
    '#required' => TRUE,
    '#description' => t('<p>Format of the taxonomy listing URLs created by Taxonomy Filter. ' .
      'You will only need to change this if you have configured non-standard ' .
      'taxonomy listings (e.g. with the Taxonomy Menu or Views modules).</p>'),
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
  );
  return $form;
  /*
  // TODO: handle own caching

  $form['caching'] = array('#type' => 'fieldset',
    '#title' => t('block cache settings'),
  );
  $form['caching']['flags'] = array(
    '#type' => 'radios',
    '#title' => t('cache level'),
    '#default_value' => variable_get('taxonomy_filter_cache', 2),
    '#options' => array(
      t('no caching'),
      t('cache per user'),
      t('cache per role'),
      t('global cache'),
    ),
  );
  */
}

/**
 * Submit handler.
 *
 * Break the input filter patterns into component pieces.
 */
function taxonomy_filter_admin_advanced_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] == $form_state['values']['reset']) {
    $filters = TAXONOMY_FILTER_INPUT;
    variable_del('taxonomy_filter_input');
    variable_del('taxonomy_filter_output');
  }
  else {
    $filters = $form_state['values']['taxonomy_filter_input'];
    variable_set('taxonomy_filter_input', $filters);
    variable_set('taxonomy_filter_output', $form_state['values']['taxonomy_filter_output']);
  }
  taxonomy_filter_parse_input_filters($filters);

  drupal_set_message(t('Updated the advanced settings.'));
}

/**
 * Form builder.
 */
function taxonomy_filter_admin_menu_edit_form($form, &$form_state, $menu_id) {
  if (!is_numeric($menu_id)) {
    drupal_not_found();
    exit;
  }
  $menus = variable_get('taxonomy_filter_menus', array());
  if (!array_key_exists($menu_id, $menus)) {
    drupal_not_found();
    exit;
  }
  $module = $menus[$menu_id]['module'];

  $form = array();
  $form['menu_id'] = array(
    '#type' => 'value',
    '#value' => $menu_id,
  );
  // Store this for other modules to test in their form_alter hook.
  $form['module'] = array(
    '#type' => 'value',
    '#value' => $module,
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu name'),
    '#default_value' => $menus[$menu_id]['name'],
  );
  $form['template_name'] = array(
    '#type' => 'item',
    '#title' => t('Menu template'),
    '#value' => $menus[$menu_id]['template'],
  );
  $form['depth'] = array(
    '#type' => 'select',
    '#title' => t('Listing depth'),
    '#multiple' => False,
    '#default_value' => $menus[$menu_id]['depth'],
    '#options' => array(
      t('Not specified (ie use default)'),
      1, 2, 3, 4, 5,
      'all' => t('Show all levels'),
    ),
    '#description' => t('How many levels of child terms to show in listings.'),
  );

  // TODO This seems like it duplicates the form_alter hook. Remove?
  $template_settings = module_invoke($module, 'tf_settings');
  if (is_array($template_settings)) {
    $form += $template_settings;
  }
  // TODO If a 'tf_settings' function exists, it can set a submit hook. Remove this.
  // Also, statement following this if block overrides the if block.
//  if (function_exists($module .'_tf_settings_submit')) { // use module_hook instead?
//    $form['#submit'][] = $module .'_tf_settings_submit';
//  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#weight' => 20,
  );
  return $form;
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_menu_edit_form_submit($form, &$form_state) {
  $menus = variable_get('taxonomy_filter_menus', array());
  $menu_id = $form_state['values']['menu_id'];

  $menus[$menu_id]['name'] = $form_state['values']['name'];
  $menus[$menu_id]['depth'] = $form_state['values']['depth'];

  variable_set('taxonomy_filter_menus', $menus);
  $form_state['redirect'] = 'admin/config/user-interface/taxonomy_filter';
  drupal_set_message(t('Updated menu %name.', array('%name' => $form_state['values']['name'])));
}

/**
 * Form builder.
 */
function taxonomy_filter_admin_menu_delete_confirm($form, &$form_state, $id) {
  if (!is_numeric($id)) {
    return drupal_access_denied();
  }
  $menus = variable_get('taxonomy_filter_menus', array());
  $name = $menus[$id]['name'];
  $form['menu_id'] = array('#type' => 'value', '#value' => $id);
  $form['menu_name'] = array('#type' => 'value', '#value' => $name);
  $message = t('Are you sure you want to delete the taxonomy filter menu %name?', array('%name' => $name));
  $caption = '<p>' . t('This action cannot be undone.') . '</p>';
  return confirm_form($form, $message, 'admin/config/user-interface/taxonomy_filter', $caption, t('Delete'));
}

/**
 * Submit handler.
 */
function taxonomy_filter_admin_menu_delete_confirm_submit($form, &$form_state) {
  // Reset mappings to 'None' for the filter menu.
  $mappings = variable_get('taxonomy_filter_mappings', array());
  $mid = $form_state['values']['menu_id'];
  foreach ($mappings as $vid => &$mapping) {
    if ($mapping['refine_menu'] == $mid) {
      $mapping['refine_menu'] = '0';
    }
    if ($mapping['current_menu'] == $mid) {
      $mapping['current_menu'] = '0';
    }
  }
  variable_set('taxonomy_filter_mappings', $mappings);

  // Delete the filter menu.
  $menus = variable_get('taxonomy_filter_menus', array());
  unset($menus[$form_state['values']['menu_id']]);
  variable_set('taxonomy_filter_menus', $menus);

  $t_args = array('%name' => $form_state['values']['menu_name']);
  drupal_set_message(t('Deleted menu %name.', $t_args));
  watchdog('taxonomy filter', 'Deleted menu %name.', $t_args, WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/config/user-interface/taxonomy_filter';
}

/**
 * Submit callback for taxonomy_filter_admin_list_form_submit.
 *
 * @param string $name Menu name.
 * @param string $template Menu template to use.
 * @param string $module Name of module implementing menu template.
 */
function _taxonomy_filter_menu_create($name, $template, $module) {
  // Create menu.
  $menu = array(
    'name' => $name,
    'template' => $template,
    'module' => $module,
    'depth' => '0',
  );

  // Add default values for enabled submodules.
  $modules = module_implements('tf_default_settings');
  foreach ($modules as $module) {
    $menu[$module] = module_invoke($module, 'tf_default_settings');
  }

  // Save variable.
  $menus = variable_get('taxonomy_filter_menus', array()); // TODO: change to get_menu??
  // Set first index to one, o/w add one to last index.
  $keys = array_keys($menus);
  $key = ($keys) ? $keys[count($keys) - 1] + 1 : 1;
  $menus[$key] = $menu;
  variable_set('taxonomy_filter_menus', $menus);
  drupal_set_message(t('Added menu %name.', array('%name' => $name)));
}

/**
 * Returns list of menu templates.
 *
 * @todo Remove the parameter?
 * @param boolean $names_only
 * @return array List of menu templates.
 */
function _taxonomy_filter_menu_templates($names_only = TRUE) {
  static $templates;

  if (is_null($templates)) {
    // Get complete information the first time so we can handle all requests.
    $modules = module_implements('tf_template_info');
    $templates = array();
    foreach ($modules as $module) {
      $tfinfo = module_invoke($module, 'tf_template_info');
      $info_file = drupal_parse_info_file(drupal_get_path('module', $module) . '/' . $module . '.info');
      $name = ($tfinfo['name']) ? $tfinfo['name'] : $info_file['name'];
      $status = _taxonomy_filter_module_status($module);
      $templates[$name] = array(
        'name' => $name,
        'desc' => ($tfinfo['desc']) ? $tfinfo['desc'] : $info_file['description'],
        'module' => $module,
        'module name' => $info_file['name'],
        'status' => $status,
      );
    }
  }

  if ($names_only) {
    $names = array();
    foreach ($templates as $name => $template) {
      $names[$name] = $name;
    }
    return $names;
  }
  return $templates;
}

/**
 * Returns list of menus.
 *
 * @param boolean $enabled_only
 * @param boolean $names_only
 * @param boolean $warning_in_name
 * @return array List of menus.
 */
function _taxonomy_filter_menu_list($enabled_only = TRUE, $names_only = TRUE, $warning_in_name = FALSE) {
  $templates = _taxonomy_filter_menu_templates();
  $menus = variable_get('taxonomy_filter_menus', array());
  $menu_vocabs = _taxonomy_filter_menu_vocabs();

  $results = array();
  foreach ($menus as $id => $menu) {
    // TODO: Check this expression for accuracy and possible simplifications.
    // It should leave out disabled templates only if required.
    if (!($enabled_only && !in_array($menu['template'], $templates))) {
      $status = _taxonomy_filter_module_status($menu['module']);
      if ($names_only) {
        if ($warning_in_name && $status != 'enabled') {
          $results[$id] = $menu['name'] . ' (' . $status . ')';
        }
        else {
          $results[$id] = $menu['name'];
        }
      }
      else {
        $results[$id] = array(
          'name' => $menu['name'],
          'template' => $menu['template'],
          'module' => $menu['module'],
          'status' => $status,
          'vocabs' => isset($menu_vocabs[$id]) ? $menu_vocabs[$id] : '',
        );
      }
    }
  }
  return $results;
}

/**
 * Returns list of vocabulary mappings keyed by menu template.
 *
 * @param integer $menu_id
 * @return array List of vocabulary mappings keyed by menu template.
 */
function _taxonomy_filter_menu_vocabs($menu_id = NULL) {
  static $menu_vocabs = array();
  if (!$menu_vocabs) {
    $mappings = variable_get('taxonomy_filter_mappings', array());
    $vocabs = _taxonomy_filter_get_vocabs();
    foreach ($mappings as $vid => $mapping) {
      if ($mapping['refine_menu']) {
        $menu_vocabs[$mapping['refine_menu']][] = $vocabs[$vid];
      }
    }
  }
  if ($menu_id) {
    return $menu_vocabs[$menu_id];
  }
  else {
    return $menu_vocabs;
  }
}

/**
 * Returns module status.
 *
 * @param string $module Module name.
 * @return string Status.
 */
function _taxonomy_filter_module_status($module) {
  // either 'enabled', 'disabled', or 'missing'
  if (module_exists($module)) {
    return 'enabled'; // t('enabled');
  }
  if (drupal_get_filename('module', $module)) {
    return 'disabled'; // t('disabled');
  }
  else {
    return 'missing'; // t('missing');
  }
}

/**
 * Returns TRUE if any of the filter blocks is assigned to a region.
 *
 * @return boolean
 *   TRUE if any of the filter blocks is assigned to a region.
 */
function _taxonomy_filter_block_check() {
  $found = FALSE;
  $regions = _block_load_blocks();
  foreach ($regions as $region => $blocks) {
    foreach ($blocks as $key => $block) {
      if (substr($key, 0, 15) == 'taxonomy_filter') {
        $found = TRUE;
        break 2;
      }
    }
  }
  if (!$found) {
    drupal_set_message(t('None of the filter menu blocks has been assigned to a region. Assign a block to a region !here.', array('!here' => l('here', 'admin/structure/block'))), 'warning');
  }
  return $found;
}
