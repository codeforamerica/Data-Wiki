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
}
