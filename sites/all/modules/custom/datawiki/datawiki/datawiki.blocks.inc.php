<?php

/**
 * Implements hook_block_info().
 */
function datawiki_block_info() {
/*
  $blocks['datawiki_welcome'] = array(
    'info' => t('Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['datawiki_branding_header'] = array(
    'info' => t('Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
*/
  $blocks['datawiki_branding_footer'] = array(
    'info' => t('Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
/*
  $blocks['datawiki_facebook_like'] = array(
    'info' => t('Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['datawiki_add_data'] = array(
    'info' => t('Add Data'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['datawiki_new_group_search'] = array(
    'info' => t('New Group Search'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['datawiki_home_menu'] = array(
    'info' => t('Home Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );*/
  $blocks['datawiki_navigation_menu'] = array(
    'info' => t('Navigation Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
/*
  $blocks['datawiki_header_menu'] = array(
    'info' => t('Header Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
*/
  $blocks['datawiki_dashboard_add_content'] = array(
    'info' => t('Dashboard Add Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function datawiki_block_view($delta = '') {
  switch ($delta) {  
    case 'datawiki_welcome':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('welcome');
      break;
      
    case 'datawiki_branding_header':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('branding_header');
      break;
      
    case 'datawiki_branding_footer':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('branding_footer');
      break;     
      
    case 'datawiki_facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $block['subject'] = '';
      $block['content'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;

    case 'datawiki_new_group_search':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('new_group_search');
      break;

    case 'datawiki_add_data':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('add_data');
      break;
    
    case 'datawiki_home_menu':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('home_menu');
      break;
      
    case 'datawiki_navigation_menu':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('navigation_menu');
      break;
      
    case 'datawiki_header_menu':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('header_menu');
      break;
    
    case 'datawiki_dashboard_add_content':
      $block['subject'] = '';
      $block['content'] = datawiki_contents('dashboard_add_content');
      break;  
  }
  return $block;
}

/**
 * Block placeholder content
 */
function datawiki_contents($type) {
  $output = '';
  
  switch ($type) {      
    case 'welcome':
      $output .= '<h2>' . t('Find groups by location or topic.') . '</h2>';
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
      $output .= '<div id="new-group-search">' 
        . '<div class="form-submit">'
        . l('New Search', $base_url)
        . '</div>'
        . '</div>';
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
/*       $ning = '<img src="' . base_path() . path_to_theme() . '/images/cfa-full-logo.png" />'; */

      $links = $facebook . $google . $meetup . $mailinglist . $twitter . $blog . $yahoo . $mail /*. $ning */;
      $output .= '
        <div class="add-data">' .
        '<h3>' . t('We make it easy to find and share all kinds of groups in your city.') . '</h3>'
        . '<div class="groups-icons">' . $links . '</div>'
/*           . t('Know a cool group? Why not <a href="/node/add/online-community">Add</a> it?') */
        . '</div>';
      break;
      
      case 'home_menu':
        $output .= "<div id=\"home-menu\">"
          .  "<div id=\"home-menu-locations\" class=\"item\">"
          . "<h3>Location</h3>"
          . "<div class=\"menu-item place\"><a href=\"/map\">
              <img src=\"" . base_path() . path_to_theme() . "/images/icons/icon_place.gif\" title=\"Map\" alt=\"Map\" />"
          . "<div class=\"label\">Map</div></a></div>"
          . "<div class=\"menu-item list\"><a href=\"/list\" ><img src=\"" . base_path() . path_to_theme() . "/images/icons/icon_tag.gif\" title=\"List\" alt=\"List\" /><div class=\"label\">List</div></a></div>"
          . "</div>"
          .  "<div id=\"home-menu-locations\" class=\"item\">"
          . "<h3>Topic</h3>"
          . "<div class=\"menu-item topics\"><a href=\"/categories\"><img src=\"" . base_path() . path_to_theme() . "/images/icons/icon_blog.gif\" title=\"Topics\" alt=\"Topics\" /><div class=\"label\">Topics</div></a></div>"
          . "</div>"
          .  "<div id=\"home-menu-projects\" class=\"item\">"          
          . "<h3>Projects</h3>"
          . "<div class=\"menu-item projects\"><a href=\"/projects\"><img src=\"" . base_path() . path_to_theme() . "/images/icons/icon_blog.gif\" title=\"Projects\" alt=\"Projects\" /><div class=\"label\">Projects</div></a></div>"
  
          . "</div>";

        break;
        
      case 'navigation_menu':
        $output .= "<ul class=\"menu\">";
        $output .= "<li><a href=\"/about\">About</a></li>";
        $output .= "<li><a href=\"/get-involved\">Get Involved</a></li>";
        $output .= "<li><a href=\"/map\">Map</a></li>";
        $output .= "<li><a href=\"/list\">List</a></li>";
        $output .= "<li><a href=\"/categories\">Topics</a></li>";
        $output .= "<li><a href=\"/node/add/community-group\">Add Group</a></li>";
        $output .= "<li><a href=\"/community-data-api\">Community Data & API</a></li>";
        $output .= "<li><a href=\"/contact\">Contact</a></li>";
        $output .= "<li><a href=\"/projects\">Projects</a></li>";
        $output .= "</ul>";
        break;

      case 'header_menu':
        $output .= "<ul class=\"menu\">";
        $output .= "<li><a href=\"/\">Home</a></li>";
        $output .= "<li><a href=\"/map\">Map</a></li>";
        $output .= "<li><a href=\"/list\">List</a></li>";
        $output .= "<li><a href=\"/topics\">Topics</a></li>";
        $output .= "<li><a href=\"/node/add/community-group\">Add A Group</a></li>";
        $output .= "</ul>";
        break;
        
      case 'dashboard_add_content':
        $output .= "<h3>Initial Setup</h3>";
        $output .= "<ol class=\"menu\">";
        $output .= "<li>Import a CSV file: <a href=\"/node/add/community-group-feed-upload-csv\">Upload CSV</a></li>";
        $output .= "<li>Edit site information: <a href=\"#\">Site</a></li>";
        $output .= "</ol>";

        $output .= "<h3>Add Content</h3>";
        $output .= "<ul class=\"menu\">";
        $output .= "<li><a href=\"/node/add/community-group\">Add A Group</a></li>";
        $output .= "<li><a href=\"/node/add/community-group-feed-upload-csv\">Upload CSV</a></li>";
        $output .= "</ul>";
        break;
      
  }
  
  return $output;
}