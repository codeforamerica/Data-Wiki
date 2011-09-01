<?php
/**
 * @file
 * citygroups_content.features.content_menu_links.inc
 */

/**
 * Implementation of hook_content_menu_links_defaults().
 */
function citygroups_content_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: menu-citygroups-menu:<front>
  $menu_links['menu-citygroups-menu:<front>'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
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
    'link_title' => 'Categories',
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
    'weight' => '-46',
  );
  // Exported menu link: menu-citygroups-menu:list
  $menu_links['menu-citygroups-menu:list'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'list',
    'router_path' => 'list',
    'link_title' => 'List View',
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
  // Exported menu link: menu-citygroups-menu:node/add/community-group
  $menu_links['menu-citygroups-menu:node/add/community-group'] = array(
    'menu_name' => 'menu-citygroups-menu',
    'link_path' => 'node/add/community-group',
    'router_path' => 'node/add/community-group',
    'link_title' => 'Add New Group',
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
  // Exported menu link: menu-footer-menu:node/6052
  $menu_links['menu-footer-menu:node/6052'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node-name/citygroups_page_about',
    'router_path' => 'node/%',
    'link_title' => 'About CityGroups',
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
  // Exported menu link: menu-footer-menu:node/6043
  $menu_links['menu-footer-menu:node/6043'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node-name/community_data',
    'router_path' => 'node/%',
    'link_title' => 'Community Data',
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
  // Exported menu link: menu-footer-menu:node/6042
  $menu_links['menu-footer-menu:node/6042'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node-name/developers',
    'router_path' => 'node/%',
    'link_title' => 'Developers',
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
  // Exported menu link: menu-postscript-menu:node/6048
  $menu_links['menu-postscript-menu:node/6048'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node-name/about_groups',
    'router_path' => 'node/%',
    'link_title' => 'About the Groups',
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
  // Exported menu link: menu-postscript-menu:node/6047
  $menu_links['menu-postscript-menu:node/6047'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node-name/api',
    'router_path' => 'node/%',
    'link_title' => 'API',
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
  // Exported menu link: menu-postscript-menu:node/6049
  $menu_links['menu-postscript-menu:node/6049'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node-name/citygroups_page_get_involved',
    'router_path' => 'node/%',
    'link_title' => 'Get Involved',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('About CityGroups');
  t('About the Groups');
  t('Add New Group');
  t('Categories');
  t('Community Data');
  t('Contact');
  t('Developers');
  t('Get Involved');
  t('Home');
  t('List View');
  t('Map View');


  return $menu_links;
}
