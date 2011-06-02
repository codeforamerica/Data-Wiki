<?php
/**
 * @file
 * datawiki_community_groups.openlayers_styles.inc
 */

/**
 * Implementation of hook_openlayers_styles().
 */
function datawiki_community_groups_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'city_group_map_style';
  $openlayers_styles->title = 'City Group Map Style';
  $openlayers_styles->description = '';
  $openlayers_styles->data = array(
    'pointRadius' => 6,
    'fillColor' => '#0E9EDD',
    'strokeColor' => '#fff',
    'strokeWidth' => 2,
    'fillOpacity' => 0.7,
    'strokeOpacity' => 0.7,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['city_group_map_style'] = $openlayers_styles;

  return $export;
}
