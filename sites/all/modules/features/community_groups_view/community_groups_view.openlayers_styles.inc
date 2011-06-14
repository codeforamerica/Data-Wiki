<?php
/**
 * @file
 * community_groups_view.openlayers_styles.inc
 */

/**
 * Implementation of hook_openlayers_styles().
 */
function community_groups_view_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'citygroups_map_style';
  $openlayers_styles->title = 'CityGroups Style';
  $openlayers_styles->description = 'Map style for CityGroups';
  $openlayers_styles->data = array(
    'pointRadius' => 6,
    'fillColor' => '#eee',
    'strokeColor' => '#eee',
    'strokeWidth' => 1,
    'fillOpacity' => 0.5,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['citygroups_map_style'] = $openlayers_styles;

  return $export;
}
