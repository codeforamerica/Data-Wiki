<?php
/**
 * @file
 * datawiki_community_groups.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function datawiki_community_groups_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_datawiki_community_groups';
  $strongarm->value = '0';
  $export['comment_anonymous_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feed_datawiki_community_groups';
  $strongarm->value = '0';
  $export['comment_anonymous_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feed_mailing_list_csv_';
  $strongarm->value = '0';
  $export['comment_anonymous_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feed_mailing_list_rss_';
  $strongarm->value = '0';
  $export['comment_anonymous_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_online_community';
  $strongarm->value = '0';
  $export['comment_anonymous_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_datawiki_community_groups';
  $strongarm->value = '2';
  $export['comment_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_default_mode_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feed_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_default_mode_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feed_mailing_list_csv_';
  $strongarm->value = 1;
  $export['comment_default_mode_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feed_mailing_list_rss_';
  $strongarm->value = 1;
  $export['comment_default_mode_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_online_community';
  $strongarm->value = 1;
  $export['comment_default_mode_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_datawiki_community_groups';
  $strongarm->value = '50';
  $export['comment_default_per_page_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feed_datawiki_community_groups';
  $strongarm->value = '50';
  $export['comment_default_per_page_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feed_mailing_list_csv_';
  $strongarm->value = '50';
  $export['comment_default_per_page_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feed_mailing_list_rss_';
  $strongarm->value = '50';
  $export['comment_default_per_page_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_online_community';
  $strongarm->value = '50';
  $export['comment_default_per_page_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feed_datawiki_community_groups';
  $strongarm->value = '2';
  $export['comment_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feed_mailing_list_csv_';
  $strongarm->value = '2';
  $export['comment_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feed_mailing_list_rss_';
  $strongarm->value = '2';
  $export['comment_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_form_location_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feed_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_form_location_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feed_mailing_list_csv_';
  $strongarm->value = 1;
  $export['comment_form_location_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feed_mailing_list_rss_';
  $strongarm->value = 1;
  $export['comment_form_location_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_online_community';
  $strongarm->value = 1;
  $export['comment_form_location_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_online_community';
  $strongarm->value = '2';
  $export['comment_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_datawiki_community_groups';
  $strongarm->value = '1';
  $export['comment_preview_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feed_datawiki_community_groups';
  $strongarm->value = '1';
  $export['comment_preview_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feed_mailing_list_csv_';
  $strongarm->value = '1';
  $export['comment_preview_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feed_mailing_list_rss_';
  $strongarm->value = '1';
  $export['comment_preview_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_online_community';
  $strongarm->value = '1';
  $export['comment_preview_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_subject_field_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feed_datawiki_community_groups';
  $strongarm->value = 1;
  $export['comment_subject_field_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feed_mailing_list_csv_';
  $strongarm->value = 1;
  $export['comment_subject_field_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feed_mailing_list_rss_';
  $strongarm->value = 1;
  $export['comment_subject_field_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_online_community';
  $strongarm->value = 1;
  $export['comment_subject_field_online_community'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_datawiki_community_groups';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feed_datawiki_community_groups';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_feed_datawiki_community_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feed_mailing_list_csv_';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feed_mailing_list_csv_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feed_mailing_list_rss_';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feed_mailing_list_rss_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_online_community';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_online_community'] = $strongarm;

  return $export;
}
