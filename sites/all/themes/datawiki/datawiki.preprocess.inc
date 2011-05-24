<?php
/**
 * Stub functions, orginally taken from Fusion Core.
 */

/**
 * HTML preprocessing
 */
function datawiki_preprocess_html(&$vars) {
  global $theme_key, $user;

  // Add to array of helpful body classes
  if (isset($vars['node'])) {
    $vars['classes_array'][] = ($vars['node']) ? 'full-node' : '';                                            // Full node
    $vars['classes_array'][] = (($vars['node']->type == 'forum') || (arg(0) == 'forum')) ? 'forum' : '';      // Forum page
  }
  else {
    $vars['classes_array'][] = (arg(0) == 'forum') ? 'forum' : '';                                            // Forum page
  }

  // Add a unique page id
  $vars['body_id'] = 'pid-' . strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', drupal_get_path_alias($_GET['q'])));
}

/**
 * Maintenance page preprocessing
 */
function  datawiki_preprocess_maintenance_page(&$vars) {
  if (class_exists('Database', FALSE)) {
    datawiki_preprocess_html($vars);  // set html vars (html.tpl.php is in maintenance-page.tpl.php)
    datawiki_preprocess_page($vars);  // set page vars
  }
}

/**
 * Page preprocessing
 */
function datawiki_preprocess_page(&$vars) {

  // If sidebars are empty, make main region full width.
  if(count($vars['page']['sidebar_first']) == 0 && count($vars['page']['sidebar_second']) == 0) {
    $vars['main_region_width'] = 'grid_16';
  }
  else {
    $vars['main_region_width'] = 'grid_11';
  }

  // Create some resource variables
/*
  $vars['logo_image'] = theme('image', array(
    'path' => drupal_get_path('theme', 'et') . '/images/header_logo.gif', 
    )
  );
*/
//  $vars['logo_image_link'] = l($vars['logo_image'], '<front>', array('html' => TRUE));
  
  // Create login link
  $account_text = t('Sign in');
  global $user;
  if ($user->uid > 0) {
    // User is logged in
    $account_text = t('My Account');
  }
  $vars['account_link'] = l($account_text, 'user', array(
    'attributes' => array(
      'id' => 'signin',
    )
  ));
  
  // Temp for wireframing or MVP
  $vars['submit_btn'] = url(drupal_get_path('theme', 'et') . '/images/submit-large-overlay.gif');
  
  // Hardcoded site names
  switch ($_SERVER['HTTP_HOST']) {
    case 'philly.citygroups.org':
      $vars['sub_site_name'] = t('Philadelphia');
      break;
      
    case 'seattle.citygroups.org':
      $vars['sub_site_name'] = t('Seattle');
      break;
      
    case 'bayarea.citygroups.org':
      $vars['sub_site_name'] = t('San Francisco Bay Area');
      break;
      
    case 'staging.citygroups.org':
      $vars['sub_site_name'] = t('Staging');
      break;
      
    default:
      $vars['sub_site_name'] = t('Development');
      break;
  }

  // Remove breadcrumbs if disabled
  if (theme_get_setting('breadcrumb_display') == 0) {
    $vars['breadcrumb'] = '';
  }
}


/**
 * Region preprocessing
 */
function datawiki_preprocess_region(&$vars) {
  // Set region variables
  $vars['region_style'] = $vars['fluid_width'] = '';
  $vars['region_name'] = str_replace('_', '-', $vars['region']);
  $vars['classes_array'][] = $vars['region_name'];
}



/**
 * Block preprocessing
 */
function datawiki_preprocess_block(&$vars) {
  global $theme_info, $user;

  // Exit if block is outside a defined region
  if (!in_array($vars['block']->region, array_keys($theme_info->info['regions']))) {
    return;
  }
}


/**
 * Node preprocessing
 */
function datawiki_preprocess_node(&$vars) {
  // dpm($vars); not working, use this krumo call instead to see the node object.
/*   var_dump(krumo($vars)); */

  // Add to array of handy node classes
  $vars['classes_array'][] = $vars['zebra'];                              // Node is odd or even
  $vars['classes_array'][] = (!$vars['teaser']) ? 'full-node grid_16 alpha' : '';       // Node is teaser or full-node
  
  // Add preprocess functions for all node types.
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars);
  }

/*
  // Node top, bottom & sidebar can't be set with context, unfortunately, until we can figure out
  // how to access blocks set by context. Context seems to override the entire block system...
  // So for now, node regions should only be set in preprocessing
  // functions - to be used for certain fields and the like.*/

  $vars['node_top'] = '';
  $vars['node_bottom'] = '';
  $vars['node_sidebar'] = '';

  // Set margin in grid system for node to flush
  $vars['node_content_width'] = 'alpha';
}

/* Load location data for nodes */
function datawiki_node_location(&$vars) {
  $output = '';
  if(!empty($vars['field_location_text']['und'][0]['value'])) {
    $output .=  t(', ') . $vars['field_location_text']['und'][0]['value'];
  }
  else {
    if(!empty($vars['field_neighborhood']['und'][0]['taxonomy_term']->name)) {
      $output .= t(', ') . $vars['field_neighborhood']['und'][0]['taxonomy_term']->name;
    }
    if(!empty($vars['field_city']['und'][0]['taxonomy_term']->name)) {
      $output .= t(', ') . $vars['field_city']['und'][0]['taxonomy_term']->name;
    }
    if(!empty($vars['field_state']['und'][0]['taxonomy_term']->name)) {
      $output .= t(', ') . $vars['field_state']['und'][0]['taxonomy_term']->name;
    }
  }
  return $output;
}

