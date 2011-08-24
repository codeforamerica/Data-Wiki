<?php
/**
 * @file
 * datawiki_content.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function datawiki_content_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer Menu',
    'description' => '',
  );
  // Exported menu: menu-postscript-menu
  $menus['menu-postscript-menu'] = array(
    'menu_name' => 'menu-postscript-menu',
    'title' => 'Postscript Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu');
  t('Postscript Menu');


  return $menus;
}
