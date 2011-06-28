<?php

/**
 * Implements hook_block_info().
 */
function sea_calendars_block_info() {
  $blocks['sea_calendars_welcome'] = array(
    'info' => t('Seattle calendars Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_branding_header'] = array(
    'info' => t('Seattle calendars Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_branding_footer'] = array(
    'info' => t('Seattle calendars Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_facebook_like'] = array(
    'info' => t('Seattle calendars Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_add_data'] = array(
    'info' => t('Seattle calendars Add Data'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_search'] = array(
    'info' => t('Seattle calendars Search'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_site_tagline'] = array(
    'info' => t('Seattle calendars Site Tagline'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_map'] = array(
    'info' => t('Seattle calendars Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_categories'] = array(
    'info' => t('Seattle calendars Categories'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_list'] = array(
    'info' => t('Seattle calendars List'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_home_menu'] = array(
    'info' => t('Seattle calendars Home Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_topics_menu'] = array(
    'info' => t('Seattle calendars Categories Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_map_menu'] = array(
    'info' => t('Seattle calendars Map Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_list_menu'] = array(
    'info' => t('Seattle calendars List Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_calendars_about_block'] = array(
    'info' => t('Seattle calendars About Block'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function sea_calendars_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'sea_calendars_welcome':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('welcome');
      break;
      
    case 'sea_calendars_branding_header':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('branding_header');
      break;
      
    case 'sea_calendars_branding_footer':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('branding_footer');
      break;     
      
    case 'sea_calendars_facebook_like':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('facebook_like');
     break;

    case 'sea_calendars_search':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('search');
      break;

    case 'sea_calendars_add_data':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('add_data');
      break;

    case 'sea_calendars_site_tagline':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('site_tagline');
      break;
      
    case 'sea_calendars_map':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('map');
      break;
    
    case 'sea_calendars_categories':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('categories');
      break;
    
    case 'sea_calendars_list':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('list');
      break;
      
    case 'sea_calendars_home_menu':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('home_menu');
      break;
    
    case 'sea_calendars_topics_menu':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('topics_menu');
      break;
      
    case 'sea_calendars_list_menu':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('list_menu');
      break; 

    case 'sea_calendars_map_menu':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('map_menu');
      break;
       
    case 'sea_calendars_about_block':
      $block['subject'] = '';
      $block['content'] = sea_calendars_contents('about_block');
      break;
  }
  return $block;
}

/**
 * Block placeholder content
 */
function sea_calendars_contents($type) {
  $output = '';
  $add_variables = '?section=calendars&destination=calendars';
 
  switch ($type) {
    case 'welcome':
      $output .= t('Welcome Message');
      break;

    case 'site_tagline':
      $output .= '<h2>' . t('A public directory of community groups.') . '</h2>';
      break;
      
    case 'branding_header':
      $output .= '<div id="branding-header"></div>';
      break;
      
    case 'branding_footer':
      $output .= '<div id="branding-footer"></div>';
      break;
      
     case 'facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $output .= '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;     

    case 'search':        
        global $base_url;
        $output .= '<div id="search-links" style="width:420px">';
        $output .= '<div id="search-places" class="form-input">';
        $output .= '<h3>' . t('Find your block watch captain') . '</h3>';
        $output .= '<input placeholder="Enter your address or zipcode here." size=50 class="form-item" />';
        $output .= '<input type="image" src="' . base_path() . path_to_theme() . '/images/search_icon-50.png" id="search-links-submit" class="search_btn" value="Search" alt="Search">';
        $output .= '</div>';
        $output .= '</div>';
      break;
      
    case 'add_data':
        $output .= "<div class=\"add-container\"><div class=\"message\">Are you a block watch captain?</div><div class=\"add-group\"><a href=\"/node/add/community-group" . $add_variables . "\">Add</a></div></div>";
      break;
      
      case 'map':
        $output .= datawiki_group_map_render();
      break;
      
      case 'categories':
        $output .= "";
      break;
      
      case 'list':
        $output .= "";
      break;
      
      case 'home_menu':
/*
        $output .= '<div id="home-menu" class="grid_6 push_10">';
        $output .= '<ul class="menu">';
        $output .= '<li><a href="calendars">' . t('Home/Map') . '</a></li>';
        $output .= '<li><a href="list/all/block-watch">' . t('List') . '</a></li>';
        $output .= '<li><a href="/node/add/community-group' . $add_variables . '">' . t('Add') . '</a></li>';
        $output .= '</ul>';
        $output .= '</div>';          
*/      
      break;
      
      case 'map_menu':
        $output .= '';
      break;
      
      case 'list_menu':
        $output .= "";
      break;
      
      case 'topics_menu':
        $output .= "";
      break;
      
      case 'about_block':
        $output .= "<h3>What is a Block Watch Captain?</h3>";
        $output .= "<p>Block Watch is a national program that is based
        on the principle that neighbors working together are the 
        first and best line of defense against crime.</p>";
        $output .= "<p>Block Watch Captains lead the program at the block-level,
        serving as the eyes and ears for the police department and help
        to organize block parties, street clean-ups and other 
        events and initiatives.</p>";
/*         $output .= "<p>Click <a href=\"/calendars/about\">here</a> to learn more</p>"; */
      break;
  }
  return $output;
}