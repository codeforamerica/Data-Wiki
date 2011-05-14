<?php
/**
 * @file
 * web_resource.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function web_resource_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'web_resource_feed_csv';
  $feeds_importer->config = array(
    'name' => 'Web Resource Feed (CSV)',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'web_resource',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'URL',
            'target' => 'field_url:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URL Title',
            'target' => 'field_url:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Neighborhood',
            'target' => 'field_neighborhood',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'City',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'State',
            'target' => 'field_state',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Latitude',
            'target' => 'field_location:left',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Longitude',
            'target' => 'field_location:lon',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Type',
            'target' => 'field_type_web_resource',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Ownership',
            'target' => 'field_ownership',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
      ),
    ),
    'content_type' => 'feed_web_resource',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['web_resource_feed_csv'] = $feeds_importer;

  return $export;
}
