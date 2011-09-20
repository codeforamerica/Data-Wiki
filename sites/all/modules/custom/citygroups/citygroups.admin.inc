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
    <h3>Configure & Manage CityGroups</h3>
    <p><strong>Let\'s set up CityGroups for your City.</strong></p>
    <p>There are a few accounts, settings and data that you will need to do to customize the tool for your city.</p>
    
    <div class="admin clearfix">
      <h4>Initial Setup</h4>
      <ul class="menu-list">
        <li><a href="#help">Get Help</a></li>
        <li><a href="#configure">Configure</a></li>
        <li><a href="#site-content">Site Content</a></li>
      </ul>

      <h4>Ongoing Maintenance & Moderation</h4>      
      <ul class="menu-list">
        <li><a href="#content">Content</a></li>
        <li><a href="#flags">Flags</a></li>        
        <li><a href="#data">Data</a></li>
        <li><a href="#outreach">Outreach</a></li>
        <li><a href="#servers">Servers</a></li>
        <li><a href="#moderation">Moderation</a></li>
      </ul>
    </div>
    
    <fieldset class="configure">
      <legend>Get Help</legend>
        <a name="help"></a>
        <h4>Get Help</h4>
        <ul>
          <li><a href="http://citygroups.org/documentation">Documentation</a></li>
          <li><a href="http://citygroups.org/support">Support</a></li>
          <li><a href="http://citygroups.org/contact">Contact</a></li>
          <li><a href="http://tasks.citygroups.org">CityGroups Project Blog</a></li>
        </ul>
    </fieldset>

    <fieldset class="configure">
      <legend>Configure</legend>    
        <a name="configure"></a>
        <h4>Configure</h4>
        <ol>
          <li><a href="/admin/config/system/googleanalytics">Google Analytics</a></li>
          <li><a href="/admin/config/content/mollom/settings">Mollom, spam protection</a></li>
          <li><a href="/admin/config/content/mollom">Configure Mollom (spam control)</a></li>
          <li><a href="/admin/build/openlayers/layers/settings">Set Map API Keys (Google & Cloudmade.)</a></li>
          <li><a href="/admin/build/openlayers/presets/citygroups_group_display/edit">Set Map Center in Map for Forms</a></li>
          <li><a href="/admin/build/openlayers/presets/citygroups_form/edit">Set Map Center in Map for Display</a></li>
          <li><a href="/admin/citygroups_stats">Re-count groups</a></li>
          <li><a href="/admin/config/citygroups_vocabularies">Load & Update Vocabularies</a></li>
          <li>RPX</li>
          <li>Typekit</li>
          <li>Mailchimp</li>
        </ol>
    </fieldset>

    <fieldset class="configure">
      <legend>Content</legend>    
        <a name="content"></a>    
        <h4>Content</h4>
        <ul>
          <li><a href="/admin/content/node">Content</a> View all content</li>
    
          <li><a href="/admin/content/node">Content</a> View all content</li>
          <li><a href="/admin/config/taxonomy_cleanup">Taxonomy Cleanup</a> Cleanup, merge & split taxonomies.</li>
          <li><a href="/admin/config/citygroups_vocabularies">Update Taxonomoy Vocabularies</a> This will add new terms to vocabularies.</li>
        </ul>
    </fieldset>

    <fieldset class="configure">
      <legend>Flags</legend>  
        <a name="flags"></a>    
        <h4>Flagged Content</h4>
        <p>Users who are signed in have the ability to set a number of "flags" on any community group content.</p>
        <ul>
          <li><a href="/manage/recommended">Duplicates</a> View duplicates.</li>
          <li><a href="/manage/dashboard/favorites">Duplicates</a> View groups people are watching.</li>
          <li><a href="/manage/duplicates">Duplicates</a> View duplicates.</li>
          <li><a href="/manage/inactive">Duplicates</a> View groups people consider to be inactive.</li>
          <li><a href="/manage/inappropriate">Duplicates</a> View groups flagged as inappropriate.</li>
        </ul>
    </fieldset>
    
    <fieldset class="configure">
      <legend>Data</legend>  
        <a name="data"></a>    
        <h4>Data</h4>
        <ul>
          <li><a href="http://citygroups.org/documentation/get-data/groups">Get groups data</a></li>
          <li><a href="http://citygroups.org/documentation/get-data/neighborhood">Get neighborhood data</a></li>
          <li><a href="http://citygroups.org/documentation/get-data/categories">Get category data</a></li>
          <li><a href="/datasets</a> Contributed datasets</li>
          <li><a href="/projects</a> Data collection Projects</li>
          <li><a href="/node/add/community-group-feed-upload-csv</a> Contribute dataset with CSV File</li>
          <li><a href="/data-standard/community-groups</a> Data Standard</li>
          <li><a href="/projects</a> Data collection Projects</li>
          <li><a href="/projects/add"</a> How to add a data collection project</li>
        </ul>
    </fieldset>

    <fieldset class="configure">
      <legend>Outreach</legend>          
        <a name="outreach"></a>  
        <h4>Outreach</h4>
        <ul>
          <li><a href="http://citygroups.org/documentation/community-mapping-project">Start a Community Mapping Project</a></li>
        </ul>
    </fieldset>
 
     <fieldset class="configure">
      <legend>Servers</legend>        
        <a name="servers"></a>  
        <h4>Servers</h4>
        <ul>
          <li><a href="http://citygroups.org/documentation/servers">Servers</a></li>
          <li><a href="http://citygroups.org/documentation/server-administration">Server Administration</a></li>
          <li><a href="/admin/config/system/backup_migrate/export">Backup Database</a></li>
          <li>Robots (staging servers)</li>
          <li>Updates to code</li>
          <li>Maintenance</li>
        </ul>
     </fieldset>

 
     <fieldset class="configure">
      <legend>Moderation</legend>     
        <a name="moderation"></a>  
        <h4>Content Moderation</h4>
        <p>All public facing sites that allow users to join are subject to the pressures 
        of robots and people who try to get accounts, or add comments that try to sell things.
        Here are some links to tools that will allow you to delete bad content.</p>
        <p>In general, it is good to check on the comments & users at least every month or two to make sure the site is OK.</p>
        <p>When a site is attacked, a robot can fill up the database with bad content, which has the potential to crash the server.</p>
        <ul>
          <li><a href="/admin/content/comment/approval">Comment Approval Queue</a> Approve comments. (Configuring Mollom will cut down on any spam from forms.)</li>
          <li><a href="/admin/people/people">Users</a> This is where you can cancel accounts for any robots that might try to join the site.</li>
        </ul>
     </fieldset>
 
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
<h3>' . t('Search for Groups') .'</h3>'
    ),
    '#description' => 'Prompt to check out groups in the directory',
  );

  $form['citygroups_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_add_new_group', '
<h3>' . t('Know community groups that should be listed?') . '</h3>
<p>Anyone can suggest a group. Groups should be based in ' . variable_get('citygroups_city_name', 'our city') . ', and do work to make ' . variable_get('citygroups_city_name', 'our city') . ' better.</p>
<div class="button"><a href="/node/add/community-group">Add New Group</a></div>
    '),
    '#description' => 'Prompt to add new groups.',
  );

  $form['citygroups_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_news', 
    '<h3>' . t('Spread the word') . '</h3>
' .
t('CityGroups launches in our city!')),
    '#description' => 'News about CityGroups',
  );

  $form['citygroups_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('citygroups_content_promote', '
<h3>Spread the word</h3>
<p>If you like this directory and know other people who should <a href="/get-involved">get involved</a>, we want to help you do that.</p>'),
    '#description' => 'Links to promotional content',
  );
  

  $form['citygroups_social_media_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#default_value' =>  variable_get('citygroups_social_media_twitter', 'AllCityGroups'),
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
    '#default_value' =>  variable_get('citygroups_mailing_list', 'http://citygroups.us2.list-manage1.com/subscribe?u=eb1facd19686e6ad279923882&id=ea0d4c3774'),
    '#description' => 'Link to mailing list.',
  );

  $form['citygroups_social_media_flyer'] = array(
    '#type' => 'textfield',
    '#title' => t('Flyer'),
    '#default_value' =>  variable_get('citygroups_social_media_flyer', array()),
    '#description' => 'Path to printable flyer',
  );

  $form['citygroups_default_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' =>  variable_get('citygroups_default_city', array()),
    '#description' => 'Set Default City for Taxonomy',
  );

  $form['citygroups_default_state'] = array(
    '#type' => 'textfield',
    '#title' => t('State'),
    '#default_value' =>  variable_get('citygroups_default_state', array()),
    '#description' => 'Set Default State for Taxonomy',
  );

  $form['citygroups_default_county'] = array(
    '#type' => 'textfield',
    '#title' => t('County'),
    '#default_value' =>  variable_get('citygroups_default_county', array()),
    '#description' => 'Set Default County for Taxonomy',
  );

  $form['citygroups_default_location_latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#default_value' =>  variable_get('citygroups_default_location_latitude', array()),
    '#description' => 'Set Default Latitude',
  );

  $form['citygroups_default_location_longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#default_value' =>  variable_get('citygroups_default_location_longitude', array()),
    '#description' => 'Set Default Longitude',
  );

  return system_settings_form($form);
}
