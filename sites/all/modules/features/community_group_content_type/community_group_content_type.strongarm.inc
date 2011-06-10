<?php
/**
 * @file
 * community_group_content_type.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function community_group_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_community_group';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_community_group'] = $strongarm;

  return $export;
}
