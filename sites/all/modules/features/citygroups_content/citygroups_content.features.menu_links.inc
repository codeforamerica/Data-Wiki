<?php
/**
 * @file
 * citygroups_content.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function citygroups_content_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-citygroups-menu:map
  $menu_links['menu-citygroups-menu:map'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'map',
    'router_path' => 'map',
    'link_title' => 'Map View',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-postscript-menu:contact
  $menu_links['menu-postscript-menu:contact'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Map View');


  return $menu_links;
}
