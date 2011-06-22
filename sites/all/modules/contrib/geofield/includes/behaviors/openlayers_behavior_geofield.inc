<?php

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Map Form Values Behavior
 */
class openlayers_behavior_geofield extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    //TODO: use the field name and the delta in naming these items so we don't get conflicts
    return array(
        'wkt' => '#geofield_wkt',
        'geo_type' => '#geofield_geo_type',
        'lat' => '#geofield_lat',
        'lon' => '#geofield_lon',
        'left' => '#geofield_left',
        'bottom' => '#geofield_bottom',
        'right' => '#geofield_right',
        'top' => '#geofield_top',
        'geofield_draw_features' => array(),
    );
  }

  /**
   * Form defintion for per map customizations.
   */
  function options_form($defaults) {
    // Select which features can be drawn on the map.

    $form = array();
    $form['geofield_draw_features'] = array(
      '#title' => t('Geofield Draw Features'),
      '#type' => 'checkboxes',
      '#options' => array('point' => t('Point'), 'polygon' => t('Polygon'), 'bounds' => t('Bounds'),'line' => t('Line')),
      '#description' => t('Select which map drawing features should be available.'),
      '#default_value' => isset($defaults['geofield_draw_features']) ? 
        $defaults['geofield_draw_features'] : array(),
    );

    return $form;
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'geofield') .'/includes/behaviors/js/openlayers_behavior_geofield.js');
    drupal_add_css(drupal_get_path('module', 'geofield') .'/includes/behaviors/css/openlayers_behavior_geofield.css');
    return $this->options;
  }
}
