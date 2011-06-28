<?php
/**
 * @file
 * datawiki_context.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function datawiki_context_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-citygroups-menu:<front>
  $menu_links['menu-citygroups-menu:<front>'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home/Map',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-citygroups-menu:categories
  $menu_links['menu-citygroups-menu:categories'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'categories',
    'router_path' => 'categories',
    'link_title' => 'Topics',
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
  // Exported menu link: menu-citygroups-menu:list
  $menu_links['menu-citygroups-menu:list'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'list',
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
  // Exported menu link: menu-citygroups-menu:node/add/community-group
  $menu_links['menu-citygroups-menu:node/add/community-group'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'node/add/community-group',
    'router_path' => 'node/add/community-group',
    'link_title' => 'Add',
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
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add');
  t('Home/Map');
  t('List');
  t('Topics');


  return $menu_links;
}
