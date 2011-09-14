<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function citygroups_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = "CityGroups";
  $form['site_information']['site_slogan']['#default_value'] = "A public directory of community groups in your city.";
  
  $form['citygroups_city_name'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' =>  variable_get('citygroups_city_name'),
    '#description' => 'Enter city name',
    '#required' => TRUE,
    '#weight' => -20,
  );
  
  $form['#submit'][] = 'citygroups_profile_submit';
}

function citygroups_profile_submit(&$form, $form_state) {
  variable_set('citygroups_city_name', $form_state['values']['citygroups_city_name']);
}
