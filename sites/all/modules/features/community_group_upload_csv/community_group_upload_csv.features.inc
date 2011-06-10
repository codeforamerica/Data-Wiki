<?php
/**
 * @file
 * community_group_upload_csv.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function community_group_upload_csv_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function community_group_upload_csv_node_info() {
  $items = array(
    'community_group_feed_upload_csv' => array(
      'name' => t('Community Group Feed: Upload CSV'),
      'base' => 'node_content',
      'description' => t('Container for feeds that upload CSV files.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
