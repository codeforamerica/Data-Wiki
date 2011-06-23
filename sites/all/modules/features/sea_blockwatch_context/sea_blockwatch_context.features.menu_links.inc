<?php
/**
 * @file
 * sea_blockwatch_context.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function sea_blockwatch_context_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-block-watch-menu:blockwatch
  $menu_links['menu-block-watch-menu:blockwatch'] = array(
    'menu_name' => 'menu-block-watch-menu',
    'link_path' => 'blockwatch',
    'router_path' => 'blockwatch',
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
  // Exported menu link: menu-block-watch-menu:list/all/block-watch
  $menu_links['menu-block-watch-menu:list/all/block-watch'] = array(
    'menu_name' => 'menu-block-watch-menu',
    'link_path' => 'list/all/block-watch',
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
  // Exported menu link: menu-block-watch-menu:node/add/community-group
  $menu_links['menu-block-watch-menu:node/add/community-group'] = array(
    'menu_name' => 'menu-block-watch-menu',
    'link_path' => 'node/add/community-group',
    'router_path' => 'node/add/community-group',
    'link_title' => 'Add',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'query' => array(
        'section' => 'blockwatch',
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
