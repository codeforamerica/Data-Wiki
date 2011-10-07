<?php
/**
 * @file
 * sfo_food_context.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function sfo_food_context_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-Block-Watch-menu:food
  $menu_links['menu-Block-Watch-menu:food'] = array(
    'menu_name' => 'menu-Block-Watch-menu',
    'link_path' => 'food',
    'router_path' => 'food',
    'link_title' => 'Home/Map',
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
    'weight' => '-50',
  );
  // Exported menu link: menu-Block-Watch-menu:list/all/Block-Watch
  $menu_links['menu-Block-Watch-menu:list/all/Block-Watch'] = array(
    'menu_name' => 'menu-Block-Watch-menu',
    'link_path' => 'list/all/Block-Watch',
    'router_path' => 'list',
    'link_title' => 'List',
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
  // Exported menu link: menu-Block-Watch-menu:node/add/community-group
  $menu_links['menu-Block-Watch-menu:node/add/community-group'] = array(
    'menu_name' => 'menu-Block-Watch-menu',
    'link_path' => 'node/add/community-group',
    'router_path' => 'node/add/community-group',
    'link_title' => 'Add',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'query' => array(
        'section' => 'food',
        'destination' => 'food',
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
  t('Add');
  t('Home/Map');
  t('List');


  return $menu_links;
}
