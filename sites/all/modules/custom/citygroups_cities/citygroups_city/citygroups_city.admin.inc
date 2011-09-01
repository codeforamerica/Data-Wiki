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
    '#markup' => '
    <p>Set up CityGroups (in progress, not yet fully functional)</p>
    <p><a href="">Documentation</a></p>
    <p><a href="">Support</a></p>
    <p><a href="">Contact</a></p>
    ',
  );

  $form['city_name'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#description' => 'Enter the name of the city.',
  );

  $form['city_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('City Slogan'),
    '#default_value' => 'Sharing community groups in CityName.',
    '#description' => 'slogan',
  );

  $form['home_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Homepage Markup'),
    '#default_value' => 'Homepage markup',
    '#description' => 'HTML',
  );

  $form['about_content'] = array(
    '#type' => 'textarea',
    '#title' => t('About Markup'),
    '#default_value' => 'About markup',
    '#description' => 'HTML',
  );

  $form['google_API_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google API Key'),
    '#description' => 'get API key (link)',
  );

  $form['cloudmade_API_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Cloudmade API Key'),
    '#description' => 'get Cloudmade API key (link)',
  );

  $form['google_analytics'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics'),
    '#description' => 'Google Analytics (link)',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}
