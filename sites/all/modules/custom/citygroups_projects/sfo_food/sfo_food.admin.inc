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
    '#default_value' =>  variable_get('sfo_food_name', 'Block Watch Captain Directory'),
    '#description' => 'Name of project.',
  );
  
  $form['sfo_food_slogan'] = array(
    '#type' => 'textarea',
    '#title' => t('Slogan'),
    '#default_value' =>  variable_get('sfo_food_slogan', 'Find the nearest Block Watch Captain.'),
    '#description' => 'Slogan.',
  ); 

  $form['sfo_food_content_tagline'] = array(
    '#type' => 'textarea',
    '#title' => t('Tagline'),
    '#default_value' =>  variable_get('sfo_food_content_tagline', '
<p>The Block Watch Captain Directory lists basic contact information for Block Watch Captains in Bay Area.</p>'),
    '#description' => 'Customize site tagline',
  );

  $form['sfo_food_content_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('View Groups (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_groups', '
<h3>' . t('View Block Watch Captains') .'</h3>
<p>Find a Block Watch Captain on the map.</p>'
    ),
    '#description' => 'Prompt to check out groups in the directory',
  );

  $form['sfo_food_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_add_new_group', '
<h3>' . t('Are you a Block Watch Captain?') . '</h3>
<p>Help your neighbors and other Block Watch captains find you. <a href="/node/add/community-group">Add</a> your contact information and map your Block Watch community.</p>
<div class="button"><a href="/node/add/community-group">Add New</a></div>
    '),
    '#description' => 'Prompt to add new groups.',
  );

  $form['sfo_food_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('sfo_food_content_news', 
    '<h3>' . t('Mapping in West Bay Area.') . '</h3>
<p>This fall we are reaching out to Block Watch Captains in West Bay Area to build a public map of Block Watch Groups.</p>
<p>As you can see, there are only a handful of Block Watch Captains listed, and our goal is to develop a complete list and map, and eventually have a Captain on every block in West Bay Area.</p>
<p>We are working with the <a href="http://genesee-schmitz.org">Genesee-Schmitz Neighborhood Council</a>, the <a href="http://wsfoodnet.wordpress.com/">West Bay Area Block Watch Captain’s Network</a> and the 
<a href="http://www.Bay Area.gov/spd/">Bay Area Police Department</a> to reach out to Block Watch Captains in Bay Area and fill in this map.</p>
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
<h3>What is a Block Watch Captain?</h3>
<p>Block Watch is a national program that is based on the principle that neighbors working together are the first and best line of defense against crime. The Captain is also the logical person to organize the efforts to prepare for a disaster or emergency like a major earthquake.  Each household and every block needs to be prepared.</p>
<p>Block Watch Captains take the lead among their neighbors by partnering with the Bay Area Police Department, the Department of Emergency Preparedness, and other city departments to alert them to suspicious activity,  to organize their block to prepare for and respond to an emergency, and create a better sense of community as neighbors help each other. Block parties, emergency kit building, street cleanups and other creative initiatives at the block or neighborhood level makes this work.</p>           
    '),
    '#description' => 'About content',
  );

  $form['sfo_food_content_about_participate'] = array(
    '#type' => 'textarea',
    '#title' => t('Participate'),
    '#default_value' =>  variable_get('sfo_food_content_about_participate', '
<h3>Get on the map</h3>
<p>The Bay Area Police Department estimates that there may be over 4,000 Block Watch Captains in various Block Watch Communities throughout Bay Area.</p>
<p>If you want to help your neighborhood get on the map, contact XXXXX, a community of Block Watch Organizers & Emergency Preparedness community leaders who are working to make Bay Area safer by building community.</p>
    '),
    '#description' => 'Participate',
  );

  $form['sfo_food_content_about_local'] = array(
    '#type' => 'textarea',
    '#title' => t('Local'),
    '#default_value' =>  variable_get('sfo_food_content_about_local', '
<h3>Block Watch Resources</h3>
<p>Get connected to the Bay Area Police Department and other local crime prevention & emergency preparedness initiatives.</p>
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
<ul>
  <li><a href="">West Bay Area food Captains Network</a></li>
  <li><a href="">Emergency Hubs</a></li>
  <li><a href="">SNAP (Bay Area Neighborhoods Actively Prepare)</a></li>
  <li><a href="">Bay Area Police Department, food</a></li>
</ul> 
'),
    '#description' => 'Links and resources',
  );

  $form['sfo_food_related_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('Related Groups'),
    '#default_value' =>  variable_get('sfo_food_related_groups', '
<div class="related-categories">
<ul class="categories">
  <li><a href="categories/emergency-preparedness">Emergency Preparedness</a></li>
  <li><a href="categories/national-night-out">National Night Out</a></li>
  <li><a href="categories/crime-prevention">Crime Prevention</a></li>
  <li><a href="categories/public-safety">Public Safety</a></li>
  <li><a href="categories/block-party">Block Party</a></li>
</ul>
</div>
'),
    '#description' => 'Links to related groups',
  );

  $form['sfo_food_related_terms'] = array(
    '#type' => 'textarea',
    '#title' => t('Related Terms'),
    '#default_value' =>  variable_get('sfo_food_related_terms', 'Block watch, Crime prevention, National Night Out, Emergency preparedness, Public safety, Block party'),
    '#description' => 'Links to related groups',
  );


  $form['sfo_food_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Term'),
    '#default_value' =>  variable_get('sfo_food_term', 'Block-Watch'),
    '#description' => 'Term to filter content',
  );

  $form['sfo_food_flyer'] = array(
    '#type' => 'textarea',
    '#title' => t('Flyer Text'),
    '#default_value' =>  variable_get('sfo_food_flyer', '
<h3>Help Map Block Watches in Bay Area</h3>
<p>Know a Block Watch Captain in Bay Area?</p>
<a href="http://Bay Area.citygroups.org/food">http://Bay Area.citygroups.org/food</a>
<p>Contact: Name Lastname, phone.</p>
    '),
    '#description' => 'Text to be used in flyers',
  );

  $form['sfo_food_email'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Text'),
    '#default_value' =>  variable_get('sfo_food_email', '
Know a Block Watch Captain? Ask them to get listed in the Block Watch Captain Directory. <a href="http://Bay Area.citygroups.org/food">http://Bay Area.citygroups.org/food</a>
    '),
    '#description' => 'Text to be used in emails',
  );

  $form['sfo_food_tweet'] = array(
    '#type' => 'textarea',
    '#title' => t('Tweet Text'),
    '#default_value' =>  variable_get('sfo_food_tweet', '
Know a Block Watch Captain? Ask them to get listed in the Block Watch Captain Directory. http://Bay Area.citygroups.org/food
    '),
    '#description' => 'Text to be used in tweets',
  );

  $form['sfo_food_facebook'] = array(
    '#type' => 'textarea',
    '#title' => t('Facebook Text'),
    '#default_value' =>  variable_get('sfo_food_facebook', '
Share the Block Watch Captain Directory on Facebook.
    '),
    '#description' => 'Text to be used in facebook share links',
  );

  $form['sfo_food_qrcode'] = array(
    '#type' => 'textarea',
    '#title' => t('QR Code path'),
    '#default_value' =>  variable_get('sfo_food_qrcode', '
Bay Area Block Watch Captain Directory
The Block Watch Captain Directory lists basic contact information for Block Watch Captains in Bay Area.

http://Bay Area.citygroups.org/food
'),
    '#description' => 'QR Code message: Message URL',
  );

  return system_settings_form($form);
}
