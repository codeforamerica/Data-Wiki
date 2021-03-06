<?php
/**
 * @file
 *
 * Handles all of the general hooks
 *
 * We are grouping hooks that we expect to run on cache clears
 */

/**
 * Implements hook_menu
 */
function _apps_menu() {
  $menu = array();
  apps_include('manifest');
  $servers = apps_servers();
  $APPSTORE_BASEPATH = APPSTORE_BASEPATH;
  //These are items we expoect in most of the pages
  $common = array(
    'access arguments' => array('administer apps'),
    'file' => 'apps.pages.inc',
  );
  //We are going to create hooks for each server. 
  //We are doing this instead of using % so it is cleaner when there are no servers
  foreach ($servers as $server) {
    $menu["$APPSTORE_BASEPATH/{$server['name']}"] =  array(
      'title' => "{$server['title']} Apps",
      'page callback' => 'apps_install_page',
      'page arguments' => array($server['name']),
      'description' => $server['description'],
    ) + $common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/install"] = array(
      'title' => "All Apps",
      'weight' => 1,
      'type'=> MENU_DEFAULT_LOCAL_TASK,
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}"];
    $menu["$APPSTORE_BASEPATH/{$server['name']}/manage"] = array(
      'title' => "Installed Apps",
      'page callback' => 'apps_manage_page',
      'page arguments' => array($server['name']),
      'weight' => 2,
      'type'=> MENU_LOCAL_TASK,
    ) + $common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/update"] = array(
      'title' => "Available Updates",
      'page callback' => 'apps_update_page',
      'page arguments' => array($server['name']),
      'weight' => 3,
      'type'=> MENU_LOCAL_TASK,
    ) + $common;

    //app actions
    $app_common = array(
      'access callback' => 'apps_tunnel',
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], FALSE, APPSTORE_BASEPATH_DEPTH + 3),
    ) + $common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/install"] = array(
      'title' => "Install App",
      'page callback' => 'apps_app_install',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'install', APPSTORE_BASEPATH_DEPTH + 3),
      'type'=> MENU_LOCAL_ACTION,
    ) + $app_common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/disable"] = array(
      'title' => "Disable App",
      'page callback' => 'apps_app_disable',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'disable', APPSTORE_BASEPATH_DEPTH + 3),
      'type'=> MENU_LOCAL_ACTION,
    ) + $app_common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/enable"] = array(
      'title' => "Enable App",
      'page callback' => 'apps_app_enable',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'enable', APPSTORE_BASEPATH_DEPTH + 3),
      'type'=> MENU_LOCAL_ACTION,
    ) + $app_common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/uninstall"] = array(
      'title' => "Uninstall App",
      'page callback' => 'apps_app_uninstall',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'uninstall', APPSTORE_BASEPATH_DEPTH + 3),
      'type'=> MENU_LOCAL_ACTION,
    ) + $app_common;

    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%"] = array(
      'title callback' => 'apps_app_title',
      'title arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'page callback' => 'apps_app_details_page',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'file' => 'apps.pages.inc',
    ) + $app_common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/details"] = array(
      'title' => 'Details',
      'title callback' => FALSE,
      'title arguments' => FALSE,
      'weight' => -2,
      'type'=> MENU_DEFAULT_LOCAL_TASK,
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%"];
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/configure"] =  array(
      'title' => 'Configure',
      'page callback' => 'apps_app_config_page',
      'page arguments' => array($server['name'], APPSTORE_BASEPATH_DEPTH + 3),
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'configure', APPSTORE_BASEPATH_DEPTH + 3),
      'weight' => -1,
      'type'=> MENU_LOCAL_TASK,
    ) + $app_common;
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/configure-action"] =  array(
      'page callback' => 'apps_app_config_action_redirect',
      'title' => 'Configure App',
      'access arguments' => array('pages', '_apps_app_access', 'administer apps', $server['name'], 'configure-action', APPSTORE_BASEPATH_DEPTH + 3),
      'type'=> MENU_LOCAL_ACTION,
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/configure"];

    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/server-install"] =  array(
      'type'=> MENU_LOCAL_TASK,
      'page callback' => 'drupal_goto',
      'page arguments' => array("$APPSTORE_BASEPATH/{$server['name']}/install"),
      'options' => array('attributes'=>array('style'=>"border-right:4px #aaa solid", 'class'=>array('bob'))),
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}/install"];
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/server-manage"] =  array(
      'type'=> MENU_LOCAL_TASK,
      'page callback' => 'drupal_goto',
      'page arguments' => array("$APPSTORE_BASEPATH/{$server['name']}/manage"),
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}/manage"];
    $menu["$APPSTORE_BASEPATH/{$server['name']}/app/%/server-update"] =  array(
      'type'=> MENU_LOCAL_TASK,
      'page callback' => 'drupal_goto',
      'page arguments' => array("$APPSTORE_BASEPATH/{$server['name']}/update"),
    ) + $menu["$APPSTORE_BASEPATH/{$server['name']}/update"];
  }
  

  // If we have create servers lets point the base link to the first one
  // TODO: Create Parent Page if there is more then one server
  if(!empty($menu)) {
    if (sizeof($servers) == 1) {
      $server = array_pop($servers);
      $menu["$APPSTORE_BASEPATH"] = array(
        'page callback' => 'drupal_goto',
        'title' => 'Apps',
        'description' => t('Install and Manage Apps'),
        'page arguments' => array("$APPSTORE_BASEPATH/{$server['name']}"),
        'access arguments' => array('administer apps'),
        'weight' => -10,
        'type'=> MENU_NORMAL_ITEM,
      );
    }
    else {
      $menu["$APPSTORE_BASEPATH"] = array(
        'page callback' => 'apps_market_page',
        'title' => 'Apps',
        'description' => t('Install and Manage Apps'),
        'weight' => -10,
        'type'=> MENU_NORMAL_ITEM,
      ) + $common;
    }
  }
  return $menu;
  
}

