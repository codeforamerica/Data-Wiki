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
  $blocks['citygroups_sub_facebook_like'] = array(
    'info' => t('Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_add_data'] = array(
    'info' => t('Add Data'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_new_group_search'] = array(
    'info' => t('New Group Search'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_site_tagline'] = array(
    'info' => t('Site Tagline'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_map'] = array(
    'info' => t('Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_categories'] = array(
    'info' => t('Categories'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_list'] = array(
    'info' => t('List'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_home_menu'] = array(
    'info' => t('Home Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_categories_menu'] = array(
    'info' => t('Categories Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_map_menu'] = array(
    'info' => t('Map Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_list_menu'] = array(
    'info' => t('List Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_projects'] = array(
    'info' => t('Projects'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_sub_add_group'] = array(
    'info' => t('Add Group'),
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
      
    case 'citygroups_sub_facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $block['subject'] = '';
      $block['content'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;

    case 'citygroups_sub_new_group_search':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('new_group_search');
      break;

    case 'citygroups_sub_add_data':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('add_data');
      break;

    case 'citygroups_sub_site_tagline':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('site_tagline');
      break;
      
    case 'citygroups_sub_map':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('map');
      break;
    
    case 'citygroups_sub_categories':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('categories');
      break;
    
    case 'citygroups_sub_list':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('list');
      break;
      
    case 'citygroups_sub_home_menu':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('home_menu');
      break;
    
    case 'citygroups_sub_categories_menu':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('categories_menu');
      break;
      
    case 'citygroups_sub_list_menu':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('list_menu');
      break; 

    case 'citygroups_sub_map_menu':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('map_menu');
      break;
    
    case 'citygroups_sub_projects':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('projects');
      break;

    case 'citygroups_sub_add_group':
      $block['subject'] = '';
      $block['content'] = citygroups_sub_contents('add_group');
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
      $output .= '<p>' . t('Find groups by location or topic.') .'</p>';
      break;

    case 'site_tagline':
      $output .= '<h3>' . t('A public directory of over 300 community groups in the Seattle area.') . '</h3>';
      break;
      
    case 'branding_header':
      $output .= '<div id="branding-header"></div>';
      break;
      
    case 'branding_footer':
      $code_for_america = '';
      $output .= '<div id="branding-footer alpha omega grid_16">' 
      . '<div class="about grid_6">' 
      . t('Maintained by the City and Community Groups.') . '<br />'
      . t('Created as Open Source by <a href="http://codeforamerica.org">Code for America</a>') 
      . '<div class="tagline">' .  t('"For a more transparent, efficient and participatory future."') . '</div>' . '</div>'
      . '<div class="logo grid_10"><a href="http://codeforamerica.org">' . '<img src="' . base_path() . path_to_theme() . '/images/cfa-full-logo.png" width="150" />' . '</a></div>'
      . '</div>';
      break;

    case 'new_group_search':
      global $base_url;
        $output .= '<div id="search-links">';
        $output .= '<div id="search-places" class="form-input">';
        $output .= '<input placeholder="Enter your address or zipcode here." size=50 class="form-item" />';
        $output .= '<input type="image" src="' . base_path() . path_to_theme() . '/images/search_icon-50.png" id="search-links-submit" class="search_btn" value="Search" alt="Search">';
        $output .= '</div>';
        $output .= '</div>';
      break;
      
    case 'add_data':

      $facebook = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_facebook.png" title="Facebook" alt="Facebook" />';
      $yahoo = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_yahoo_groups.png" title="Yahoo Groups" alt="Yahoo Groups" />';
      $google = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_google_groups.png" title="Google Groups" alt="Google Groups" />';
      $meetup = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_meetup.png" title="Meetup Groups" alt="Meetup Groups" />';
      $mailinglist = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_email.png" title="Email" alt="Email" />';
      $twitter = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_twitter.png" title="Twitter" alt="Twitter" />';
      $blog = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_blogs.png" title="Community Blogs" alt="Community Blogs" />';
      $mail = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_mail.png" title="Personal Email" alt="Personal Email" />';

      $links = $facebook . $google . $meetup . $mailinglist . $twitter . $blog . $yahoo . $mail /*. $ning */;
      $output .= '<div class="add-data">' .
        '<h3>' . t('We make it easy to find and share all kinds of groups in your city.') . '</h3>'
        . '<div class="groups-icons">' . $links . '</div>'
        . '</div>';
      break;
      
      case 'map':
        $output .= datawiki_group_map_render();
      break;
      
      case 'categories':
        $output .= " ";
      break;
      
      case 'list':
        $output .= " ";
      break;
      
      case 'home_menu':
        $output .= '<div id="map-links">';
        $output .= '<ul>';
        $output .= '<li><a href="/">' . t('Home/Map') . '</a></li>';
        $output .= '<li><a href="/list">' . t('View as List') . '</a></li>';
        $output .= '<li><a href="/categories">' . t('All Topics') . '</a></li>';
        $output .= '</ul>';
        $output .= '</div>';                
      break;
      
      case 'map_menu':
        $output .= '';
      break;
      
      case 'list_menu':
        $output .= " ";
      break;
      
      case 'categories_menu':
        $output .= " ";
      break;

      case 'add_group':
        $output .= "<div class=\"add-group\"><a href=\"/node/add/community-group\">Add Group</a></div> ";
      break;

      case 'projects':
        $output .= "<ul class=\"menu citygroups-projects\">
        <li><a href=\"blockwatch\">Block Watch Captain Finder</a></li>
        </ul>";
        
        /*
        <li><a href=\"wallingford\">Wallingford</a></li>
        <li><a href=\"food\">Food</a></li>
        <li><a href=\"calendars\">Calendars</a></li>
        */
      break;
  }
  
  return $output;
}
