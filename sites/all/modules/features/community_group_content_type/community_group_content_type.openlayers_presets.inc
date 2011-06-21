<?php
/**
 * @file
 * community_group_content_type.openlayers_presets.inc
 */

/**
 * Implementation of hook_openlayers_presets().
 */
function community_group_content_type_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'citygroups_form';
  $openlayers_presets->title = 'CityGroups Map Form';
  $openlayers_presets->description = 'Map for CityGroups community froup input form.';
  $openlayers_presets->data = array(
    'width' => '400px',
    'height' => '400px',
    'image_path' => 'sites/all/themes/datawiki/openlayers/img/',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.36112753603, 47.593299492122',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'geofield_draw_features' => array(
          'point' => 'point',
          'polygon' => 'polygon',
          'bounds' => 0,
          'line' => 0,
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'geofield_formatter',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'Cloudmade',
    'layers' => array(
      'Cloudmade' => 'Cloudmade',
      'geofield_formatter' => 'geofield_formatter',
      'community_groups_map_openlayers_1' => 0,
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'city_group_map_form_style',
      'community_groups_map_openlayers_1' => 'city_group_map_form_style',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'community_groups_map_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'community_groups_map_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'city_group_map_form_style',
      'select' => 'city_group_map_form_style',
      'temporary' => 'city_group_map_form_style',
    ),
  );
  $export['citygroups_form'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'citygroups_group_display';
  $openlayers_presets->title = 'CityGroups Map Group Display';
  $openlayers_presets->description = 'Map for CityGroups community group display.';
  $openlayers_presets->data = array(
    'width' => '400px',
    'height' => '400px',
    'image_path' => 'sites/all/themes/datawiki/openlayers/img/',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.36112753603, 47.593299492122',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'geofield_draw_features' => array(
          0 => '0',
          1 => '1',
          2 => 0,
          3 => 0,
        ),
      ),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'geofield_formatter',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'Cloudmade',
    'layers' => array(
      'Cloudmade' => 'Cloudmade',
      'geofield_formatter' => 'geofield_formatter',
      'community_groups_map_openlayers_1' => 0,
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'city_group_map_form_style',
      'community_groups_map_openlayers_1' => 'city_group_map_form_style',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'community_groups_map_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'community_groups_map_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'city_group_map_form_style',
      'select' => 'city_group_map_form_style',
      'temporary' => 'city_group_map_form_style',
    ),
  );
  $export['citygroups_group_display'] = $openlayers_presets;

  return $export;
}
