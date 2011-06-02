<?php
/**
 * @file
 * datawiki_community_groups.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function datawiki_community_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => 2);
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
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
function datawiki_community_groups_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function datawiki_community_groups_flag_default_flags() {
  $flags = array();
  // Exported flag: "Like".
  $flags['like'] = array(
    'content_type' => 'node',
    'title' => 'Like',
    'global' => '0',
    'types' => array(
      0 => 'online_community',
    ),
    'flag_short' => 'Recommend',
    'flag_long' => 'I like this.',
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
    'module' => 'datawiki_community_groups',
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
function datawiki_community_groups_node_info() {
  $items = array(
    'feed_datawiki_community_groups' => array(
      'name' => t('Feed: Online Community (Link to CSV)'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed_mailing_list_rss_' => array(
      'name' => t('Feed: Online Community (RSS)'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'online_community' => array(
      'name' => t('Online Community'),
      'base' => 'node_content',
      'description' => t('A web resource that is of particular use to the community. For example, a hyperlocal blog.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('What is the name of the community group. Try to use the name that the group calls itself. That will help prevent duplicates.'),
    ),
  );
  return $items;
}
