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
  $feeds_tamper->id = 'area_code_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'area_code';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['area_code_explode'] = $feeds_tamper;

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

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'city_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'city';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['city_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'demographic_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'demographic';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['demographic_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'district_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'district';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['district_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'neighborhood_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'neighborhood';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['neighborhood_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'region_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'region';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['region_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'state_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'state';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['state_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'type_community';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'type_community';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['type_community'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'zipcode_explode';
  $feeds_tamper->importer = 'community_group_feed_csv_upload';
  $feeds_tamper->source = 'zipcode';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['zipcode_explode'] = $feeds_tamper;

  return $export;
}
