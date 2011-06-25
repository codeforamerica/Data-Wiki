/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */


(function($) {
  
/**
 * Geofield Behavior
 */
Drupal.behaviors.openlayers_behavior_geofield = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');

    /*
     * Helper method called on addFeature
     */
    function setItem(feature) {
      geom = feature.clone().geometry.transform(
        feature.layer.map.projection,
        new OpenLayers.Projection('EPSG:4326'));
        
      centroid = geom.getCentroid();
      bounds = geom.getBounds();
      type = typeLookup(feature);
      feature.layer.map.data_form.wkt.val(geom.toString());
      feature.layer.map.data_form.type.val(type);
      feature.layer.map.data_form.lat.val(centroid.x);      
      feature.layer.map.data_form.lon.val(centroid.y);
      feature.layer.map.data_form.left.val(bounds.left);
      feature.layer.map.data_form.top.val(bounds.top);
      feature.layer.map.data_form.bottom.val(bounds.bottom);
      feature.layer.map.data_form.right.val(bounds.right);
        
      for (var i = 0; i < selection_layer.features.length; i++) {
        if (selection_layer.features[i] != feature) {
          selection_layer.features[i].destroy();
        }
      }
    }
    
    function typeLookup(feature) {
      lookup = {
        'OpenLayers.Geometry.Point':'point',
        'OpenLayers.Geometry.LineString':'line',
        'OpenLayers.Geometry.Polygon':'polygon',
      };
      
      return lookup[feature.geometry.__proto__.CLASS_NAME];
    }
    
    if (data && data.map.behaviors['openlayers_behavior_geofield']) {
      
      data.openlayers.data_form = {
        'wkt':$(data.map.behaviors['openlayers_behavior_geofield']['wkt']),
        'type':$(data.map.behaviors['openlayers_behavior_geofield']['type']),
        'lat':$(data.map.behaviors['openlayers_behavior_geofield']['lat']),
        'lon':$(data.map.behaviors['openlayers_behavior_geofield']['lon']),
        'left':$(data.map.behaviors['openlayers_behavior_geofield']['left']),
        'top':$(data.map.behaviors['openlayers_behavior_geofield']['top']),
        'right':$(data.map.behaviors['openlayers_behavior_geofield']['right']),
        'bottom':$(data.map.behaviors['openlayers_behavior_geofield']['bottom'])
      };
      
      /*
       * Style
       */

    // Redraw feature with style.
    var geofieldStyleMap = new OpenLayers.StyleMap({
                "default": new OpenLayers.Style({
                    pointRadius: "5", // sized according to type attribute
                    strokeColor: "#333333",
                    fillColor: "#666666",
                    strokeWidth: 2,
                    fillOpacity: 0.6
                }),
                "select": new OpenLayers.Style({
                    strokeColor: "#333333",
                    fillColor: "#666666",
                    strokeWidth: 2,
                    fillOpacity: 0.6
                })
            });

      selection_layer = new OpenLayers.Layer.Vector('Selection Layer', {styleMap: geofieldStyleMap});
      
      /*
       * Point Drawing
       */
      point_control = new OpenLayers.Control.DrawFeature(
        selection_layer,
        OpenLayers.Handler.Point,
        {
          featureAdded: setItem
        }
      );
      data.openlayers.addLayer(selection_layer);
      data.openlayers.addControl(point_control);
      // point_control.activate();
      
      /*
       * Line Drawing
       */     
      line_control = new OpenLayers.Control.DrawFeature(
        selection_layer,
        OpenLayers.Handler.Path,
        {
          featureAdded: setItem
        }
      );
      data.openlayers.addLayer(selection_layer);
      data.openlayers.addControl(line_control);
      
      /*
       * Polygon Drawing
       */      
      polygon_control = new OpenLayers.Control.DrawFeature(
        selection_layer,
        OpenLayers.Handler.Polygon,
        {
          featureAdded: setItem
        }
      );
      data.openlayers.addLayer(selection_layer);
      data.openlayers.addControl(polygon_control);
      
      /*
       * Bounds drawing
       */
      bounds_control = new OpenLayers.Control.DrawFeature(
        selection_layer,
        OpenLayers.Handler.RegularPolygon,
        {
          featureAdded: setItem
        }
      );

      bounds_control.handler.setOptions({
          'sides': 4,
          'irregular': true});

      data.openlayers.addControl(bounds_control);

      /*
       * Navigate Control
       */      
/*
      navigate_control = new OpenLayers.Control.DrawFeature(
        selection_layer,
        OpenLayers.Handler.Polygon,
        {
          featureAdded: setItem
        }
      );
      data.openlayers.addLayer(selection_layer);
      data.openlayers.addControl(polygon_control);
*/


      // Button controls.
      var draw_features_settings = data.map.behaviors['openlayers_behavior_geofield']['geofield_draw_features'];  

      function deactivateButtons() {
         $('div.openlayers_behavior_geofield_button_pointItemInactive').css('opacity', '0.7');
         $('div.openlayers_behavior_geofield_button_polygonItemInactive').css('opacity', '0.7');
         $('div.openlayers_behavior_geofield_button_boundsItemInactive').css('opacity', '0.7');
         $('div.openlayers_behavior_geofield_button_lineItemInactive').css('opacity', '0.7');
         $('div.openlayers_behavior_geofield_button_navigateItemInactive').css('opacity', '0.7');
        // $('div.map-draw-tip').remove();
      }

      // Functions when buttons are clicked 
      buttonTogglePoint = function() {
        bounds_control.deactivate();
        line_control.deactivate();
        polygon_control.deactivate();
        point_control.activate();
        deactivateButtons();
        $('div.openlayers_behavior_geofield_button_pointItemInactive').css('opacity', '1');
      }

      buttonToggleLine = function() {
        point_control.deactivate();
        polygon_control.deactivate();
        bounds_control.deactivate(); 
        line_control.activate();
        deactivateButtons();
        $('div.openlayers_behavior_geofield_button_lineItemInactive').css('opacity', '1');
      }

      buttonToggleBounds = function() {
        point_control.deactivate();
        line_control.deactivate();
        polygon_control.deactivate();
        bounds_control.activate();
        deactivateButtons();
        $('div.openlayers_behavior_geofield_button_boundsItemInactive').css('opacity', '1');
      }

      buttonTogglePolygon = function() {
        point_control.deactivate();
        bounds_control.deactivate();
        line_control.deactivate();
        polygon_control.activate();
        deactivateButtons();
        //$('div.openlayers_behavior_geofield_button_polygonItemInactive').after('<div class="map-draw-tip">Single click on the last point to set the polygon.</div>');
        $('div.openlayers_behavior_geofield_button_polygonItemInactive').css('opacity', '1');
        
      }

      buttonToggleNavigate = function() {
        point_control.deactivate();
        bounds_control.deactivate();
        line_control.deactivate();
        polygon_control.deactivate();
        deactivateButtons();
        $('div.openlayers_behavior_geofield_button_navigateItemInactive').css('opacity', '1');
      }

      // Add buttons to control_panel for each control type
      // @TODO add graphic icons.
      point_button = new OpenLayers.Control.Button({
        displayClass: "openlayers_behavior_geofield_button_point", 
        title: Drupal.t('Set a point'),
        trigger: buttonTogglePoint
      });

      line_button = new OpenLayers.Control.Button({
        displayClass: "openlayers_behavior_geofield_button_line", 
        title: Drupal.t('Add a line'),
        trigger:  buttonToggleLine
      });

      polygon_button = new OpenLayers.Control.Button({
        displayClass: "openlayers_behavior_geofield_button_polygon", 
        title: Drupal.t('Add a polygon'),
        trigger: buttonTogglePolygon
      });

      bounds_button = new OpenLayers.Control.Button({
        displayClass: "openlayers_behavior_geofield_button_bounds", 
        title: Drupal.t('Set bounds'),
        trigger: buttonToggleBounds
      });
 
      navigate_button = new OpenLayers.Control.Button({
        displayClass: "openlayers_behavior_geofield_button_navigate", 
        title: Drupal.t('Navigate'),
        trigger: buttonToggleNavigate
      });
      
      // Create a panel to hold control buttons
      button_panel = new OpenLayers.Control.Panel({
        displayClass: 'openlayers_behavior_geofield_button_panel'
      });
            
      var buttons = [];
      if (draw_features_settings['point'] == 'point') {
        buttons.push(point_button); 
      }
      if (draw_features_settings['line'] == 'line') {
        buttons.push(line_button); 
      }
      if (draw_features_settings['polygon'] == 'polygon') {
        buttons.push(polygon_button); 
      }
      if (draw_features_settings['bounds'] == 'bounds') {
        buttons.push(bounds_button); 
      }
      if(buttons.length > 0) {
        buttons.push(navigate_button);
      }
      button_panel.addControls(buttons);
      data.openlayers.addControl(button_panel);


      // Hold down control key for polygons
      // Hold down alt key for lines
      // Hold down shift for bounds
/*

      $(document).keydown(function(event) {
        // Shift  -> Boundary
        if (event.keyCode == 16) {
          point_control.deactivate();
          line_control.deactivate();
          polygon_control.deactivate();
          bounds_control.activate();
        }
        // Control  -> Lines
        if (event.keyCode == 17) {
          point_control.deactivate();
          polygon_control.deactivate();
          bounds_control.deactivate();
          line_control.activate();
        }
        // Alt  -> Polygons
        if (event.keyCode == 18) {
          point_control.deactivate();
          line_control.deactivate();
          bounds_control.deactivate();
          polygon_control.activate();
        }
      });

      $(document).keyup(function(event) {
        // On keyup, go back to points
        if (event.keyCode == 16 || event.keyCode == 17 || event.keyCode == 18) {
          bounds_control.deactivate();
          line_control.deactivate();
          polygon_control.deactivate();
          point_control.activate();
        }
      });
      */
      
      /*
       * Draw features if the form has values
       */
      if (data.openlayers.data_form.wkt.val()) {
        geometry = new OpenLayers.Geometry.fromWKT(data.openlayers.data_form.wkt.val());
        geometry.transform(
            new OpenLayers.Projection('EPSG:4326'),
            data.openlayers.projection);
        feature = new OpenLayers.Feature.Vector(geometry, {styleMap: geofieldStyleMap});
        selection_layer.addFeatures([feature]);
      }      
    }
  }
  
};

})(jQuery);