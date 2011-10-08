<?php
/**
 * @file
 * community_group_content_type.openlayers_maps.inc
 */

/**
 * Implementation of hook_openlayers_maps().
 */
function community_group_content_type_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'citygroups';
  $openlayers_maps->title = 'CityGroups';
  $openlayers_maps->description = 'A map for CityGroups';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.35816955077, 37.74574303671',
        'zoom' => '9',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-13648672.205184,4509326.045845,-13574069.665591,4567112.439219',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'geofield_formatter',
        'point_zoom_level' => '14',
      ),
    ),
    'default_layer' => 'google_hybrid',
    'layers' => array(
      'google_hybrid' => 'google_hybrid',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'geofield_formatter' => '0',
      'community_groups_map_openlayers_1' => '0',
    ),
    'layer_styles' => array(
      'community_groups_map_openlayers_1' => '0',
      'geofield_formatter' => '0',
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
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['citygroups'] = $openlayers_maps;

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'citygroups_map_form';
  $openlayers_maps->title = 'CityGroups Map Form';
  $openlayers_maps->description = 'Form for Maps';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/themes/citygroups_base/openlayers/img/',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.31079101101, 37.591642486714',
        'zoom' => '9',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '-13669386.639874,4474812.914899,-13550450.623884,4580907.51014',
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
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_scaleline' => array(),
    ),
    'default_layer' => 'google_hybrid',
    'layers' => array(
      'google_hybrid' => 'google_hybrid',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'geofield_formatter' => '0',
      'community_groups_map_openlayers_1' => '0',
    ),
    'layer_styles' => array(
      'community_groups_map_openlayers_1' => '0',
      'geofield_formatter' => 'city_group_map_form_style',
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
  $export['citygroups_map_form'] = $openlayers_maps;

  return $export;
}
