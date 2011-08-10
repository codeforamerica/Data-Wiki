<?php
/**
 * @file
 * community_group_content_type.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function community_group_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_community_group';
  $strongarm->value = '0';
  $export['comment_anonymous_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_community_group';
  $strongarm->value = '2';
  $export['comment_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_community_group';
  $strongarm->value = 1;
  $export['comment_default_mode_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_community_group';
  $strongarm->value = '50';
  $export['comment_default_per_page_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_community_group';
  $strongarm->value = 1;
  $export['comment_form_location_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_community_group';
  $strongarm->value = '1';
  $export['comment_preview_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_community_group';
  $strongarm->value = 1;
  $export['comment_subject_field_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_community_group';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_community_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_default_preset';
  $strongarm->value = 'citygroups_form';
  $export['openlayers_default_preset'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_layers_cloudmade_api';
  $strongarm->value = 'b59bc8b09cd84af58fcef3019d84e662';
  $export['openlayers_layers_cloudmade_api'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_layers_cloudmade_js';
  $strongarm->value = 'sites/all/libraries/cloudmade/cloudmade.js';
  $export['openlayers_layers_cloudmade_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_layers_google_api';
  $strongarm->value = 'ABQIAAAA69Pr8X6qVjpuLObW66yHqxQvCBnyA8Dnut3uUp_R-TVopO7JaxT3FkO2q3npJ5nTyzL9raYyhP8evw';
  $export['openlayers_layers_google_api'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_source';
  $strongarm->value = 'sites/all/libraries/openlayers-2.9.1/OpenLayers.js';
  $export['openlayers_source'] = $strongarm;

  return $export;
}
