<?php

/**
 * Settings page form
 *
 * This function provides the module settings page form which is used for enabling content type blocks.
 */
function relevant_content_admin() {
  $settings = variable_get('relevant_content', array());

  $content_types = node_type_get_names();
  $vocabularies = taxonomy_get_vocabularies();

  $variables = array(
    'header' => array(t('Block ID'), t('Enabled Types'), t('Enabled Vocabularies'), t('Max Results'), t('Actions')),
    'rows' => array(),
  );
  if (empty($settings)) {
    $variables['rows'][] = array(array('colspan' => 5, 'data' => t('There are no configured blocks yet - add one using the form below.')));
  }
  else {
    foreach ($settings as $delta => $info) {
      array_walk($info['types'],  '_relevant_content_array_map_key_to_values', $content_types);
      array_walk($info['vocabs'], '_relevant_content_array_map_key_to_values', $vocabularies);

      $ops = array(
        l(t('Edit'), 'admin/config/relevant_content/blocks/'. $delta),
        l(t('Delete'), 'admin/config/relevant_content/blocks/'. $delta .'/delete'),
      );

      $variables['rows'][] = array(
        check_plain($delta),
        theme('item_list', array('items' => $info['types'])),
        theme('item_list', array('items' => $info['vocabs'])),
        check_plain($info['limit']),
        theme('item_list', array('items' => $ops)),
      );
    }
  }

  // Render the output into an array and return.
  $output['blocks'] = array('#type' => 'markup', '#markup' => theme('table', $variables));
  $output['new_block'] = drupal_get_form('relevant_content_admin_block_form');

  return $output;
}


/**
 * Form API based function which generates the add AND edit forms. The form is an 'edit' form if a delta is passed in for editing.
 *
 * @param $delta
 *   mixed - The 'delta' (or ID) of the block being editted. Will effectively be the array key in the $settings array.
 */
function relevant_content_admin_block_form($form, &$form_state, $delta = NULL) {
  $settings = variable_get('relevant_content', array());
  $form = array();

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => isset($delta) ? t('Edit Block') : t('Add Block'),
    '#tree' => TRUE,
    '#collapsible' => !isset($delta),
    '#collapsed' => !isset($delta),
  );

  if (!isset($delta)) {
    $form['settings']['delta'] = array(
      '#type' => 'textfield',
      '#title' => t('Block <em>Delta</em>'),
      '#description' => t('The <em>Delta</em> is used to uniquely identify a block. Please user uppercase & lowercase characters, numbers and underscores only'),
      '#required' => TRUE,
      '#maxlength' => 12,
      '#size' => 12,
    );
  }
  else {
    $form['settings']['delta'] = array(
      '#type' => 'value',
      '#value' => $delta,
    );
    $form['settings']['delta_field'] = array(
      '#type' => 'item',
      '#title' => t('Block <em>Delta</em>'),
      '#description' => t('The <em>Delta</em> is used to uniquely identify a block'),
      '#markup' => check_plain($delta),
    );
  }

  $form['settings']['types'] = array(
    '#type' => 'checkboxes',
    '#title' =>  t('Enabled Content Types'),
    '#description' => t('Check the content types you would like to search for.'),
    '#options' => node_type_get_names(),
    '#default_value' => isset($delta) ? $settings[$delta]['types'] : array(),
  );


  $vocabs = array();
  foreach (taxonomy_get_vocabularies() as $vid => $voc) {
    $vocabs[$vid] = $voc->name;
  }

  $form['settings']['vocabs'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled Vocabularies'),
    '#description' => t('Check the vocabularies you would like to search for'),
    '#options' => $vocabs,
    '#default_value' => isset($delta) ? $settings[$delta]['vocabs'] : array(),
  );

  $form['settings']['limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Limit'),
    '#description' => t('What is the maximum number of results would you like returned?'),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
    '#default_value' => isset($delta) ? $settings[$delta]['limit'] : 5,
  );

  $form['settings']['header_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Header Text'),
    '#description' => t('Optionally provide some text to appear above the listing'),
    '#rows' => 3,
    '#default_value' => isset($delta) ? $settings[$delta]['header_text'] : '',
  );

  $form['settings']['token_settings'] = array(
    '#type' => 'textfield',
    '#title' => t('Token pattern'),
    '#description' => t('Optionally define a token pattern here to override the default output. Please use plain text only. Leave blank to use hyper links to nodes.'),
    '#default_value' => isset($delta) ? $settings[$delta]['token_settings'] : '',
  );

  $form['settings']['token_help'] = array(
    '#type' => 'fieldset',
    '#title' => t('Token Help'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['settings']['token_help']['body'] = array(
    '#type' => 'markup',
    '#markup' => theme('relevant_content_token_help'),
  );

  $form['settings']['op'] = array(
    '#type' => 'value',
    '#value' => isset($delta) ? 'edit' : 'add',
  );
  $form['settings']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings'),
  );

  return $form;
}


