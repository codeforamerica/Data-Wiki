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
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function community_group_content_type_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function community_group_content_type_flag_default_flags() {
  $flags = array();
  // Exported flag: "Duplicate Content".
  $flags['duplicate'] = array(
    'content_type' => 'node',
    'title' => 'Duplicate Content',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Flag as Duplicate',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'My mistake, this is not a duplicate.',
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
  // Exported flag: "Flag a group as inactive".
  $flags['inactive'] = array(
    'content_type' => 'node',
    'title' => 'Flag a group as inactive',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Seems Dead',
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
    'module' => 'community_group_content_type',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Inappropriate Content".
  $flags['inappropriate'] = array(
    'content_type' => 'node',
    'title' => 'Inappropriate Content',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Flag as inappropriate',
    'flag_long' => 'This content is inappropriate.',
    'flag_message' => 'Flag this content as inappropriate.',
    'unflag_short' => 'My mistake, this content is appropriate.',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
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
    'flag_confirmation' => 'Thanks. We will look at the inappropriate content as soon as possible.',
    'unflag_confirmation' => 'Thanks. We will ignore your message.',
    'module' => 'community_group_content_type',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Recommend".
  $flags['recommend'] = array(
    'content_type' => 'node',
    'title' => 'Recommend',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Recommend',
    'flag_long' => 'I would recommend this.',
    'flag_message' => '',
    'unflag_short' => 'Un-Recommend.',
    'unflag_long' => 'You recommended this. You can un-recommend it.',
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
  // Exported flag: "Watch".
  $flags['watch'] = array(
    'content_type' => 'node',
    'title' => 'Watch',
    'global' => '0',
    'types' => array(
      0 => 'community_group',
    ),
    'flag_short' => 'Watch',
    'flag_long' => 'Watch this group',
    'flag_message' => 'This post has been added to your watch list.',
    'unflag_short' => 'Stop Watching',
    'unflag_long' => 'Stop watching this group.',
    'unflag_message' => 'This post has been removed from your watch list.',
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
    'show_on_form' => 1,
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
      'title_label' => t('Name of Group'),
      'help' => t('What is the name of the community group. Try to use the name that the group calls itself.'),
    ),
  );
  return $items;
}
