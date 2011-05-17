<?php
/**
 * @file
 * mailing_list.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function mailing_list_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed_mailing_list_csv';
  $feeds_importer->config = array(
    'name' => 'Feed: Mailing List (CSV)',
    'description' => 'Import Mailing List',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
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
        'content_type' => 'mailing_list',
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
            'source' => 'Ownership',
            'target' => 'field_ownership',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Contact',
            'target' => 'field_contact',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'District',
            'target' => 'field_district',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Region',
            'target' => 'field_region',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Type',
            'target' => 'field_type_mailing_list',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Area Code',
            'target' => 'field_area_code',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'feed_mailing_list_csv_',
    'update' => 0,
    'import_period' => '10800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feed_mailing_list_csv'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed_mailing_list_rss';
  $feeds_importer->config = array(
    'name' => 'Feed: Mailing List (RSS)',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'mailing_list',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'tags',
            'target' => 'field_type_mailing_list',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'url',
            'target' => 'field_url:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'author_name',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'feed_mailing_list_rss_',
    'update' => 0,
    'import_period' => '10800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feed_mailing_list_rss'] = $feeds_importer;

  return $export;
}
