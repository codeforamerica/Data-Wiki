<?php

/**
 * Implements hook_block_info().
 */
function sea_blockwatch_block_info() {
  $blocks['sea_blockwatch_welcome'] = array(
    'info' => t('Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_home_content'] = array(
    'info' => t('Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_about'] = array(
    'info' => t('About'),
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
          <div class=\"grid_16 sections alpha omega \">
           
            <div class=\"grid_6 add-new-group section alpha\">
              <h3>Are you a Block Watch Captain?</h3>
              <p>Help your neighbors and other Block Watch captains find you.

              <a href=\"/node/add/community-group" . $add_variables . "\">Add</a> your contact information and map your Block Watch community.</p>
              <div class=\"button\"><a href=\"/node/add/community-group" . $add_variables . "\">Add New</a></div>
            </div>    

            <div class=\"grid_6 push_2 view-data section omega\">
              <h3>View Block Watch Captains</h3>
              <p>Find a Block Watch Captain on the map.</p>
        
              <div class=\"button\"><a href=\"blockwatch/map\">Map view</a></div>
              <div class=\"button\"><a href=\"blockwatch/list\">List view</a></div>
            </div>

          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">
              <h3>Mapping in West Seattle.</h3>
              <p>This fall we are reaching out to Block Watch Captains in West Seattle to build a public map of Block Watches.</p>
              <p>As you can see, there are only a handful of Block Watch Captains listed.</p>
              <p>We are working with the <a href=\"http://wsblockwatchnet.wordpress.com/\">West Seattle Block Watch Captain’s Network</a> and the 
              <a href=\"http://www.seattle.gov/spd/\">Seattle Police Department</a> to reach out to Block Watch Captains in Seattle and fill in this map.</p>
            </div>    
            <div class=\"grid_6 push_2 promote section omega\">
              <h3>Spread the word</h3>
              <p>Tell your friends, neighbors & local community groups.</p>
              <p>We’ve written emails, made <a href=\"blockwatch/get-involved\">printable flyers</a> to make it easy to explain to others.</p>
            </div>      
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
            <p>Block Watch is a national program that is based on the principle that neighbors working together are the first and best line of defense against crime.</p>
            <p>Block Watch Captains take the lead among their neighbors by partnering with the police department and other city departments to alert them to suspicious activity and creating a better sense of community. Block parties, street cleanups and other creative initiatives at the block or neighborhood level makes this work</p>
          </div>
  
          <div class=\"grid_4 push_1 participate\">
          <h3>Get on the map</h3>
            <p>The Seattle Police Department estimates that there may be over 4,000 Block Watch Captains in various Block Watch Communities throughout Seattle.</p>
            <p>If you want to help your neighborhood get on the map, contact XXXXX, a community of Block Watch Organizers & Emergency Preparedness community leaders who are working to make Seattle safer by building community.</p>         
          </div>

          <div class=\"grid_4 push_1 local omega\">
            <h3>Block Watch Resources</h3>
            <p>Get connected to the Seattle Police Department and other local crime prevention & emergency preparedness initiatives.</p>
            <h3>More Local community groups</h3>
            <p>CityGroups lists other kinds of community groups working to make your neighborhood better in Seattle. Find other community leaders near you.</p>
          </div>
        </div>        
        ";
      break;      

  }
  
  return $output;
}