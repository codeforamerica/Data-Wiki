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
        <li><a href="#servers">Servers</a></li>
        <li><a href="#site-content">Site Content</a></li>
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

    <a name="servers"></a>  
    <h4>Servers</h4>
    <ul>
      <li><a href="http://citygroups.org/documentation/servers">Servers</a></li>
      <li><a href="http://citygroups.org/documentation/server-administration">Server Administration</a></li>
      <li><a href="/admin/config/system/backup_migrate/export">Backup Database</a></li>
      <li>Updates to code</li>
    </ul>

    <a name="site-content"></a>    
    <h3>Site Content</h3>
    <p>Enter custom text that should appear throughout the site & on the homepage.</p>
    ',
  );

  $form['citygroups_city_name'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' =>  variable_get('citygroups_city_name'),
    '#description' => 'Enter city name',
  );

  $form['citygroups_city_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('City Slogan'),
    '#default_value' =>  variable_get('citygroups_city_slogan', 'A directory of community groups in ' . variable_get('citygroups_city_name', 'our city')),
    '#description' => 'Customize the slogan for CityGroups',
  );

  $form['citygroups_content_tagline'] = array(
    '#type' => 'textarea',
    '#title' => t('Tagline'),
    '#default_value' =>  variable_get('citygroups_content_tagline', '
<h3>' . variable_get('citygroups_city_slogan', 'A directory of community groups in ' . variable_get('citygroups_city_name', 'our city')) . '</h3>
<p>' . t('Making it easier to find local community groups.') .'</p>'),
    '#description' => 'Customize site tagline',
  );

  $form['citygroups_content_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('View Groups (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_groups', '
<h3>' . t('Search for Groups') .'</h3>
<p>' . '0' . ' community groups in ' . variable_get('citygroups_city_name', 'our city') . '.</p>'
    ),
    '#description' => 'HTML',
  );

  $form['citygroups_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_add_new_group', '
<h3>' . t('Know community groups that should be listed?') . '</h3>
<p>Anyone can suggest a group. Groups should be based in ' . variable_get('citygroups_city_name', 'our city') . ', and do work to make ' . variable_get('citygroups_city_name', 'our city') . ' better.</p>
<div class="button"><a href="/node/add/community-group">Add New Group</a></div>
    '),
    '#description' => 'HTML',
  );

  $form['citygroups_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_news', 
    '<h3>' . t('Spread the word') . '</h3>
' .
t('CityGroups launches in our city!')),
    '#description' => 'HTML',
  );

  $form['citygroups_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_promote', '
<h3>Spread the word</h3>
<p>If you like this directory and know other people who should <a href=\"/get-involved\">get involved</a>, we want to help you do that.</p>'),
    '#description' => 'HTML',
  );
  

  $form['citygroups_social_media_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#default_value' =>  variable_get('citygroups_social_media_twitter', array()),
    '#description' => 'What is the account name? (Ex. BostonCityGroups)',
  );
  
  $form['citygroups_social_media_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' =>  variable_get('citygroups_social_media_facebook', array()),
    '#description' => 'Link to Facebook page',
  );

  $form['citygroups_mailing_list'] = array(
    '#type' => 'textfield',
    '#title' => t('Mailing List'),
    '#default_value' =>  variable_get('citygroups_mailing_list', array()),
    '#description' => 'Link to mailing list.',
  );

  $form['citygroups_social_media_flyer'] = array(
    '#type' => 'textfield',
    '#title' => t('Flyer'),
    '#default_value' =>  variable_get('citygroups_social_media_flyer', array()),
    '#description' => 'Path to printable flyer',
  );

  return system_settings_form($form);
}
