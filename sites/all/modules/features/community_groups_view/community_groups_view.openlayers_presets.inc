<?php
/**
 * @file
 * community_groups_view.openlayers_presets.inc
 */

/**
 * Implementation of hook_openlayers_presets().
 */
function community_groups_view_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'citygroups';
  $openlayers_presets->title = 'CityGroups';
  $openlayers_presets->description = 'CityGroups map preset.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.35810168192, 47.630495609724',
        'zoom' => '11',
      ),
      'restrict' => array(
        'restrictextent' => 0,
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
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'community_groups_map_openlayers_1' => 'community_groups_map_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_styles' => array(
      'community_groups_map_openlayers_1' => 'city_group_map_style',
      'geofield_formatter' => 'city_group_map_style',
    ),
    'layer_activated' => array(
      'community_groups_map_openlayers_1' => 'community_groups_map_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'community_groups_map_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'city_group_map_style',
      'select' => 'city_group_map_style',
      'temporary' => 'city_group_map_style',
    ),
  );
  $export['citygroups'] = $openlayers_presets;

  return $export;
}
