<?php

/**
 * Implements hook_block_info().
 */
function sea_blockwatch_block_info() {
  $blocks['sea_blockwatch_welcome'] = array(
    'info' => t('Seattle Blockwatch Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_branding_header'] = array(
    'info' => t('Seattle Blockwatch Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_branding_footer'] = array(
    'info' => t('Seattle Blockwatch Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_facebook_like'] = array(
    'info' => t('Seattle Blockwatch Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_add_data'] = array(
    'info' => t('Seattle Blockwatch Add Data'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_search'] = array(
    'info' => t('Seattle Blockwatch Search'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_site_tagline'] = array(
    'info' => t('Seattle Blockwatch Site Tagline'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_map'] = array(
    'info' => t('Seattle Blockwatch Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_categories'] = array(
    'info' => t('Seattle Blockwatch Categories'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_list'] = array(
    'info' => t('Seattle Blockwatch List'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_home_menu'] = array(
    'info' => t('Seattle Blockwatch Home Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_topics_menu'] = array(
    'info' => t('Seattle Blockwatch Categories Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_map_menu'] = array(
    'info' => t('Seattle Blockwatch Map Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_list_menu'] = array(
    'info' => t('Seattle Blockwatch List Menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sea_blockwatch_about_block'] = array(
    'info' => t('Seattle Blockwatch About Block'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function sea_blockwatch_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'sea_blockwatch_welcome':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('welcome');
      break;
      
    case 'sea_blockwatch_branding_header':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('branding_header');
      break;
      
    case 'sea_blockwatch_branding_footer':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('branding_footer');
      break;     
      
    case 'sea_blockwatch_facebook_like':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('facebook_like');
     break;

    case 'sea_blockwatch_search':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('search');
      break;

    case 'sea_blockwatch_add_data':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('add_data');
      break;

    case 'sea_blockwatch_site_tagline':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('site_tagline');
      break;
      
    case 'sea_blockwatch_map':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('map');
      break;
    
    case 'sea_blockwatch_categories':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('categories');
      break;
    
    case 'sea_blockwatch_list':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('list');
      break;
      
    case 'sea_blockwatch_home_menu':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('home_menu');
      break;
    
    case 'sea_blockwatch_topics_menu':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('topics_menu');
      break;
      
    case 'sea_blockwatch_list_menu':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('list_menu');
      break; 

    case 'sea_blockwatch_map_menu':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('map_menu');
      break;
       
    case 'sea_blockwatch_about_block':
      $block['subject'] = '';
      $block['content'] = sea_blockwatch_contents('about_block');
      break;
  }
  return $block;
}

/**
 * Block placeholder content
 */
function sea_blockwatch_contents($type) {
  $output = '';

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
        $output .= '<div id="search-links">';
        $output .= '<div id="search-places" class="form-input">' . t('Find your block watch captain');
        $output .= '<input placeholder="Enter your address here." />';
        $output .= '</div>';
        $output .= '</div>';
      break;
      
    case 'add_data':
        $output .= "<div class=\"add-group\">Are you a block watch captain? <a href=\"#\">Add</a></div>";
      break;
      
      case 'map':
        $output .= "<div id=\"map\">Map</div>";
      break;
      
      case 'categories':
        $output .= "<div id=\"topics\">Topics</div>";
      break;
      
      case 'list':
        $output .= "<div id=\"list\">List</div>";
      break;
      
      case 'home_menu':
        $output .= '<div id="map-links">';
        $output .= '<ul>';
        $output .= '<li><a href="blockwatch/about">' . t('About') . '</a></li>';
        $output .= '<li><a href="blockwatch/map">' . t('Map') . '</a></li>';
        $output .= '<li><a href="blockwatch/list">' . t('List') . '</a></li>';
        $output .= '<li><a href="blockwatch/add">' . t('Add Block Watch') . '</a></li>';
        $output .= '<li><a href="blockwatch/upload">' . t('Upload Data') . '</a></li>';
        $output .= '</ul>';
        $output .= '</div>';                
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
        $output .= "<p>Click <a href=\"/blockwatch/about\">here</a> to learn more</p>";
      break;
  }
  return $output;
}