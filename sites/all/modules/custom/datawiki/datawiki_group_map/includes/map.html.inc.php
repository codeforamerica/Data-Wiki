<?php
  $html_root = drupal_get_path('module', 'datawiki_group_map');
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta charset="utf-8">
  <title>CityGroups: Map of Community Groups in Seattle</title>
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/fluid_grid.css" type="text/css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/boilerplate.css" type="text/css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/js/leaflet/leaflet.css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/style.css" type="text/css" />
<!--[if lte IE 8]><link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/leaflet/leaflet.ie.css" /><![endif]-->
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/jquery-1.5.min.js"></script>
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/leaflet/leaflet.js"></script>
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/map.js"></script>
</head>
<body>
<div id="container" class="section container_12">
    <div id="header">
      <div class="logo grid_6 alpha"><h1><a href="/">CityGroups: Map of Community Groups in Seattle</a></h1></div>
      <div class="grid_6 omega">
        <ul class="menu">
          <li><a href="#popular-searches" id="popular-search">Popular Searches</a></li>
          <li><a href="node/add/community-group"  id="add-group">Add a Group</a></li>
        </ul>
      </div> 
    </div>
    <div id="page-content" class="grid_12"> 
      <div id="sidebar" class="grid_2 alpha">                 
        <div id="popular-terms" class="block">
          <ul>
            <li><a href="#block-watch">Block Watch</a></li>
            <li><a href="#online-newspaper">Online Newspaper</a></li>
          </ul>
        </div>
        
        <div id="block-add-groups" class="block">
          <ul>
            <li><a href="/node-add-community-group">Add a Group</a></li>
          </ul>
        </div>

      </div>     
      <div id="map-area" class="grid_9 omega">
        <div id="map" style="height: 600px"></div>
        <div id="data"></div>
      </div>

      <div id="popup-content">
          <div class="content">Click map to see where the groups are</div>
      </div>
    </div>                
    <div id="footer" class="grid_12">
      <ul class="menu">
        <li><a href="about">About</a></li>
        <li><a href="groups">View all as list</a></li>
      </ul>
    </div>
  </div>
</div>
</html>
