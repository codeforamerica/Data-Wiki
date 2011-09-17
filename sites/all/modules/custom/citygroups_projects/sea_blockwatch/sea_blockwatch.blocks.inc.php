<?php

/**
 * Implements hook_block_info().
 */
function sea_blockwatch_block_info() {
  $blocks['sea_blockwatch_welcome'] = array(
    'info' => t('Seattle Blockwatch: Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_home_content'] = array(
    'info' => t('Seattle Blockwatch: Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_about'] = array(
    'info' => t('Seattle Blockwatch: About'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function sea_blockwatch_block_view($delta = '') {
  switch ($delta) {
    case 'sea_blockwatch_welcome':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('welcome');
      break; 

    case 'sea_blockwatch_home_content':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('home_content');
      break;

    case 'sea_blockwatch_about':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('about');
      break; 
  }
  return $block;
}

/**
 * Block placeholder content
 */
function sea_blockwatch_contents($type) {
  $output = '';
  $add_variables = '?section=blockwatch&destination=blockwatch';
  // $add_variables = "?category=Block Watch, Crime Prevention&title=Add a Block Watch Captain&instructions=List Block Watch Captain or Block Watch Group.&map_instructions=Where is this Block Watch?";
    
  switch ($type) {
    case 'welcome':
      $output .= '<p>' . t('The Block Watch Captain Directory lists basic contact information for Block Watch Captains in Seattle.') .'</p>';
      break;
      
      case 'home_content':
        $output .= "
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 add-new-group section alpha\">"
              . variable_get('sea_blockwatch_content_add_new_group') .  "
            </div>
            <div class=\"grid_6 push_2 view-data section omega\">"
              . variable_get('sea_blockwatch_content_groups') .
              
              /*
              "<div id=\"search-map\" class=\"form-input\">
              <input placeholder=\"Enter your address or zipcode here.\" class=\"form-item\" />
              <input type=\"image\" src=\"" . base_path() . path_to_theme() . "/images/search_button.png\" id=\"search-links-submit\" class=\"search_btn\" value=\"Search\" alt=\"Search\">
              </div> 
              */
              "Over <strong>" . variable_get('citygroups_stats_groups_published') . " groups</strong> in " . variable_get('citygroups_city_name') . "." .
              
              "<div class=\"button\"><a href=\"map\">Map view</a></div>
              <div class=\"button\"><a href=\"list\">List view</a></div>
            </div>
          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">"
              . variable_get('sea_blockwatch_content_news') .  "                          
            </div>    
            <div class=\"grid_6 push_2 promote section omega\">" 
            . variable_get('sea_blockwatch_content_promote')
            . citygroups_promote()
            . "</div>      
          </div>
        ";
      break;  
  
      case 'about':
      
        $facebook = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_facebook.png" title="Facebook" alt="Facebook" />';
        $yahoo = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_yahoo_groups.png" title="Yahoo Groups" alt="Yahoo Groups" />';
        $google = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_google_groups.png" title="Google Groups" alt="Google Groups" />';
        $meetup = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_meetup.png" title="Meetup Groups" alt="Meetup Groups" />';
        $mailinglist = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_email.png" title="Email" alt="Email" />';
        $twitter = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_twitter.png" title="Twitter" alt="Twitter" />';
        $blog = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_blogs.png" title="Community Blogs" alt="Community Blogs" />';
        $mail = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_mail.png" title="Personal Email" alt="Personal Email" />';
  
        $links = $facebook . $google . $meetup . $mailinglist . $twitter . $blog . $yahoo . $mail /*. $ning */;

        $output .= "
        <div class=\"grid_16 postscript-content alpha omega\">
          <div class=\"grid_6 about alpha\">
            <h3>What is a Block Watch Captain?</h3>
              <p>Block Watch is a national program that is based on the principle that neighbors working together are the first and best line of defense against crime. The Captain is also the logical person to organize the efforts to prepare for a disaster or emergency like a major earthquake.  Each household and every block needs to be prepared.</p>
              <p>Block Watch Captains take the lead among their neighbors by partnering with the Seattle Police Department, the Department of Emergency Preparedness, and other city departments to alert them to suspicious activity,  to organize their block to prepare for and respond to an emergency, and create a better sense of community as neighbors help each other. Block parties, emergency kit building, street cleanups and other creative initiatives at the block or neighborhood level makes this work.</p>
          </div>
  
          <div class=\"grid_4 push_1 participate\">
          <h3>Get on the map</h3>
            <p>The Seattle Police Department estimates that there may be over 4,000 Block Watch Captains in various Block Watch Communities throughout Seattle.</p>
            <p>If you want to help your neighborhood get on the map, contact XXXXX, a community of Block Watch Organizers & Emergency Preparedness community leaders who are working to make Seattle safer by building community.</p>         
          </div>

          <div class=\"grid_4 push_1 local omega\">
            <h3>Block Watch Resources</h3>
            <p>Get connected to the Seattle Police Department and other local crime prevention & emergency preparedness initiatives.</p>
            <p><a href=\"/blockwatch/resources\">See list of resources</a></p>
            <br />
            <h3>More Local community groups</h3>
            <p>CityGroups lists other kinds of community groups working to make your neighborhood better in Seattle. Find other community leaders near you.</p>
            <p><a href=\"/blockwatch/categories\">See related groups</a></p>
          </div>
        </div>        
        ";
      break;      

  }
  
  return $output;
}