/**
 * Implements hook_theme
 */
function _apps_theme()  { 
  $common = array(
      'file' => 'apps.theme.inc',
      'path' => drupal_get_path('module', 'apps') . '/theme',
  );
  $theme = array(
    'apps_install_page' => array(
      'render element' => 'content',
      'template' => 'apps-install-page',
    ) + $common,
    'apps_manage_page' => array(
      'render element' => 'content',
      'template' => 'apps-manage-page',
    ) + $common,
    'apps_update_page' => array(
      'render element' => 'content',
      'template' => 'apps-update-page',
    ) + $common,
    'apps_list' => array(
      'render element' => 'apps',
    ) + $common,
    'apps_app_teaser' => array(
      'render element' => 'app',
      'template' => 'apps-app-teaser',
    ) + $common,
    'apps_app_page' => array(
      'render element' => 'app',
      'template' => 'apps-app-page',
    ) + $common,
    'apps_app_featured' => array(
      'render element' => 'app',
      'template' => 'apps-app-featured',
    ) + $common,
  );
  return $theme;
}

/**
 * Implementation of hook_image_default_styles().
 */
function _apps_image_default_styles() {
  $styles = array();

  // Exported image style: apps_logo
  $styles['apps_logo'] = array(
    'name' => 'apps_logo',
    'effects' => array(
      '1' => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '100',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
  );
  
  // Exported image style: apps_logo
  $styles['apps_logo_small'] = array(
    'name' => 'apps_logo',
    'effects' => array(
      '1' => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '60',
          'height' => '60',
        ),
        'weight' => '1',
      ),
    ),
  );
  

  // Exported image style: apps_screenshot
  $styles['apps_screenshot'] = array(
    'name' => 'apps_screenshot',
    'effects' => array(
      '2' => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '590',
          'height' => '370',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: apps_featured_screenshot
  $styles['apps_featured_screenshot'] = array(
    'name' => 'apps_featured_screenshot',
    'effects' => array(
      '2' => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '548',
          'height' => '265',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_permission
 */
function _apps_permission() {
  return array(
    'administer apps' => array(
      'title' => t('Administer the App Store'),
      'description' => t('Install and Manage Apps'),
      'restrict access' => TRUE,
    )
  );
}