/**
 * Validate function for the above form
 */
function relevant_content_admin_block_form_validate($form, &$form_state) {
  if ($form_state['values']['settings']['op'] == 'add') {
    if (preg_match('#[^a-zA-Z0-9_]#', $form_state['values']['settings']['delta'])) {
      form_set_error('settings][delta', t('Invalid character detected. Please only use uppercase and lowercase characters, numbers and underscores'));
      return;
    }

    $settings = variable_get('relevant_content', array());
    if (isset($settings[$form_state['values']['settings']['delta']])) {
      form_set_error('settings][delta', t('This <em>Delta</em> has already been used, please try another'));
    }
  }

  if (!is_numeric($form_state['values']['settings']['limit']) || $form_state['values']['settings']['limit'] <= 0) {
    form_set_error('settings][limit', t('The limit must be a positive numeric value, eg 5.'));
  }

  $a = array_filter($form_state['values']['settings']['types']);
  if (empty($a)) {
    form_set_error('settings][types', t('You must select at least one content type to display.'));
  }

  $a = array_filter($form_state['values']['settings']['vocabs']);
  if (empty($a)) {
    form_set_error('settings][vocabs', t('You must select at least one vocabulary to limit your term searching to.'));
  }
}


/**
 *  Submit handler for the block add/edit form.
 */
function relevant_content_admin_block_form_submit($form, &$form_state) {
  $settings = variable_get('relevant_content', array());

  $settings[$form_state['values']['settings']['delta']] = array(
    'types'          => array_filter($form_state['values']['settings']['types']),
    'vocabs'         => array_filter($form_state['values']['settings']['vocabs']),
    'limit'          => (int)$form_state['values']['settings']['limit'],
    'header_text'    => $form_state['values']['settings']['header_text'],
    'token_settings' => $form_state['values']['settings']['token_settings'],
  );

  variable_set('relevant_content', $settings);
  $form_state['redirect'] = 'admin/config/relevant_content/blocks';
}


/**
 * Menu callback for deleting a variable. Does some basic validation first before calling the Form API.
 */
function relevant_content_admin_delete($delta) {
  $settings = variable_get('relevant_content', array());

  return drupal_get_form('relevant_content_admin_delete_confirm', $delta);
}


/**
 * Form API based function for geneating the confirmation page for deleting a block from the settings.
 */
function relevant_content_admin_delete_confirm($form, &$form_state, $delta) {
  $form = array();

  $form['delta'] = array(
    '#type' => 'hidden',
    '#value' => $delta
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete block "%delta"?', array('%delta' => $delta)),
    'admin/config/relevant_content/blocks',
    t('Note: This action cannt be undone')
  );
}


/**
 *  Delete confirmation form submission handler. Usets the block settings from the settings array based on the hidden delta field passed in from the previous funciton.
 */
function relevant_content_admin_delete_confirm_submit($form, &$form_state) {
  $settings = variable_get('relevant_content', array());

  // Remove the settings from the array and save
  unset($settings[$form_state['values']['delta']]);
  variable_set('relevant_content', $settings);

  // Tidy up the blocks table...
  foreach (array('block', 'block_node_type', 'block_role') as $table) {
    db_delete($table)
      ->condition('module', 'relevant_content')
      ->condition('delta', $form_state['values']['delta'])
      ->execute();
  }

  $form_state['redirect'] = 'admin/config/relevant_content/blocks';
}



