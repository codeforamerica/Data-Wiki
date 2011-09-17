<?php
/**
 * @file
 * Libraries module integration.
 */

/**
 * Include additional files.
 */
foreach (_mobile_codes_get_libraries() as $library => $file) {
  require_once $file;
}

/**
 *
 */
function _mobile_codes_get_libraries() {
  static $libraries = array();

  if (empty($libraries)) {
    foreach (libraries_get_libraries() as $library => $path) {
      if (file_exists($file = drupal_get_path('module', 'mobile_codes') . "/includes/libraries.{$library}.inc")) {
        $libraries[$library] = $file;
      }
    }
  }

  return $libraries;
}

/**
 * Implements hook_mobile_codes_menu_alter() on behalf of libraries.inc.
 */
function libraries_mobile_codes_menu_alter(&$items) {
  foreach (_mobile_codes_get_libraries() as $library => $file) {
    if (function_exists($function = "mobile_codes_libraries_{$library}_menu_alter")) {
      $function($items);
    }
  }
}

/**
 * Implements hook_mobile_codes_default_mobile_codes_provider_alter() on behalf of libraries.inc.
 */
function libraries_mobile_codes_default_mobile_codes_provider_alter(&$export) {
  foreach (_mobile_codes_get_libraries() as $library => $file) {
    if (function_exists($function = "mobile_codes_libraries_{$library}_default_mobile_codes_provider_alter")) {
      $function($export);
    }
  }
}
