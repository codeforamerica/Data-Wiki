<?php

/**
 * Implements hook_field_formatter_info().
 */
function geofield_field_formatter_info() {
  $formatters = array(
    'geofield_wkt' => array(
      'label' => t('Well Known Text (WKT)'),
      'field types' => array('geofield'),
      'settings' => array('data' => ''),
    ),
    'geofield_geojson' => array(
      'label' => t('GeoJSON'),
      'field types' => array('geofield'),
      'settings' => array('data' => ''),
    ),
    'geofield_kml' => array(
      'label' => t('KML'),
      'field types' => array('geofield'),
      'settings' => array('data' => ''),
    ),
    'geofield_gpx' => array(
      'label' => t('GPX'),
      'field types' => array('geofield'),
      'settings' => array('data' => ''),
    ),
    'geofield_latlon' => array(
      'label' => t('Latitude/Longitude'),
      'field types' => array('geofield'),
      'settings' => array('data' => '', 'format' => ''),
    ),
    'geofield_lat' => array(
      'label' => t('Latitude Only'),
      'field types' => array('geofield'),
      'settings' => array('data' => '', 'format' => ''),
    ),
    'geofield_lon' => array(
      'label' => t('Longitude Only'),
      'field types' => array('geofield'),
      'settings' => array('data' => '', 'format' => ''),
    ),
    'geofield_geo_type' => array(
      'label' => t('Geometry Type'),
      'field types' => array('geofield'),
      'settings' => array('data' => '', 'format' => ''),
    ),
  );

  if (module_exists('openlayers')) {  
    $formatters['geofield_openlayers'] = array(
      'label' => t('OpenLayers'),
      'field types' => array('geofield'),
      'settings' => array('map_preset' => '', 'data' => ''),
    );
  }
  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 */
function geofield_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  
  // Transform into centroid or bouding if needed
  if ($display['settings']['data'] != 'full') {
    geofield_load_geophp();
    if ($display['settings']['data'] == 'centroid') {
      foreach ($items as $delta => $item) {
        $centroid = geoPHP::load($item['wkt'],'wkt')->centroid();
        $items[$delta] = geofield_get_values_from_geometry($centroid);
      }
    }
    if ($display['settings']['data'] == 'bounding') {
      foreach ($items as $delta => $item) {
        $envelope = geoPHP::load($item['wkt'],'wkt')->envelope();
        $items[$delta] = geofield_get_values_from_geometry($envelope);
      }
    }
  }
  
  // If we are a lat, lon, or latlon, and we are using degrees-minutes-seconds (instead of decimal degrees), then do a transformation
  if (isset($display['settings']['format'])) {
    if ($display['settings']['format'] == 'degrees_minutes_seconds') {
      foreach ($items as $delta => $item) {
        $items[$delta]['lat'] = geofield_latlon_DECtoDMS($item['lat'],'lat');
        $items[$delta]['lon'] = geofield_latlon_DECtoDMS($item['lon'],'lon');
      }
    }
  }

  // If we are a lat, lon, or latlon, and we are using celestial coordinate system (instead of decimal degrees), then do a transformation
  if (isset($display['settings']['format'])) {
    if ($display['settings']['format'] == 'ccs') {
      foreach ($items as $delta => $item) {
        $items[$delta]['lat'] = geofield_latlon_DECtoCCS($item['lat'],'lat');
        $items[$delta]['lon'] = geofield_latlon_DECtoCCS($item['lon'],'lon');
      }
    }
  }

  switch ($display['type']) {
    case 'geofield_wkt':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['wkt']);
      }
      return $element;
    case 'geofield_geojson':
      geofield_load_geophp();
      foreach ($items as $delta => $item) {
        $geometry = geoPHP::load($item['wkt'],'wkt');
        if($geometry) {
          $json = $geometry->out('json');
        }
        else {
          $json = "{}";
        }
        $element[$delta] = array('#markup' => $json);
      }
      return $element;
    case 'geofield_kml':
      geofield_load_geophp();
      foreach ($items as $delta => $item) {
        $geometry = geoPHP::load($item['wkt'],'wkt');
        $kml = $geometry->out('kml');
        $element[$delta] = array('#markup' => $kml);
      }
      return $element;
    case 'geofield_gpx':
      geofield_load_geophp();
      foreach ($items as $delta => $item) {
        $geometry = geoPHP::load($item['wkt'],'wkt');
        $kml = $geometry->out('gpx');
        $element[$delta] = array('#markup' => $kml);
      }
      return $element;
    case 'geofield_latlon':
      foreach ($items as $delta => $item) {
      	$output = t('Latitude: !latitude <br/>Longitude: !longitude', array('!latitude' => $item['lat'], '!longitude' => $item['lon']));
        $element[$delta] = array('#markup' => $output);
      }
      return $element;
    case 'geofield_lat':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['lat']);
      }
      return $element;
    case 'geofield_lon':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['lon']);
      }
      return $element;
    case 'geofield_geo_type':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['geo_type']);
      }
      return $element;
    case 'geofield_openlayers':
      $preset_name = $display['settings']['map_preset'] ? $display['settings']['map_preset'] : 'geofield_formatter_map';
      $element[0] = array('#markup' => _geofield_openlayers_formatter($preset_name, $items)); 
      return $element;
  }

  return $element;
}

