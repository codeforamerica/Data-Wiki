<?php
/**
 * @file
 * datawiki_context.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function datawiki_context_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-citygroups-menu
  $menus['menu-citygroups-menu'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'title' => 'CityGroups Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CityGroups Menu');


  return $menus;
}
