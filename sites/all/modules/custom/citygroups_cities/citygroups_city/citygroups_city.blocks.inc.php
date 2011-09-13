<?php

/**
 * Implements hook_block_info().
 */
function citygroups_city_block_info() {
  $blocks['citygroups_city_welcome'] = array(
    'info' => t('Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_branding_header'] = array(
    'info' => t('Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_branding_footer'] = array(
    'info' => t('Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_site_slogan'] = array(
    'info' => t('Site Slogan'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_facebook_like'] = array(
    'info' => t('Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_home_content'] = array(
    'info' => t('Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_about'] = array(
    'info' => t('About'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
/*
  $blocks['citygroups_city_map'] = array(
    'info' => t('Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
*/
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function citygroups_city_block_view($delta = '') {
  switch ($delta) {
    case 'citygroups_city_welcome':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('welcome');
      break;
      
    case 'citygroups_city_branding_header':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('branding_header');
      break;
      
    case 'citygroups_city_branding_footer':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('branding_footer');
      break;     

    case 'citygroups_city_site_slogan':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('site_slogan');
      break;

    case 'citygroups_city_about_citygroups':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('about_citygroups');
      break;         

    case 'citygroups_city_facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $block['subject'] = '';
      $block['content'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;

    case 'citygroups_city_home_content':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('home_content');
      break;

    case 'citygroups_city_about':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('about');
      break; 

  }
  return $block;
}

/**
 * Block content for main CityGroups content.
 */
function citygroups_city_contents($type) {
  $output = '';
  
  switch ($type) {
  
    // You will need to reconfigure the context in order for custom block to appear.
    case 'welcome':
        $output .= "";
      break;

    case 'site_slogan':
        $output .= "";
      break;
      
    case 'branding_header':
        $output .= "";
      break;
      
    case 'branding_footer':
        $output .= "";
      break;
      
      case 'home_content':
        $output .= "";
      break;  

      case 'about':
        $output .= "";
      break;      

  }
  return $output;
}