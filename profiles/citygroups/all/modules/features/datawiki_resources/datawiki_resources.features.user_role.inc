<?php
/**
 * @file
 * datawiki_resources.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function datawiki_resources_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  // Exported role: moderator
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => '2',
  );

  return $roles;
}
