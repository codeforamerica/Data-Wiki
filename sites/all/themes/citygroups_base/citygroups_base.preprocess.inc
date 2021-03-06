<?php
/**
 * Stub functions, orginally taken from Fusion Core.
 */

/**
 * HTML preprocessing
 */
function citygroups_base_preprocess_html(&$vars) {
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
function  citygroups_base_preprocess_maintenance_page(&$vars) {
  if (class_exists('Database', FALSE)) {
    citygroups_base_preprocess_html($vars);  // set html vars (html.tpl.php is in maintenance-page.tpl.php)
    citygroups_base_preprocess_page($vars);  // set page vars
  }
}

/**
 * Page preprocessing
 */
function citygroups_base_preprocess_page(&$vars) {

  //$fbconnect = theme_fbconnect_login_button($vars);
  //dpm($fbconnect);

  // Create variables from theme settings (set in .info file)
  $vars['sitename'] = theme_get_setting('sitename');
  
  $vars['site_slogan'] = '<h3>' . theme_get_setting('site_slogan') .'</h3>';
  if(empty($vars['site_slogan'])) {
    $vars['site_slogan'] = '<h3>' . variable_get('site_slogan') .'</h3>';
  }
  
  $vars['logo_image_link'] = theme_get_setting('logo_image_link');
  $vars['logo'] = '<a href="/"><img src="/' . drupal_get_path('theme', 'citygroups_base') . '/' . $vars['logo_image_link'] . '" /></a>';

  // If sidebars are empty, make main region full width.
  if(count($vars['page']['sidebar_first']) == 0 && count($vars['page']['sidebar_second']) == 0) {
    $vars['main_region_width'] = 'grid_16 alpha omega';
  }
  else {
    $vars['main_region_width'] = 'grid_11 alpha';
  }
  
  $vars['number_groups'] = views_embed_view('number_groups', 'default');



  // Create login link
  $account_text = t('Sign in');
  global $user;
  if ($user->uid > 0) {
    // User is logged in
    $account_text = t('My Account');
  }
  
  $vars['account_link'] = '';
  
  if ($user->uid > 0) {
  $vars['account_link'] .= l('Dashboard', 'admin/dashboard', array(
      'attributes' => array(
        'id' => 'dashboard',
      )
    )) . ' | ' ;
  }
  
  
  $vars['account_link'] .= l($account_text, 'user', array(
    'attributes' => array(
      'id' => 'signin',
    )
  ));
  
  if ($user->uid > 0) {
    // User is logged in
  $vars['account_link'] .= ' | ' . 
    l('Logout', 'user/logout', array(
      'attributes' => array(
        'id' => 'logout',
      )
    ));
  }
  
  // Temp for wireframing or MVP
  $vars['submit_btn'] = url(drupal_get_path('theme', 'citygroups_base') . '/images/submit-large-overlay.gif');
  
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
function citygroups_base_preprocess_region(&$vars) {
  // Set region variables
  $vars['region_style'] = $vars['fluid_width'] = '';
  $vars['region_name'] = str_replace('_', '-', $vars['region']);
  $vars['classes_array'][] = $vars['region_name'];
}


/**
 * Block preprocessing
 */
function citygroups_base_preprocess_block(&$vars) {
  global $theme_info, $user;

  // Exit if block is outside a defined region
  if (!in_array($vars['block']->region, array_keys($theme_info->info['regions']))) {
    return;
  }
}


/**
 * Node preprocessing
 */
function citygroups_base_preprocess_node(&$vars) {
  // dpm($vars); not working, use this krumo call instead to see the node object.

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

function citygroups_base_preprocess_node_community_group(&$vars) {
  // Configure links.
  switch ($vars['view_mode']) {
    case 'full':
      $vars['content']['links']['#suffix'] = citygroups_base_node_share($vars, 'full');
      break;
    case 'search_result':
    case 'teaser':
    case 'search_index':
      $vars['content']['links']['#suffix'] = citygroups_base_node_share($vars, 'teaser');
    default:
      break;  
  }

  // Reorder flags.
  citygroups_base_reorder_community_group_flags($vars);

  /*
    if ($url = mobile_codes_process_url($variables['data'], $variables['attributes'])) {
      if ($path = mobile_codes_generate($url)) {
        return theme('image', array('path' => $path, 'alt' => $variables['image_alt'], 'title' => $variables['image_title'], 'attributes' => $variables['image_attributes'], 'getsize' => $variables['image_getsize']));
      }
    }
  */
}

function citygroups_base_reorder_community_group_flags(&$vars) {

  $flags = $vars['content']['links']['flag']['#links'];
  $new_flags = array(
    'flag-watch' => $flags['flag-watch'],
    'flag-recommend' => $flags['flag-recommend'],
    'flag-inactive' => $flags['flag-inactive'],
    'flag-duplicate' => $flags['flag-duplicate'],
    'flag-inappropriate' => $flags['flag-inappropriate'],
  );
  unset($vars['content']['links']['flag']['#links']);
  $vars['content']['links']['flag']['#links'] = $new_flags;

}

/* Load location data for nodes */
function citygroups_base_node_location(&$vars) {
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

function citygroups_base_node_share(&$vars, $view_mode) {

  global $base_url;
  $path = $base_url . $vars['node_url'];
  
  $data = $vars['field_description']['und'][0]['value'];
    // Trim Data if over maximum number of characters.
  $max_chars = 100;
  if(strlen($data) > $max_chars) {
    $data = strip_tags($data);
    $data = substr ($data, 0, $max_chars) . ' ...';
  }
  
  

  $qrcode = citygroups_qrcode($path, 'medium', $vars['title'], $data);
  
  $twitter_full =  $vars['title'] . ' ' . $path .
  '<a href="https://twitter.com/share" class="twitter-share-button" data-url="' . $path . '" data-text="' .
      $vars['title'] .
      '" data-count="horizontal">Tweet</a><script type="text/javascript" src="//platform.twitter.com/widgets.js"></script>';
      
  $twitter_teaser = $vars['title'] . ' ' . $path;
  
  citygroups_base_fb_like($vars);
  
  $facebook_full = '<div class="facebook">' . $vars['fb_like'] . '</div>';
  
  $email = 'Did know about this group? ' . $vars['title'] . ' ' . $path ;

  global $user;
 
  if (user_is_logged_in()) {
    $edit = '<div class="edit">' . l('Edit', $base_url . '/node/' . $vars['nid'] . '/edit') . ' information about this group.</div>';
  }
  else {
    $edit = '<div class="edit">Sign in to ' . l('edit',  $base_url . '/user/login',  array('query' => array('destination' => 'node/' . $vars['nid'] . '/edit'))) . ' information about this group.</div>';
  }
  
  $output = '';
    
  switch ($vars['view_mode']) {
    case 'full':
      $twitter = $twitter_full;
      $facebook = $facebook_full;
      break;
    default:   
    case 'search_result':
    case 'teaser':
    case 'search_index':

      $twitter = $twitter_teaser;
      $facebook = '';

      $share_link = array( 
        '#theme' => 'links__node__flag',
        '#attributes' => array(
          'class' => array('links', 'inline'),
        ),
      );

      $edit_link = array( 
        '#theme' => 'links__node__node',
        '#attributes' => array(
          'class' => array('links', 'inline'),
        ),
      );
      break;  
  }

   $edit_link['#links']  =  array(
        'edit' => array(
          'title' => '
            <div class="edit">'
            . $edit . '
            </div>
          ',
          'html' => TRUE,            
        ),
  );

  $share_link['#links']  =  array(
        'twitter' => array(
          'title' => '
          <div class="flag-wrapper twitter">
          <div title="" class="flag flag-action flag-link-toggle" rel="nofollow">
          Twitter<span class="flag-message">' . $twitter . '</span>
          </div>
          </div>
          ',
          'html' => TRUE,            
        ),
        'facebook' => array(
          'title' => '
          <div class="flag-wrapper facebook">
          <div title="" class="flag flag-action flag-link-toggle" rel="nofollow">
          Facebook<span class="flag-message">' . $facebook . '</span>
          </div>
          </div>
          ',
          'html' => TRUE,            
        ),
        'email' => array(
          'title' => '
          <div class="flag-wrapper email">
          <div title="" class="flag flag-action flag-link-toggle" rel="nofollow">
          Email<span class="flag-message">' . $email . '</span>
          </div>
          </div>              
          ',
          'html' => TRUE,            
        ),
        'qrcode' => array(
          'title' => '
          <div class="flag-wrapper qrcode">
          <div title="" class="flag flag-action flag-link-toggle" rel="nofollow">
          QR Code<span class="flag-message">' . $qrcode . '</span>
          </div>
          </div>
          ',
          'html' => TRUE,            
        ),
  );

  $vars['content']['links']['share'] = $share_link;
  $vars['content']['links']['edit'] = $edit_link;
  

  return $output;
}


function citygroups_base_fb_like(&$vars, $url) {

  if(isset($url)) {
    $path = $url;
  }

  $fb_script = 
  '
     <div id="fb-root"></div>
      <script>(function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) {return;}
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/en_US/all.js#appId=249561838420518&xfbml=1";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, \'script\', \'facebook-jssdk\'));</script>
      
      <div class="fb-like" data-href="' . $base_url . '" data-send="true" data-width="450" data-show-faces="true"></div>

  ';


  $vars['fb_like'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';

}

/**
 * Comment preprocessing
 */
function citygroups_base_preprocess_comment(&$vars) {
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
function citygroups_base_vertical_tabs($variables) {
  $element = $variables['element'];
  // Add required JavaScript and Stylesheet.
  drupal_add_library('system', 'drupal.vertical-tabs');

  $output = '<h2 class="element-invisible">' . t('Vertical Tabs') . '</h2>';
  $output .= '<div class="vertical-tabs-panes grid_8">' . $element['#children'] . '</div>';
  return $output;
}

/**
 * Theme menu links.
 * @TODO This should go in module because it themes sections for data collection projects.
 */
function citygroups_base_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  // Get section values if set.
  global $section;
  
  if(empty($section)) {
    $section = '';
  }
  if(!empty($_GET['section']) && ($section == '')) {
    $section = $_GET['section'];
  }

  $element['#attributes']['class'][] = '';

  // Rewrite certain menu links to point to section.
  if (($element['#theme'] == 'menu_link__citygroups_header')) {
    if ($section == '') {
        $section_path = '';
    }
    else {
        $section_path = $section . '/';
    }
    
    switch ($element['#href']) {
      case '<front>':
      case 'home':
        $element['#localized_options']['attributes']['title'] = t('Home');
        $element['#attributes']['class'][] = 'home';
        if($section != '') {
          $element['#href'] = $section;
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'map':
        $element['#localized_options']['attributes']['title'] = t('Map View');
        $element['#attributes']['class'][] = 'map-view';
        if($section != '') {
          $element['#href'] = $section_path . $element['#href'];
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'list':
        $element['#localized_options']['attributes']['title'] = t('List View');
        $element['#attributes']['class'][] = 'list-view';
        if($section != '') {
          $element['#href'] = $section_path . $element['#href'];
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'categories':
        $element['#localized_options']['attributes']['title'] = t('Categories');
        $element['#attributes']['class'][] = 'categories';
        if($section != '') {
          $element['#href'] = $section_path . $element['#href'];
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'node/add/community-group':
        $element['#localized_options']['attributes']['title'] = t('Add New');
        $element['#attributes']['class'][] = 'add-new';
        if($section != '') {
          $element['#href'] = $element['#href'];
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
    }
  }
  
  // Rewrite certain menu links to point to section.
  if (($element['#theme'] == 'menu_link__menu_postscript_menu')) {
    if ($section == '') {
        $section_path = '';
    }
    else {
        $section_path = $section . '/';
    }
    
    /* 
    
    We are basing these off of the title because the defaultcontent
    module can't store path aliases - and the node ids will be different on 
    all systems. The admin will need to generate pages by hand anyways
    when making this module, so we won't be too fancy about it.
    
    Basically, we can override the postscript menu - linking to 
    specific content for this data collection project.
    
    */
    switch ($element['#title']) {
      case 'About the Groups':
        $element['#localized_options']['attributes']['title'] = t('About the Groups');
        $element['#attributes']['class'][] = 'about';
        if($section != '') {
          $element['#href'] =  $section_path . 'about';
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'Get Involved':
        $element['#localized_options']['attributes']['title'] = t('Get Involved');
        $element['#attributes']['class'][] = 'get-involved';
        if($section != '') {
          $element['#href'] = $section_path .  'get-involved';
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'Contact':
        $element['#localized_options']['attributes']['title'] = t('Contact');
        $element['#attributes']['class'][] = 'contact';
        if($section != '') {
          $element['#href'] = $section_path . $element['#href'];
          $element['#localized_options']['query']['section'] = $section;
        }
        break;
      case 'API':
        $element['#localized_options']['attributes']['title'] = t('API');
        $element['#attributes']['class'][] = 'api';
        if($section != '') {
          $element['#href'] = $section_path  . 'api';;
          $element['#localized_options']['query']['section'] = $section;
        }
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


function citygroups_base_preprocess_flag(&$vars) {

}
