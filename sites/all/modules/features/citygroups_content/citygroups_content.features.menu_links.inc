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
  // Exported menu link: menu-footer-menu:node/3635
  $menu_links['menu-footer-menu:node/3635'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/3635',
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
  // Exported menu link: menu-footer-menu:node/6042
  $menu_links['menu-footer-menu:node/6042'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/6042',
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
  // Exported menu link: menu-footer-menu:node/6043
  $menu_links['menu-footer-menu:node/6043'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/6043',
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
  // Exported menu link: menu-footer-menu:projects
  $menu_links['menu-footer-menu:projects'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
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
  // Exported menu link: menu-postscript-menu:node/2
  $menu_links['menu-postscript-menu:node/2'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node/2',
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
  // Exported menu link: menu-postscript-menu:node/6047
  $menu_links['menu-postscript-menu:node/6047'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node/6047',
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
  // Exported menu link: menu-postscript-menu:node/6048
  $menu_links['menu-postscript-menu:node/6048'] = array(
    'menu_name' => 'menu-postscript-menu',
    'link_path' => 'node/6048',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('About CityGroups');
  t('About the Groups');
  t('Community Data');
  t('Contact');
  t('Developers');
  t('Get Involved');
  t('Map View');
  t('Projects');


  return $menu_links;
}
