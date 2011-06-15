<?php
/**
 * @file
 * datawiki_feed_taxonomy_categories.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function datawiki_feed_taxonomy_categories_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_taxonomy_import';
  $strongarm->value = 0;
  $export['comment_anonymous_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_taxonomy_import';
  $strongarm->value = 1;
  $export['comment_default_mode_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_taxonomy_import';
  $strongarm->value = '50';
  $export['comment_default_per_page_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_taxonomy_import';
  $strongarm->value = 1;
  $export['comment_form_location_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_taxonomy_import';
  $strongarm->value = '1';
  $export['comment_preview_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_taxonomy_import';
  $strongarm->value = 1;
  $export['comment_subject_field_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_taxonomy_import';
  $strongarm->value = '1';
  $export['comment_taxonomy_import'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_taxonomy_import';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_taxonomy_import'] = $strongarm;

  return $export;
}
