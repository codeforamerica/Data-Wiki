<?php

/**
 * @file
 * 
 */

/**
 * Category edit page.
 */
function sea_blockwatch_configure_edit_form($form, &$form_state, array $rule = array()) {
   $form['introduction'] = array(
    '#markup' => '
    <h3>Configure Seattle Blockwatch </h3>
    <p><strong>Configure the Seattle Blockwatch pages.</strong></p>
    <a name="site-content"></a>    
    <h3>Site Content</h3>
    <p>Enter custom text that should appear throughout the site & on the homepage.</p>
    ',
  );

  $form['sea_blockwatch_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of Project'),
    '#default_value' =>  variable_get('sea_blockwatch_name', 'Block Watch Captain Directory'),
    '#description' => 'Name of project.',
  );
  
  $form['sea_blockwatch_slogan'] = array(
    '#type' => 'textarea',
    '#title' => t('Slogan'),
    '#default_value' =>  variable_get('sea_blockwatch_slogan', 'Find the nearest Block Watch Captain.'),
    '#description' => 'Slogan.',
  ); 

  $form['sea_blockwatch_content_tagline'] = array(
    '#type' => 'textarea',
    '#title' => t('Tagline'),
    '#default_value' =>  variable_get('sea_blockwatch_content_tagline', '
<p>The Block Watch Captain Directory lists basic contact information for Block Watch Captains in Seattle.</p>'),
    '#description' => 'Customize site tagline',
  );

  $form['sea_blockwatch_content_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('View Groups (homepage content)'),
    '#default_value' =>  variable_get('sea_blockwatch_content_groups', '
<h3>' . t('View Block Watch Captains') .'</h3>
<p>Find a Block Watch Captain on the map.</p>'
    ),
    '#description' => 'Prompt to check out groups in the directory',
  );

  $form['sea_blockwatch_content_add_new_group'] = array(
    '#type' => 'textarea',
    '#title' => t('Add New Group (homepage content)'),
    '#default_value' =>  variable_get('sea_blockwatch_content_add_new_group', '
<h3>' . t('Are you a Block Watch Captain?') . '</h3>
<p>Help your neighbors and other Block Watch captains find you. <a href="/node/add/community-group">Add</a> your contact information and map your Block Watch community.</p>
<div class="button"><a href="/node/add/community-group">Add New</a></div>
    '),
    '#description' => 'Prompt to add new groups.',
  );

  $form['sea_blockwatch_content_news'] = array(
    '#type' => 'textarea',
    '#title' => t('News (homepage content)'),
    '#default_value' =>  variable_get('sea_blockwatch_content_news', 
    '<h3>' . t('Mapping in West Seattle.') . '</h3>
<p>This fall we are reaching out to Block Watch Captains in West Seattle to build a public map of Block Watch Groups.</p>
<p>As you can see, there are only a handful of Block Watch Captains listed, and our goal is to develop a complete list and map, and eventually have a Captain on every block in West Seattle.</p>
<p>We are working with the <a href="http://genesee-schmitz.org">Genesee-Schmitz Neighborhood Council</a>, the <a href="http://wsblockwatchnet.wordpress.com/">West Seattle Block Watch Captain’s Network</a> and the 
<a href="http://www.seattle.gov/spd/">Seattle Police Department</a> to reach out to Block Watch Captains in Seattle and fill in this map.</p>
'),
    '#description' => 'News about this project',
  );

  $form['sea_blockwatch_content_promote'] = array(
    '#type' => 'textarea',
    '#title' => t('Promote (homepage content)'),
    '#default_value' =>  variable_get('sea_blockwatch_content_promote', '
<h3>Spread the word</h3>
<p>Tell your friends, neighbors & local community groups.</p>
<p>We’ve written emails, made <a href="blockwatch/get-involved">printable flyers</a> to make it easy to explain to others.</p>'),
    '#description' => 'Links to promotional content',
  );
  

  $form['sea_blockwatch_social_media_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#default_value' =>  variable_get('sea_blockwatch_social_media_twitter', 'AllCityGroups'),
    '#description' => 'What is the account name? (Ex. BostonCityGroups)',
  );
  
  $form['sea_blockwatch_social_media_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' =>  variable_get('sea_blockwatch_social_media_facebook', array()),
    '#description' => 'Link to Facebook page',
  );

  $form['sea_blockwatch_mailing_list'] = array(
    '#type' => 'textfield',
    '#title' => t('Mailing List'),
    '#default_value' =>  variable_get('sea_blockwatch_mailing_list', 'http://citygroups.us2.list-manage1.com/subscribe?u=eb1facd19686e6ad279923882&id=ea0d4c3774'),
    '#description' => 'Link to mailing list.',
  );

  $form['sea_blockwatch_social_media_flyer'] = array(
    '#type' => 'textfield',
    '#title' => t('Flyer'),
    '#default_value' =>  variable_get('sea_blockwatch_social_media_flyer', array()),
    '#description' => 'Path to printable flyer',
  );

  $form['sea_blockwatch_content_about'] = array(
    '#type' => 'textarea',
    '#title' => t('About'),
    '#default_value' =>  variable_get('sea_blockwatch_content_about', '
<h3>What is a Block Watch Captain?</h3>
<p>Block Watch is a national program that is based on the principle that neighbors working together are the first and best line of defense against crime. The Captain is also the logical person to organize the efforts to prepare for a disaster or emergency like a major earthquake.  Each household and every block needs to be prepared.</p>
<p>Block Watch Captains take the lead among their neighbors by partnering with the Seattle Police Department, the Department of Emergency Preparedness, and other city departments to alert them to suspicious activity,  to organize their block to prepare for and respond to an emergency, and create a better sense of community as neighbors help each other. Block parties, emergency kit building, street cleanups and other creative initiatives at the block or neighborhood level makes this work.</p>           
    '),
    '#description' => 'About content',
  );

  $form['sea_blockwatch_content_about_participate'] = array(
    '#type' => 'textarea',
    '#title' => t('Participate'),
    '#default_value' =>  variable_get('sea_blockwatch_content_about_participate', '
<h3>Get on the map</h3>
<p>The Seattle Police Department estimates that there may be over 4,000 Block Watch Captains in various Block Watch Communities throughout Seattle.</p>
<p>If you want to help your neighborhood get on the map, contact XXXXX, a community of Block Watch Organizers & Emergency Preparedness community leaders who are working to make Seattle safer by building community.</p>
    '),
    '#description' => 'Participate',
  );

  $form['sea_blockwatch_content_about_local'] = array(
    '#type' => 'textarea',
    '#title' => t('Local'),
    '#default_value' =>  variable_get('sea_blockwatch_content_about_local', '
<h3>Block Watch Resources</h3>
<p>Get connected to the Seattle Police Department and other local crime prevention & emergency preparedness initiatives.</p>
<p><a href="/blockwatch/resources">See list of resources</a></p>
<br />
<h3>More Local community groups</h3>
<p>CityGroups lists other kinds of community groups working to make your neighborhood better in Seattle. Find other community leaders near you.</p>
<p><a href="/blockwatch/categories">See related groups</a></p>
'),
    '#description' => 'Local',
  );

  $form['sea_blockwatch_resources'] = array(
    '#type' => 'textarea',
    '#title' => t('Resources'),
    '#default_value' =>  variable_get('sea_blockwatch_resources', '
<ul>
  <li><a href="">West Seattle Blockwatch Captains Network</a></li>
  <li><a href="">Emergency Hubs</a></li>
  <li><a href="">SNAP (Seattle Neighborhoods Actively Prepare)</a></li>
  <li><a href="">Seattle Police Department, Blockwatch</a></li>
</ul> 
'),
    '#description' => 'Links and resources',
  );

  $form['sea_blockwatch_related_groups'] = array(
    '#type' => 'textarea',
    '#title' => t('Related Groups'),
    '#default_value' =>  variable_get('sea_blockwatch_related_groups', '
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

  $form['sea_blockwatch_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Term'),
    '#default_value' =>  variable_get('sea_blockwatch_term', 'Block-watch'),
    '#description' => 'Term to filter content',
  );

  return system_settings_form($form);
}
