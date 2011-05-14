<?php
/**
 * @file
 * web_resource.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function web_resource_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function web_resource_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function web_resource_node_info() {
  $items = array(
    'feed_web_resource' => array(
      'name' => t('Feed: Web Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'web_resource' => array(
      'name' => t('Web resource'),
      'base' => 'node_content',
      'description' => t('A web resource that is of particular use to the community. For example, a hyperlocal blog.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
