<?php
/**
 * @file
 * community_resource.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function community_resource_ctools_plugin_api() {
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
 * Implementation of hook_node_info().
 */
function community_resource_node_info() {
  $items = array(
    'community_resource' => array(
      'name' => t('Community Resource'),
      'base' => 'node_content',
      'description' => t('A resource in a community. A place, building or other feature.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
