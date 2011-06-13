<?php
/**
 * @file
 * community_group_feed_csv_upload.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function community_group_feed_csv_upload_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'community_group_feed_csv_upload';
  $feeds_importer->config = array(
    'name' => 'Community Group Feed CSV Upload',
    'description' => 'Feed that uploads CSVs into Community Group Content Type',
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
        'content_type' => 'community_group',
        'expire' => '-1',
        'author' => '0',
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'url',
            'target' => 'field_url:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'calendar_url',
            'target' => 'field_url_calendar:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'contact',
            'target' => 'field_contact',
            'unique' => FALSE,
          ),
           6 => array(
            'source' => 'type_group',
            'target' => 'field_type_web_resource',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'notes',
            'target' => 'field_notes',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'activity_level',
            'target' => 'field_activity',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'audience_size',
            'target' => 'field_audience_size',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'ownership',
            'target' => 'field_ownership',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'image',
            'target' => 'field_url_image:url',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'location',
            'target' => 'field_location_description',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'address',
            'target' => 'field_address',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'neighborhood',
            'target' => 'field_neighborhood',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'district',
            'target' => 'field_district',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'city',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'zipcode',
            'target' => 'field_zipcode',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'state',
            'target' => 'field_state',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'region',
            'target' => 'field_region',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'area_code',
            'target' => 'field_area_code',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'latitude',
            'target' => 'field_location:lat',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'longitude',
            'target' => 'field_location:lon',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'location_geo',
            'target' => 'field_location:wkt',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'community_group_feed_upload_csv',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['community_group_feed_csv_upload'] = $feeds_importer;

  return $export;
}