function datawiki_node_share(&$vars) {
  datawiki_fb_like($vars);
  $output = '';
  $output .= '<div class="node-share">';
  $output .= 'Facebook';
  $output .= '<div class="facebook">' . $vars['fb_like'] . '</div>';
  $output .= '<div class="twitter">Twitter</div>';
  $output .= '<div class="supporters">23</div>';
  $output .= '</div>';
  return $output;
}

function datawiki_fb_like(&$vars) {
  
  // Facebook Like link (TODO: Use module)
  // Make URL, Facebook is not ok with a "localhost" URL.
  $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
  $url .= '://';
  $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
  $url .= $_SERVER['REQUEST_URI'];
  // @TODO replace with block from context.
  $vars['fb_like'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';

}
/**
 * Preprocessing function for node types.
 */
function datawiki_preprocess_node_project(&$vars) {
  // Create content variables for this node type.
  $vars['location'] =  datawiki_node_location($vars);
  $vars['share'] = datawiki_node_share($vars);
}

/**
 * Comment preprocessing
 */
function datawiki_preprocess_comment(&$vars) {
  static $comment_odd = TRUE;
 // Comment is odd or even

  // Add to array of handy comment classes
  $vars['classes_array'][] = $comment_odd ? 'odd' : 'even';
  $comment_odd = !$comment_odd;
}


/**
 * Views preprocessing
 * Add view type class (e.g., node, teaser, list, table)
 */
function datawiki_preprocess_views_view(&$vars) {
  $vars['css_name'] = $vars['css_name'] .' view-style-'. drupal_clean_css_identifier(strtolower($vars['view']->plugin_name));
  // Yes, this is kludgy.
  $term0 = $term1 = $term2 = $vars['search_string'] = '';

  if(!empty($vars['view']->exposed_input['neighborhood'])) {
    $term0 = $vars['view']->exposed_input['neighborhood'];
    if(is_numeric($term0)) {
      $term0 = taxonomy_term_load($term0)->name;
    }
/*
    if(is_array($term0)) {
      $term1 = t('Neighborhood:') . taxonomy_term_load($term0[0])->name;
    }
*/

  }
  if(!empty($vars['view']->exposed_input['category'])) {
    $term1 = $vars['view']->exposed_input['category'];
    if(is_numeric($term1)) {
      $term1 = taxonomy_term_load($term1)->name;
    }
  }
/*

  if(!empty($vars['view']->exposed_input['type_community'])) {
    $term2 = $vars['view']->exposed_input['type_community'];
    if(is_numeric($term2)) {
      $term2 = taxonomy_term_load($term2)->name;
    }
  }
*/

  if(!empty($vars['view']->exposed_input['category']) || !empty($vars['view']->exposed_input['type_community']) || !empty($vars['view']->exposed_input['category'])) {
    $vars['search_string'] = '<div class="search-terms">' . 
      '<h3>' . t('Search terms') . '</h3>' . 
        t('Neighborhood: ') . $term0  . '<br />' .
        t('Category: ') .$term1  . '<br />' .
/*         t('Type of Community: ') .$term2   . '<br />' .  */
      '</div>';
  }
}


/**
 * Search result preprocessing
 */
function datawiki_preprocess_search_result(&$vars) {
  static $search_zebra = 'even';

  $search_zebra = ($search_zebra == 'even') ? 'odd' : 'even';
  $vars['search_zebra'] = $search_zebra;
  $result = $vars['result'];
  $vars['url'] = check_url($result['link']);
  $vars['title'] = check_plain($result['title']);

  // Check for snippet existence. User search does not include snippets.
  $vars['snippet'] = '';
  if (isset($result['snippet']) && theme_get_setting('search_snippet')) {
    $vars['snippet'] = $result['snippet'];
  }

  $info = array();
  if (!empty($result['type']) && theme_get_setting('search_info_type')) {
    $info['type'] = check_plain($result['type']);
  }
  if (!empty($result['user']) && theme_get_setting('search_info_user')) {
    $info['user'] = $result['user'];
  }
  if (!empty($result['date']) && theme_get_setting('search_info_date')) {
    $info['date'] = format_date($result['date'], 'small');
  }
  if (isset($result['extra']) && is_array($result['extra'])) {
    // $info = array_merge($info, $result['extra']);  Drupal bug?  [extra] array not keyed with 'comment' & 'upload'
    if (!empty($result['extra'][0]) && theme_get_setting('search_info_comment')) {
      $info['comment'] = $result['extra'][0];
    }
    if (!empty($result['extra'][1]) && theme_get_setting('search_info_upload')) {
      $info['upload'] = $result['extra'][1];
    }
  }

  // Provide separated and grouped meta information.
  $vars['info_split'] = $info;
  $vars['info'] = implode(' - ', $info);

  // Provide alternate search result template.
  $vars['template_files'][] = 'search-result-'. $vars['type'];
}