/**
 * Helper function for getting data options
 */
function _geofield_formatter_settings_data_options($formatter) {
  return array(
    'full' => t('Use full geometry'),
    'centroid' => t('Use centroid'),
    'bounding' => t('Use bounding box -- does not work yet'),
  );
}

/**
 * Helper function for getting format options
*/
function _geofield_formatter_settings_format_options($formatter) {
  return array(
    'decimal_degrees' => t('Decimal degrees'),
    'degrees_minutes_seconds' => t('Degrees minutes seconds'),
    'ccs' => t('Astronomical Celestial Coordinates System (CCS)'), 
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function geofield_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  // Map preset formatter
  if ($display['type'] == 'geofield_openlayers' && module_exists('openlayers')) {
    
    // Get preset options, filtered to those which have the GeoField placeholder layer
    $presets = openlayers_presets();
    $preset_options = array();
    foreach ($presets as $preset) {
      if (in_array('geofield_formatter',$preset->data['layers'])) {
        $preset_options[$preset->name] = $preset->title;
      }
    }
    
    $element['map_preset'] = array(
      '#title' => t('OpenLayers Preset'),
      '#type' => 'select',
      '#default_value' => $settings['map_preset'] ? $settings['map_preset'] : 'geofield_formatter_map',
      '#required' => TRUE,
      '#options' => $preset_options,
      '#description' => t('Select which OpenLayers map you would like to use. Only maps which have the geofield placeholder layer may be selected. If your preferred map is not here, add the geofield placeholder layer to it first.'),
    );
  }
  
  $data_options = _geofield_formatter_settings_data_options($display['type']);
  $element['data'] = array(
    '#title' => t('Data options'),
    '#type' => 'select',
    '#default_value' => $settings['data'] ? $settings['data'] : 'full',
    '#required' => TRUE,
    '#options' => $data_options,
  );

  if ($display['type'] == 'geofield_latlon' || $display['type'] == 'geofield_lat' || $display['type'] == 'geofield_lon') {
    $format_options = _geofield_formatter_settings_format_options($display['type']);
  	$element['format'] = array(
      '#title' => t('Format'),
      '#type' => 'select',
      '#default_value' => $settings['format'] ? $settings['format'] : 'decimal_degrees',
      '#required' => TRUE,
      '#options' => $format_options,
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function geofield_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  $data_options = _geofield_formatter_settings_data_options($display['type']);
  
  // TODO: Not sure if this unset is needed
  // Unset possible 'No defined styles' option.
  unset($data_options['']);

  // Styles could be lost because of enabled/disabled modules that defines
  // their styles in code.
  if (isset($data_options[$settings['data']])) {
    $summary[] = t('Data options: @data', array('@data' => $data_options[$settings['data']]));
  }
  else {
    $summary[] = t('No data options set');
  }
  
  if ($display['type'] == 'geofield_openlayers' && isset($settings['map_preset'])) {
    $openlayers_presets = openlayers_preset_options();
    $summary[] = t('Openlayers Map: @data', array('@data' => $openlayers_presets[$settings['map_preset']]));
  }

  if ($display['type'] == 'geofield_latlon') {
    $format_options = _geofield_formatter_settings_format_options($display['type']);
    // Display this setting only if image is linked.
    if (isset($format_options[$settings['format']])) {
      $summary[] = $format_options[$settings['format']];
    }
  }

  return implode('<br />', $summary);
}

function _geofield_openlayers_formatter($preset_name, $items) {
  $features = array();

  // Create array of $features
  foreach ($items as $delta) {
    $features[] = array(
      'wkt' => $delta['wkt'],
      'projection' => '4326',
    );
  }

  // Get map preset
  $preset = openlayers_preset_load($preset_name);
  $map = openlayers_build_map($preset->data);
  
  if (!$map['layers']['geofield_formatter']) {
    drupal_set_error('Trying to render a geofield formatter on a map without the placeholder layer');
  }
  
  // Add the features to the placeholder layer
  $map['layers']['geofield_formatter']['features'] = $features;
  
  // Return themed map if no errors found
  if (empty($map['errors'])) {
    $js = array('openlayers' => array('maps' => array($map['id'] => $map)));
    drupal_add_js($js, 'setting');

    // Push map through theme function and return
    $output = theme('openlayers_map', array(
      'map' => $map,
      'preset_name' => $preset_name
    ));
  }
  return $output;
}