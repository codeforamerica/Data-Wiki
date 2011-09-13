<?php

/**
 * @file
 * 
 */

/**
 * Category edit page.
 */
function citygroups_edit_form($form, &$form_state, array $rule = array()) {
   $form['introduction'] = array(
    '#markup' => '
    <p>Set up CityGroups (in progress, not yet fully functional)</p>
    <p><a href="">Documentation</a></p>
    <p><a href="">Support</a></p>
    <p><a href="">Contact</a></p>

    <h3>Configure API Keys</h3>
    <ul>
      <li><a href="/admin/config/system/googleanalytics">Google Analytics</a></li>
      <li><a href="/admin/build/openlayers/layers/settings">Set Map API Keys (Google & Cloudmade.)</a></li>
      <li><a href="/admin/config/content/mollom/settings">Mollom, spam protection</a></li>
      <li><a href="/admin/build/openlayers/presets/citygroups_group_display/edit">Set Map Center in Map for Forms</a></li>
      <li><a href="/admin/build/openlayers/presets/citygroups_form/edit">Set Map Center in Map for Display</a></li> (or change in code...)
    </ul>
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

/*
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
*/

  return system_settings_form($form);
}
