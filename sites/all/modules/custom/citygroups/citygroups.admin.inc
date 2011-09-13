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
    <h3>Configure CityGroups</h3>
    <p><strong>Let\'s set up CityGroups for your City.</strong></p>
    <p>There are a few accounts, settings and data that you will need to do to customize the tool for your city.</p>
    
    <div class="admin clearfix">
      <ul class="menu">
        <li><a href="#help">Get Help</a></li>
        <li><a href="#configure">Configure</a></li>
        <li><a href="#data">Data</a></li>
        <li><a href="#outreach">Outreach</a></li>
        <li><a href="#content">Content</a></li>
      </ul>
    </div>
    
    <a name="help"></a>
    <h4>Get Help</h4>
    <ul>
      <li><a href="http://citygroups.org/documentation">Documentation</a></li>
      <li><a href="http://citygroups.org/support">Support</a></li>
      <li><a href="http://citygroups.org/contact">Contact</a></li>
      <li><a href="http://tasks.citygroups.org">CityGroups Project Blog</a></li>
    </ul>
    
    <a name="configure"></a>
    <h4>Configure</h4>
    <ol>
      <li><a href="/admin/config/system/googleanalytics">Google Analytics</a></li>
      <li><a href="/admin/config/content/mollom/settings">Mollom, spam protection</a></li>
      <li><a href="/admin/config/content/mollom">Configure Mollom (spam control)</a></li>
      <li><a href="/admin/build/openlayers/layers/settings">Set Map API Keys (Google & Cloudmade.)</a></li>
      <li><a href="/admin/build/openlayers/presets/citygroups_group_display/edit">Set Map Center in Map for Forms</a></li>
      <li><a href="/admin/build/openlayers/presets/citygroups_form/edit">Set Map Center in Map for Display</a></li>
    </ol>

    <a name="data"></a>    
    <h4>Data</h4>
    <ul>
      <li><a href="http://citygroups.org/documentation/get-data">Get data</a></li>
    </ul>

    <a name="outreach"></a>  
    <h4>Outreach</h4>
    <ul>
      <li><a href="http://citygroups.org/documentation/community-mapping-project">Start a Community Mapping Project</a></li>
    </ul>

    <a name="content"></a>    
    <h3>Site Content</h3>
    <p>Enter custom text that should appear throughout the site & on the homepage.</p>
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
    '#default_value' =>  variable_get('city_slogan', array(t('A directory of community groups in our city.'))),
    '#description' => 'slogan',
  );

  $form['welcome_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Welcome'),
    '#default_value' =>  variable_get('welcome_content', array()),
    '#description' => 'HTML',
  );

  $form['home_content_view_data'] = array(
    '#type' => 'textarea',
    '#title' => t('View Groups (homepage content)'),
    '#default_value' =>  variable_get('home_content_view_data', array()),
    '#description' => 'HTML',
  );

  $form['home_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('home_content_add_new_group', array()),
    '#description' => 'HTML',
  );

  $form['home_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('home_content_news', array()),
    '#description' => 'HTML',
  );

  $form['home_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('home_content_promote', array(
    '         
    <h3>Spread the word</h3>
    <p>If you like this directory and know other people who should <a href=\"/get-involved\">get involved</a>, we want to help you do that.</p>
    <ul>
      <li>/Tweet/</li>
      <li>/Facebook/</li>
      <li>/Email/</li>
      <li>/Print/</li>
    </ul>
    '
    
    
    )),
    '#description' => 'HTML',
  );

  $form['home_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('home_content_news', array()),
    '#description' => 'HTML',
  );

  $form['home_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('home_content_promote', array()),
    '#description' => 'HTML',
  );

  return system_settings_form($form);
}
