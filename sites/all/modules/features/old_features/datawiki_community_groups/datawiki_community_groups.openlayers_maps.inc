<?php
/**
 * @file
 * datawiki_community_groups.openlayers_maps.inc
 */

/**
 * Implementation of hook_openlayers_maps().
 */
function datawiki_community_groups_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'citygroups';
  $openlayers_maps->title = 'CityGroups';
  $openlayers_maps->description = 'A map for CityGroups';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '350px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.29499816389, 47.581157651478',
        'zoom' => '11',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_boxselect' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'geofield_formatter',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'osm_cycle' => 'osm_cycle',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'city_group_map_style',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 'geofield_formatter',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'city_group_map_style',
      'select' => 'city_group_map_style',
      'temporary' => 'city_group_map_style',
    ),
  );
  $export['citygroups'] = $openlayers_maps;

  return $export;
}
