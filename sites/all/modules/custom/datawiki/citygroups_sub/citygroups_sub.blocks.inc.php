<?php

/**
 * Implements hook_block_info().
 */
function citygroups_sub_block_info() {
  $blocks['citygroups_sub_welcome'] = array(
    'info' => t('Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_branding_header'] = array(
    'info' => t('Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_branding_footer'] = array(
    'info' => t('Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_site_slogan'] = array(
    'info' => t('Site Slogan'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_facebook_like'] = array(
    'info' => t('Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_home_content'] = array(
    'info' => t('Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );

  $blocks['citygroups_sub_about'] = array(
    'info' => t('About'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_map'] = array(
    'info' => t('Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function citygroups_sub_block_view($delta = '') {
  switch ($delta) {
    case 'citygroups_sub_welcome':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('welcome');
      break;
      
    case 'citygroups_sub_branding_header':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('branding_header');
      break;
      
    case 'citygroups_sub_branding_footer':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('branding_footer');
      break;     

    case 'citygroups_sub_site_slogan':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('site_slogan');
      break;

    case 'citygroups_about_citygroups':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('about_citygroups');
      break;         

    case 'citygroups_sub_facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $block['subject'] = '';
      $block['content'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;

    case 'citygroups_sub_home_content':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('home_content');
      break;


    case 'citygroups_sub_about':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('about');
      break; 

    case 'citygroups_sub_map':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('map');
      break;
  }
  return $block;
}

/**
 * Block placeholder content
 */
function citygroups_sub_contents($type) {
  $output = '';
  
  switch ($type) {
    case 'welcome':
      $output .= '<h3>' . t('Find community groups by location or topic.') . '</h3>';
      $output .= '<p>' . t('Welcome to the site.') .'</p>';
      break;

    case 'site_slogan':
      $output .= '<h3>' . t('A public directory of community groups in the Seattle area.') . '</h3>';
      break;
      
    case 'branding_header':
      $output .= '<div id="branding-header"></div>';
      break;
      
    case 'branding_footer':
      $code_for_america = '';
      $output .= '<div id="branding-footer alpha omega grid_16 alpha omega">' 
      . '<div class="about grid_6 alpha">' 
      . t('Maintained by the City and Community Groups.') . '<br />'
      . t('Created as Open Source by <a href="http://codeforamerica.org">Code for America</a>') 
      . '<div class="tagline">' .  t('"For a more transparent, efficient and participatory future."') . '</div>' . '</div>'
      . '<div class="logo grid_10"><a href="http://codeforamerica.org">' . '<img src="' . base_path() . path_to_theme() . '/images/cfa-full-logo.png" width="150" />' . '</a></div>'
      . '</div>';
      break;

      
      case 'map':
        $output .= datawiki_group_map_render();
      break;
      
      case 'home_content':
        $output .= "
          <div class=\"grid_16 sections\">

            <div class=\"grid_6 view-data section alpha\">
              <h3>See the groups</h3>
              <p>asdfasdfasdf</p>
              <div id=\"search-map\" class=\"form-input\">
              <input placeholder=\"Enter your address or zipcode here.\" size=40 class=\"form-item\" />
              <input type=\"image\" src=\"" . base_path() . path_to_theme() . "/images/search_button.png\" id=\"search-links-submit\" class=\"search_btn\" value=\"Search\" alt=\"Search\">
              </div>
        
              <div class=\"button\"><a href=\"map\">Map view</a></div>
              <div class=\"button\"><a href=\"list\">List view</a></div>
            </div>

           
            <div class=\"grid_6  push_2  add-new-group section omega\">
              <h3>Can you recommend any community groups?</h3>
              <p>asdfasdfasdf</p>
              <div class=\"button\"><a href=\"/node/add/community-group\">Add New</a></div>
            </div>    

          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">
              <h3>We're mapping Block Watch Captains</h3>
              <p>asdfasdfasdf</p>
            </div>    
            <div class=\"grid_6 push_2 promote section omega\">
              <h3>Spread the word</h3>
              <p>asdfasdfasdf</p>
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
          <h3>What is CityGroups?</h3>
          
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

/*
    case 'new_group_search':
      global $base_url;
        $output .= '<div id="search-links">';
        $output .= '<div id="search-places" class="form-input">';
        $output .= '<input placeholder="Enter your address or zipcode here." size=50 class="form-item" />';
        $output .= '<input type="image" src="' . base_path() . path_to_theme() . '/images/search_icon-50.png" id="search-links-submit" class="search_btn" value="Search" alt="Search">';
        $output .= '</div>';
        $output .= '</div>';
      break;
*/
    
