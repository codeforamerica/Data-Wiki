<?php
/**
 * @file
 * community_group_content_type.openlayers_styles.inc
 */

/**
 * Implementation of hook_openlayers_styles().
 */
function community_group_content_type_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'city_group_map_form_style';
  $openlayers_styles->title = 'City Group Map Form Style';
  $openlayers_styles->description = '';
  $openlayers_styles->data = array(
    'pointRadius' => 6,
    'fillColor' => '#FFF',
    'strokeColor' => '#000',
    'strokeWidth' => 4,
    'fillOpacity' => 0.8,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['city_group_map_form_style'] = $openlayers_styles;

  return $export;
}
