<?php
/**
 * @file
 * community_group_feed_csv_upload.feeds_tamper_default.inc
 */

/**
 * Implementation of hook_feeds_tamper_default().
 */
function community_group_feed_csv_upload_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'categories_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'categories';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['categories_explode'] = $feeds_tamper;

  return $export;
}
