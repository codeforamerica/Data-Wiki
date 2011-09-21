<?php
/**
 * @file
 * sea_blockwatch_context.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function sea_blockwatch_context_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-Block-Watch-menu
  $menus['menu-Block-Watch-menu'] = array(
    'menu_name' => 'menu-Block-Watch-menu',
    'title' => 'Block Watch Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Block Watch Menu');


  return $menus;
}
