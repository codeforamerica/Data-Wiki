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
      $output .= '<h3>' . t('Find the nearest Block Watch Captain') . '</h3>';
      $output .= '<p>' . t('The Block Watch Captain Directory lists basic contact information for Block Watch Captains in Seattle.') .'</p>';
      break;
      
      case 'map':
        $output .= datawiki_group_map_render();
      break;
      
      case 'home_content':
        $output .= "
          <div class=\"grid_16 sections\">
           
            <div class=\"grid_6 add-new-group section alpha\">
              <h3>Are you a Block Watch Captain?</h3>
              <p>Help your neighbors and other Block Watch captains find you.

              <a href=\"/node/add/community-group?$" . $add_variables . "\">Add</a> your contact information and map your Block Watch community.</p>
              <div class=\"button\"><a href=\"/node/add/community-group?$" . $add_variables . "\">Add New</a></div>
            </div>    

            <div class=\"grid_6 push_2 view-data section omega\">
              <h3>View Block Watch Captains</h3>
              <p>Find a Block Watch Captain on the map.</p>
              <div id=\"search-map\" class=\"form-input\">
              <input placeholder=\"Enter your address or zipcode here.\" class=\"form-item\" />
              <input type=\"image\" src=\"" . base_path() . path_to_theme() . "/images/search_button.png\" id=\"search-links-submit\" class=\"search_btn\" value=\"Search\" alt=\"Search\">
              </div>
        
              <div class=\"button\"><a href=\"map\">Map view</a></div>
              <div class=\"button\"><a href=\"list\">List view</a></div>
            </div>

          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">
              <h3>Mapping in West Seattle.</h3>
              <p>This fall we are reaching out to Block Watch Captains in West Seattle to build a public map of Block Watches.</p>
              <p>As you can see, there are only a handful of Block Watch Captains listed.</p>
              <p>We are working with the <a href=\"http://wsbwcn.com\">West Seattle Block Watch Captain’s Network</a> and the 
              <a href=\"http://seattle.gov/police\">Seattle Police Department</a> to reach out to Block Watch Captains in Seattle and fill in this map.</p>
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
          <h3>What is BWCF</h3>
          
          We make it easy to find and share all kinds of groups in your city
          <div class=\"groups-icons\">" . $links . "</div>
          
          <p>Banh mi vinyl vegan laboris magna, nihil hoodie portland homo cillum raw denim tempor. High life wayfarers you probably haven't heard of them, assumenda twee wes anderson ut dreamcatcher put a bird on it nulla echo park marfa master cleanse consequat quis. Dolor adipisicing accusamus hoodie chambray blog. Qui ullamco laboris whatever shoreditch voluptate. Brooklyn sartorial cliche, dolore whatever exercitation odio scenester. Chambray scenester esse magna locavore. Stumptown proident pariatur nesciunt.</p>
          </div>
  
          <div class=\"grid_4 push_1 participate\">
          <h3>Get on the map</h3>
          <p>Banh mi vinyl vegan laboris magna, nihil hoodie portland homo cillum raw denim tempor. High life wayfarers you probably haven't heard of them, assumenda twee wes anderson ut dreamcatcher put a bird on it nulla echo park marfa master cleanse consequat quis. Dolor adipisicing accusamus hoodie chambray blog. Qui ullamco laboris whatever shoreditch voluptate. Brooklyn sartorial cliche, dolore whatever exercitation odio scenester. Chambray scenester esse magna locavore. Stumptown proident pariatur nesciunt.</p>
          </div>
    
          <div class=\"grid_4 push_1 local omega\">
          <h3>Local Community Groups</h3>
          <p>Banh mi vinyl vegan laboris magna, nihil hoodie portland homo cillum raw denim tempor. High life wayfarers you probably haven't heard of them, assumenda twee wes anderson ut dreamcatcher put a bird on it nulla echo park marfa master cleanse consequat quis. Dolor adipisicing accusamus hoodie chambray blog. Qui ullamco laboris whatever shoreditch voluptate. Brooklyn sartorial cliche, dolore whatever exercitation odio scenester. Chambray scenester esse magna locavore. Stumptown proident pariatur nesciunt.</p>
          </div>
        </div>        
        ";
      break;      

  }
  
  return $output;
}