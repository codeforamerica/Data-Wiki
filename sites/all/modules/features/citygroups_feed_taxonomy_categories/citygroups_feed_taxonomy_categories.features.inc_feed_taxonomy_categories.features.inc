<?php
/**
 * @file
 * citygroups_feed_taxonomy_categories.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function citygroups_feed_taxonomy_categories_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
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
function citygroups_feed_taxonomy_categories_node_info() {
  $items = array(
    'taxonomy_import' => array(
      'name' => t('Taxonomy Import'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
