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
    '#default_value' =>  variable_get('city_name', array()),
    '#description' => 'Enter the name of the city.',
  );

  $form['city_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('City Slogan'),
    '#default_value' =>  variable_get('city_slogan', array()),
    '#description' => 'slogan',
  );

  $form['home_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Homepage Markup'),
    '#default_value' =>  variable_get('home_content', array()),
    '#description' => 'HTML',
  );

  $form['about_content'] = array(
    '#type' => 'textarea',
    '#title' => t('About Markup'),
    '#default_value' =>  variable_get('about_content', array()),
    '#description' => 'HTML',
  );

  $form['google_analytics'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics'),
    '#description' => 'Google Analytics (link)',
    '#default_value' =>  variable_get('google_analytics', array()),
  );

  $form['citygroups_google_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google API Key'),
    '#description' => 'get API key (link)',
    '#default_value' =>  variable_get('citygroups_google_api_key', array()),
  );
  
  $form['citygroups_cloudmade_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Cloudmade API Key'),
    '#description' => 'get API key (link)',
    '#default_value' =>  variable_get('citygroups_cloudmade_api_key', array()),
  );

  return system_settings_form($form);
}
