<?php
/**
 * @file
 * datawiki_community_groups.feeds_tamper_default.inc
 */

/**
 * Implementation of hook_feeds_tamper_default().
 */
function datawiki_community_groups_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'categories_tag_explode';
  $feeds_tamper->importer = 'web_resource_feed_csv';
  $feeds_tamper->source = 'Categories';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => 1,
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 1 items.';
  $export['categories_tag_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'city_tag_explode';
  $feeds_tamper->importer = 'web_resource_feed_csv';
  $feeds_tamper->source = 'City';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => 1,
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 1 items.';
  $export['city_tag_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'neighborhood_tag_explode';
  $feeds_tamper->importer = 'web_resource_feed_csv';
  $feeds_tamper->source = 'Neighborhood';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '100',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 100 items.';
  $export['neighborhood_tag_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ownership_tag_explode';
  $feeds_tamper->importer = 'web_resource_feed_csv';
  $feeds_tamper->source = 'Ownership';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => 1,
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 1 items.';
  $export['ownership_tag_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'type_tag_explode';
  $feeds_tamper->importer = 'web_resource_feed_csv';
  $feeds_tamper->source = 'Type';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => 1,
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Break text into items at every ",". Limit to 1 items.';
  $export['type_tag_explode'] = $feeds_tamper;

  return $export;
}
