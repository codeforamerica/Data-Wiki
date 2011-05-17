<?php
/**
 * @file
 * mailing_list.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function mailing_list_strongarm() {
  $export = array();

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
  $strongarm->name = 'comment_anonymous_mailing_list';
  $strongarm->value = 0;
  $export['comment_anonymous_mailing_list'] = $strongarm;

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
  $strongarm->name = 'comment_default_mode_mailing_list';
  $strongarm->value = 1;
  $export['comment_default_mode_mailing_list'] = $strongarm;

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
  $strongarm->name = 'comment_default_per_page_mailing_list';
  $strongarm->value = '50';
  $export['comment_default_per_page_mailing_list'] = $strongarm;

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
  $strongarm->name = 'comment_form_location_mailing_list';
  $strongarm->value = 1;
  $export['comment_form_location_mailing_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_mailing_list';
  $strongarm->value = '1';
  $export['comment_mailing_list'] = $strongarm;

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
  $strongarm->name = 'comment_preview_mailing_list';
  $strongarm->value = '1';
  $export['comment_preview_mailing_list'] = $strongarm;

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
  $strongarm->name = 'comment_subject_field_mailing_list';
  $strongarm->value = 1;
  $export['comment_subject_field_mailing_list'] = $strongarm;

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
  $strongarm->name = 'node_options_mailing_list';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_mailing_list'] = $strongarm;

  return $export;
}
