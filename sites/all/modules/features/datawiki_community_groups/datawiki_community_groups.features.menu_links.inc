<?php
/**
 * @file
 * datawiki_community_groups.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function datawiki_community_groups_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:groups/all/csv/export
  $menu_links['main-menu:groups/all/csv/export'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups/all/csv/export',
    'router_path' => 'groups/all/csv/export',
    'link_title' => 'Download',
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
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/2932
  $menu_links['main-menu:node/2932'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2932',
    'router_path' => 'node/%',
    'link_title' => 'Add Groups',
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
  // Exported menu link: main-menu:node/3334
  $menu_links['main-menu:node/3334'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3334',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:node/3335
  $menu_links['main-menu:node/3335'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3335',
    'router_path' => 'node/%',
    'link_title' => 'Community Data',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Add Groups');
  t('Community Data');
  t('Download');


  return $menu_links;
}
