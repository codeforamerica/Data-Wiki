<?php
/**
 * Stub functions, orginally taken from Fusion Core.
 */

/**
 * HTML preprocessing
 */
function citygroups_preprocess_html(&$vars) {
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
function  citygroups_preprocess_maintenance_page(&$vars) {
  if (class_exists('Database', FALSE)) {
    citygroups_preprocess_html($vars);  // set html vars (html.tpl.php is in maintenance-page.tpl.php)
    citygroups_preprocess_page($vars);  // set page vars
  }
}

/**
 * Page preprocessing
 */
function citygroups_preprocess_page(&$vars) {

  //$fbconnect = theme_fbconnect_login_button($vars);
  //dpm($fbconnect);

  // Create variables from theme settings (set in .info file)
  $vars['sitename'] = theme_get_setting('sitename');
  
  $vars['site_slogan'] = '<h3>' . theme_get_setting('site_slogan') .'</h3>';
  if(empty($vars['site_slogan'])) {
    $vars['site_slogan'] = '<h3>' . variable_get('site_slogan') .'</h3>';
  }
  
  $vars['logo_image_link'] = theme_get_setting('logo_image_link');
  $vars['logo'] = '<a href="/"><img src="/' . drupal_get_path('theme', 'citygroups') . '/' . $vars['logo_image_link'] . '" /></a>';

  // If sidebars are empty, make main region full width.
  if(count($vars['page']['sidebar_first']) == 0 && count($vars['page']['sidebar_second']) == 0) {
    $vars['main_region_width'] = 'grid_16';
  }
  else {
    $vars['main_region_width'] = 'grid_11';
  }

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
  $vars['submit_btn'] = url(drupal_get_path('theme', 'citygroups') . '/images/submit-large-overlay.gif');
  
  // Hardcoded site names
  switch ($_SERVER['HTTP_HOST']) {
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
function citygroups_preprocess_region(&$vars) {
  // Set region variables
  $vars['region_style'] = $vars['fluid_width'] = '';
  $vars['region_name'] = str_replace('_', '-', $vars['region']);
  $vars['classes_array'][] = $vars['region_name'];
}


/**
 * Block preprocessing
 */
function citygroups_preprocess_block(&$vars) {
  global $theme_info, $user;

  // Exit if block is outside a defined region
  if (!in_array($vars['block']->region, array_keys($theme_info->info['regions']))) {
    return;
  }
}


/**
 * Node preprocessing
 */
function citygroups_preprocess_node(&$vars) {
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
function citygroups_node_location(&$vars) {
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

function citygroups_node_share(&$vars) {
  citygroups_fb_like($vars);
  $output = '';
  $output .= '<div class="node-share">';
  $output .= '<div class="facebook">' . $vars['fb_like'] . '</div>';
  $output .= '</div>';
  return $output;
}

function citygroups_fb_like(&$vars) {
  
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
 * Comment preprocessing
 */
function citygroups_preprocess_comment(&$vars) {
  static $comment_odd = TRUE;
 // Comment is odd or even

  // Add to array of handy comment classes
  $vars['classes_array'][] = $comment_odd ? 'odd' : 'even';
  $comment_odd = !$comment_odd;
}

/**
 * Returns HTML for an element's children fieldsets as vertical tabs.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties and children of the
 *     fieldset. Properties used: #children.
 *
 * @ingroup themeable
 */
function citygroups_vertical_tabs($variables) {
  $element = $variables['element'];
  // Add required JavaScript and Stylesheet.
  drupal_add_library('system', 'drupal.vertical-tabs');

  $output = '<h2 class="element-invisible">' . t('Vertical Tabs') . '</h2>';
  $output .= '<div class="vertical-tabs-panes grid_12">' . $element['#children'] . '</div>';
  return $output;
}

/**
 * Theme menu links.
 * @TODO This should go in module because it themes sections for data collection projects.
 */
function citygroups_menu_link($variables) {
  $element = $variables['element'];

  $sub_menu = '';

  // Get section values if set.
  global $section;
  
  if(empty($section)) {
    $section = '';
  }
  if(!empty($_GET['section']) && ($section == '')) {
    $section = $_GET['section'];
    $section_path = '/' . $section;
  }

  $element['#attributes']['class'][] = '';

  // Rewrite certain menu links to point to section.
  if (($element['#theme'] == 'menu_link__menu_citygroups_menu') && ($section !== '')) {
    switch ($element['#href']) {
      case '<front>':
        $element['#href'] = $section;
        $element['#localized_options']['attributes']['title'] = t('Home');
        $element['#attributes']['class'][] = 'home';
        $element['#localized_options']['query']['section'] = $section;
        break;
      case 'map':
        $element['#href'] = $section_path . $element['#href'];
        $element['#localized_options']['attributes']['title'] = t('Map View');
        $element['#attributes']['class'][] = 'map-view';
        $element['#localized_options']['query']['section'] = $section;
        break;
      case 'list':
        $element['#href'] = $section_path . $element['#href'];
        $element['#localized_options']['attributes']['title'] = t('List View');
        $element['#attributes']['class'][] = 'list-view';
        $element['#localized_options']['query']['section'] = $section;
        break;
      case 'categories':
        $element['#href'] = $section_path. $element['#href'];
        $element['#localized_options']['attributes']['title'] = t('Categories');
        $element['#attributes']['class'][] = 'categories';
        $element['#localized_options']['query']['section'] = $section;
        break;
      case 'node/add/community-group':
       // $element['#href'] = $element['#href'] . urlencode('?') . "section=" . $section ;
      //@TODO look up syntax 
       //$element['#attributes']['section'] = $section;
        $element['#localized_options']['attributes']['title'] = t('Add New');
        $element['#attributes']['class'][] = 'add-new';
        $element['#localized_options']['query']['section'] = $section;
        break;
    }
  }
  

  $element['#attributes']['class'][] .= 'menu-' . $element['#original_link']['mlid'];

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
