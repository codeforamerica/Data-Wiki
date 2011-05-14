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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mailing_list_node_info() {
  $items = array(
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
