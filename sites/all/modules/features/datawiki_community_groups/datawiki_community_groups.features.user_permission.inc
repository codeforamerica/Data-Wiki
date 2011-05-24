<?php
/**
 * @file
 * datawiki_community_groups.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function datawiki_community_groups_user_default_permissions() {
  $permissions = array();

  // Exported permission: clear datawiki_community_groups_feed feeds
  $permissions['clear datawiki_community_groups_feed feeds'] = array(
    'name' => 'clear datawiki_community_groups_feed feeds',
    'roles' => array(),
  );

  // Exported permission: clear datawiki_community_groups_feed_csv feeds
  $permissions['clear datawiki_community_groups_feed_csv feeds'] = array(
    'name' => 'clear datawiki_community_groups_feed_csv feeds',
    'roles' => array(),
  );

  // Exported permission: clear feed_mailing_list_rss feeds
  $permissions['clear feed_mailing_list_rss feeds'] = array(
    'name' => 'clear feed_mailing_list_rss feeds',
    'roles' => array(),
  );

  // Exported permission: clear web_resource_feed_csv feeds
  $permissions['clear web_resource_feed_csv feeds'] = array(
    'name' => 'clear web_resource_feed_csv feeds',
    'roles' => array(),
  );

  // Exported permission: create feed_datawiki_community_groups content
  $permissions['create feed_datawiki_community_groups content'] = array(
    'name' => 'create feed_datawiki_community_groups content',
    'roles' => array(),
  );

  // Exported permission: create feed_mailing_list_rss_ content
  $permissions['create feed_mailing_list_rss_ content'] = array(
    'name' => 'create feed_mailing_list_rss_ content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create feed_web_resource content
  $permissions['create feed_web_resource content'] = array(
    'name' => 'create feed_web_resource content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create online_community content
  $permissions['create online_community content'] = array(
    'name' => 'create online_community content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any feed_datawiki_community_groups content
  $permissions['delete any feed_datawiki_community_groups content'] = array(
    'name' => 'delete any feed_datawiki_community_groups content',
    'roles' => array(),
  );

  // Exported permission: delete any feed_mailing_list_rss_ content
  $permissions['delete any feed_mailing_list_rss_ content'] = array(
    'name' => 'delete any feed_mailing_list_rss_ content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any feed_web_resource content
  $permissions['delete any feed_web_resource content'] = array(
    'name' => 'delete any feed_web_resource content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any online_community content
  $permissions['delete any online_community content'] = array(
    'name' => 'delete any online_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own feed_datawiki_community_groups content
  $permissions['delete own feed_datawiki_community_groups content'] = array(
    'name' => 'delete own feed_datawiki_community_groups content',
    'roles' => array(),
  );

  // Exported permission: delete own feed_mailing_list_rss_ content
  $permissions['delete own feed_mailing_list_rss_ content'] = array(
    'name' => 'delete own feed_mailing_list_rss_ content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own feed_web_resource content
  $permissions['delete own feed_web_resource content'] = array(
    'name' => 'delete own feed_web_resource content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own online_community content
  $permissions['delete own online_community content'] = array(
    'name' => 'delete own online_community content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 10
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 14
  $permissions['delete terms in 14'] = array(
    'name' => 'delete terms in 14',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 15
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 16
  $permissions['delete terms in 16'] = array(
    'name' => 'delete terms in 16',
    'roles' => array(),
  );

  // Exported permission: delete terms in 17
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(),
  );

  // Exported permission: delete terms in 18
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(),
  );

  // Exported permission: delete terms in 2
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any feed_datawiki_community_groups content
  $permissions['edit any feed_datawiki_community_groups content'] = array(
    'name' => 'edit any feed_datawiki_community_groups content',
    'roles' => array(),
  );

  // Exported permission: edit any feed_mailing_list_rss_ content
  $permissions['edit any feed_mailing_list_rss_ content'] = array(
    'name' => 'edit any feed_mailing_list_rss_ content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any feed_web_resource content
  $permissions['edit any feed_web_resource content'] = array(
    'name' => 'edit any feed_web_resource content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any online_community content
  $permissions['edit any online_community content'] = array(
    'name' => 'edit any online_community content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own feed_datawiki_community_groups content
  $permissions['edit own feed_datawiki_community_groups content'] = array(
    'name' => 'edit own feed_datawiki_community_groups content',
    'roles' => array(),
  );

  // Exported permission: edit own feed_mailing_list_rss_ content
  $permissions['edit own feed_mailing_list_rss_ content'] = array(
    'name' => 'edit own feed_mailing_list_rss_ content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own feed_web_resource content
  $permissions['edit own feed_web_resource content'] = array(
    'name' => 'edit own feed_web_resource content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own online_community content
  $permissions['edit own online_community content'] = array(
    'name' => 'edit own online_community content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 10
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 14
  $permissions['edit terms in 14'] = array(
    'name' => 'edit terms in 14',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 15
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 16
  $permissions['edit terms in 16'] = array(
    'name' => 'edit terms in 16',
    'roles' => array(),
  );

  // Exported permission: edit terms in 17
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(),
  );

  // Exported permission: edit terms in 18
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(),
  );

  // Exported permission: edit terms in 2
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: import datawiki_community_groups_feed_csv feeds
  $permissions['import datawiki_community_groups_feed_csv feeds'] = array(
    'name' => 'import datawiki_community_groups_feed_csv feeds',
    'roles' => array(),
  );

  // Exported permission: import feed_mailing_list_rss feeds
  $permissions['import feed_mailing_list_rss feeds'] = array(
    'name' => 'import feed_mailing_list_rss feeds',
    'roles' => array(),
  );

  // Exported permission: import web_resource_feed_csv feeds
  $permissions['import web_resource_feed_csv feeds'] = array(
    'name' => 'import web_resource_feed_csv feeds',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'feeds',
  );

  return $permissions;
}
