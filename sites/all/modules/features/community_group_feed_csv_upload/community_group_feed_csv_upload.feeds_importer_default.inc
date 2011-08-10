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
          2 => array(
            'source' => 'calendar_url',
            'target' => 'field_url_calendar:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'contact',
            'target' => 'field_contact',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'type_group',
            'target' => 'field_type_group',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'notes',
            'target' => 'field_notes',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'activity_level',
            'target' => 'field_activity',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'audience_size',
            'target' => 'field_audience_size',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'ownership',
            'target' => 'field_ownership',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'image',
            'target' => 'field_url_image:url',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'location',
            'target' => 'field_location_description',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'address',
            'target' => 'field_address',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'neighborhood',
            'target' => 'field_neighborhood',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'district',
            'target' => 'field_district',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'city',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'county',
            'target' => 'field_county',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'state',
            'target' => 'field_state',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'region',
            'target' => 'field_region',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'area_code',
            'target' => 'field_area_code',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'longitude',
            'target' => 'field_location:lon',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'location_geo_type',
            'target' => 'field_location:geo_type',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'location_wkt',
            'target' => 'field_location:wkt',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'location_geo_right',
            'target' => 'field_location:right',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'location_geo_top',
            'target' => 'field_location:top',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'location_geo_bottom',
            'target' => 'field_location:bottom',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'location_geo_left',
            'target' => 'field_location:left',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'type_community',
            'target' => 'field_type_community',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'zipcode',
            'target' => 'field_zipcode',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'area_code',
            'target' => 'field_area_code',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'latitude',
            'target' => 'field_location:lat',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'type_community',
            'target' => 'field_type_community',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'demographic',
            'target' => 'field_demographic',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'guid',
            'target' => 'field_id_guid',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'id_custom',
            'target' => 'field_id_custom',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'community_group_feed_upload_csv',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['community_group_feed_csv_upload'] = $feeds_importer;

  return $export;
}
