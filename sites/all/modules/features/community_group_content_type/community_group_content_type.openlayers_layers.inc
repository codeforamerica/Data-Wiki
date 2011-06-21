<?php
/**
 * @file
 * community_group_content_type.openlayers_layers.inc
 */

/**
 * Implementation of hook_openlayers_layers().
 */
function community_group_content_type_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'Cloudmade';
  $openlayers_layers->title = 'Cloudmade997';
  $openlayers_layers->description = '';
  $openlayers_layers->data = array(
    'styleId' => '997',
    'layer_type' => 'openlayers_layer_type_cloudmade',
  );
  $export['Cloudmade'] = $openlayers_layers;

  return $export;
}
