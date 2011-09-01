<?php

/**
 * @file
 * 
 */

/**
 * Category edit page.
 */
function citygroups_city_edit_form($form, &$form_state, array $rule = array()) {
   $form['introduction'] = array(
    '#type' => 'markup',
    '#title' => t('Introduction'),
    '#default_value' => 'blah',
  );

  $form['city_name'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#description' => 'Enter the name of the city.',
  );

  $form['city_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('City Slogan'),
    '#default_vale' => 'Sharing community groups in CityName.',
    '#description' => 'slogan',
  );

  $form['home_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Homepage Markup'),
    '#default_vale' => 'Homepage markup',
    '#description' => 'HTML',
  );

  $form['about_content'] = array(
    '#type' => 'textarea',
    '#title' => t('About Markup'),
    '#default_vale' => 'About markup',
    '#description' => 'HTML',
  );

/*

   $form['city_name'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Redirect users with roles'),
    '#options' => _login_destination_role_options(),
    '#default_value' => $default_role_options,
    '#description' => 'Redirect only the selected role(s). If you select no roles, all users will be redirected.',
  );
*/


  return $form;
}
