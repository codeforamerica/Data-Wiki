<?php
/**
 * @file
 * citygroups_site_settings.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function citygroups_site_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'error_level';
  $strongarm->value = '0';
  $export['error_level'] = $strongarm;

  return $export;
}
