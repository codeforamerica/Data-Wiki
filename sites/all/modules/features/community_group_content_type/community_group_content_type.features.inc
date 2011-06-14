<?php
/**
 * @file
 * community_group_content_type.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function community_group_content_type_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_styles") {
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
function community_group_content_type_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function community_group_content_type_flag_default_flags() {
  $flags = array();
  // Exported flag: "Flag a group as inactive".
  $flags['group_inactive'] = array(
    'content_type' => 'node',
    'title' => 'Flag a group as inactive',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Inactive Group',
    'flag_long' => 'This group appears to be inactive.',
    'flag_message' => '',
    'unflag_short' => 'Actually, no, this group is active.',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'community_group_content_type',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Recommend".
  $flags['like'] = array(
    'content_type' => 'node',
    'title' => 'Recommend',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Recommend',
    'flag_long' => 'I would recommend this.',
    'flag_message' => '',
    'unflag_short' => 'Not Recommended',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'community_group_content_type',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function community_group_content_type_node_info() {
  $items = array(
    'community_group' => array(
      'name' => t('Community Group'),
      'base' => 'node_content',
      'description' => t('A community group.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('What is the name of the community group. Try to use the name that the group calls itself.'),
    ),
  );
  return $items;
}
