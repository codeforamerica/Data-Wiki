<?php
/**
 * @file
 * sfo_food_context.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function sfo_food_context_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-Block-Watch-menu
  $menus['menu-food-menu'] = array(
    'menu_name' => 'menu-food-menu',
    'title' => 'Food Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Food Menu');


  return $menus;
}
