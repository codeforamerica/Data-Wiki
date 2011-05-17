<?php
/**
 * @file
 * mailing_list.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mailing_list_ctools_plugin_api() {
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
function mailing_list_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mailing_list_node_info() {
  $items = array(
    'feed_mailing_list_csv_' => array(
      'name' => t('Feed: Mailing List (CSV)'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed_mailing_list_rss_' => array(
      'name' => t('Feed: Mailing List (RSS)'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mailing_list' => array(
      'name' => t('Mailing List'),
      'base' => 'node_content',
      'description' => t('A description of a mailing list'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
