<?php

/**
 * @file
 * 
 */

/**
 * Category edit page.
 */
function sfo_food_configure_edit_form($form, &$form_state, array $rule = array()) {
   $form['introduction'] = array(
    '#markup' => '
    <h3>Configure Bay Area food </h3>
    <p><strong>Configure the Bay Area food pages.</strong></p>
    <a name="site-content"></a>    
    <h3>Site Content</h3>
    <p>Enter custom text that should appear throughout the site & on the homepage.</p>
    ',
  );

  $form['sfo_food_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of Project'),
    '#default_value' =>  variable_get('sfo_food_name', 'Bay Area Food System Groups Directory'),
    '#description' => 'Name of project.',
  );
  
  $form['sfo_food_slogan'] = array(
    '#type' => 'textarea',
    '#title' => t('Slogan'),
    '#default_value' =>  variable_get('sfo_food_slogan', 'Find the nearest Food System Group.'),
    '#description' => 'Slogan.',
  ); 

  $form['sfo_food_content_tagline'] = array(
    '#type' => 'textarea',
    '#title' => t('Tagline'),
    '#default_value' =>  variable_get('sfo_food_content_tagline', '
<p>The Bay Area Food System Groups Directory lists basic contact information for Food System Groups in Bay Area.</p>'),
    '#description' => 'Customize site tagline',
  );

  $form['sfo_food_content_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('View Groups (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_groups', '
<h3>' . t('View Food System Groups') .'</h3>
<p>Find a Food System Group on the map.</p>'
    ),
    '#description' => 'Prompt to check out groups in the directory',
  );

  $form['sfo_food_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_add_new_group', '
<h3>' . t('Are you a Food System Group?') . '</h3>
<p>Help your neighbors and other Food System Groups find you. <a href="/node/add/community-group">Add</a> your contact information and map a food community.</p>
<div class="button"><a href="/node/add/community-group">Add New</a></div>
    '),
    '#description' => 'Prompt to add new groups.',
  );

  $form['sfo_food_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_news', 
    '<h3>' . t('Mapping in West Bay Area.') . '</h3>
    <p>We will change this text this weekend at the hackathon</p>
    <p>This fall we are reaching out to Food System Groups in the Bay Area.</p>
'),
    '#description' => 'News about this project',
  );

  $form['sfo_food_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_promote', '
<h3>Spread the word</h3>
<p>Tell your friends, neighbors & local community groups.</p>
<p>We’ve written emails, made <a href="food/get-involved">printable flyers</a> to make it easy to explain to others.</p>'),
    '#description' => 'Links to promotional content',
  );
  

  $form['sfo_food_social_media_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#default_value' =>  variable_get('sfo_food_social_media_twitter', 'AllCityGroups'),
    '#description' => 'What is the account name? (Ex. BostonCityGroups)',
  );
  
  $form['sfo_food_social_media_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' =>  variable_get('sfo_food_social_media_facebook', array()),
    '#description' => 'Link to Facebook page',
  );

  $form['sfo_food_mailing_list'] = array(
    '#type' => 'textfield',
    '#title' => t('Mailing List'),
    '#default_value' =>  variable_get('sfo_food_mailing_list', 'http://citygroups.us2.list-manage1.com/subscribe?u=eb1facd19686e6ad279923882&id=ea0d4c3774'),
    '#description' => 'Link to mailing list.',
  );

  $form['sfo_food_social_media_flyer'] = array(
    '#type' => 'textfield',
    '#title' => t('Flyer'),
    '#default_value' =>  variable_get('sfo_food_social_media_flyer', array()),
    '#description' => 'Path to printable flyer',
  );

  $form['sfo_food_content_about'] = array(
    '#type' => 'textarea',
    '#title' => t('About'),
    '#default_value' =>  variable_get('sfo_food_content_about', '
<h3>What is a Food System Group?</h3>
<pGroups that are working to improve access to local food & to improve the food system in general.</p>
    '),
    '#description' => 'About content',
  );

  $form['sfo_food_content_about_participate'] = array(
    '#type' => 'textarea',
    '#title' => t('Participate'),
    '#default_value' =>  variable_get('sfo_food_content_about_participate', '
<h3>Get on the map</h3>
<p>Add your group!</p>
    '),
    '#description' => 'Participate',
  );

  $form['sfo_food_content_about_local'] = array(
    '#type' => 'textarea',
    '#title' => t('Local'),
    '#default_value' =>  variable_get('sfo_food_content_about_local', '
<h3>Food Group Resources</h3>
<p>These are some of the main groups that coordinate food at a regional and city level.</p>
<p><a href="/food/resources">See list of resources</a></p>
<br />
<h3>More Local community groups</h3>
<p>CityGroups lists other kinds of community groups working to make your neighborhood better in Bay Area. Find other community leaders near you.</p>
<p><a href="/food/categories">See related groups</a></p>
'),
    '#description' => 'Local',
  );

  $form['sfo_food_resources'] = array(
    '#type' => 'textarea',
    '#title' => t('Resources'),
    '#default_value' =>  variable_get('sfo_food_resources', '
'),
    '#description' => 'Links and resources',
  );

  $form['sfo_food_related_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('Related Groups'),
    '#default_value' =>  variable_get('sfo_food_related_groups', '
<div class="related-categories">
</div>
'),
    '#description' => 'Links to related groups',
  );

  $form['sfo_food_related_terms'] = array(
    '#type' => 'textarea',
    '#title' => t('Related Terms'),
    '#default_value' =>  variable_get('sfo_food_related_terms', 'Food, Urban Agriculture, Food System'),
    '#description' => 'Links to related groups',
  );


  $form['sfo_food_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Term'),
    '#default_value' =>  variable_get('sfo_food_term', 'Food'),
    '#description' => 'Term to filter content',
  );

  $form['sfo_food_flyer'] = array(
    '#type' => 'textarea',
    '#title' => t('Flyer Text'),
    '#default_value' =>  variable_get('sfo_food_flyer', '
<h3>Help Map Food Groups in Bay Area</h3>
<p>Know a Food System Group in Bay Area?</p>
<a href="http://bayarea.citygroups.org/food">http://bayarea.citygroups.org/food</a>
<p>Contact: Name Lastname, phone.</p>
    '),
    '#description' => 'Text to be used in flyers',
  );

  $form['sfo_food_email'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Text'),
    '#default_value' =>  variable_get('sfo_food_email', '
Know a Food System Group? Ask them to get listed in the Bay Area Food System Groups Directory. <a href="http://bayarea.citygroups.org/food">http://bayarea.citygroups.org/food</a>
    '),
    '#description' => 'Text to be used in emails',
  );

  $form['sfo_food_tweet'] = array(
    '#type' => 'textarea',
    '#title' => t('Tweet Text'),
    '#default_value' =>  variable_get('sfo_food_tweet', '
Know a Food System Group? Ask them to get listed in the Bay Area Food System Groups Directory. http://bayarea.citygroups.org/food
    '),
    '#description' => 'Text to be used in tweets',
  );

  $form['sfo_food_facebook'] = array(
    '#type' => 'textarea',
    '#title' => t('Facebook Text'),
    '#default_value' =>  variable_get('sfo_food_facebook', '
Share the Bay Area Food System Groups Directory on Facebook.
    '),
    '#description' => 'Text to be used in facebook share links',
  );

  $form['sfo_food_qrcode'] = array(
    '#type' => 'textarea',
    '#title' => t('QR Code path'),
    '#default_value' =>  variable_get('sfo_food_qrcode', '
Bay Area Bay Area Food System Groups Directory
The Bay Area Food System Groups Directory lists basic contact information for Food System Groups in Bay Area.

http://bayarea.citygroups.org/food
'),
    '#description' => 'QR Code message: Message URL',
  );

  return system_settings_form($form);
}
