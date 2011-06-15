<?php
  $html_root = drupal_get_path('module', 'datawiki_group_map');
  $sitename = "CityGroups";
  $tagline = "A public directory of groups in Seattle.";
  $page_title = "Map";
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta charset="utf-8">
  <title><?php print $sitename; ?>: <?php print $tagline; ?>: <?php print $page_title; ?></title>
  <link rel="stylesheet" href="/<?php print $html_root; ?>/includes/style/fluid_grid.css" type="text/css" />
  <link rel="stylesheet" href="/<?php print $html_root; ?>/includes/style/boilerplate.css" type="text/css" />
  <link rel="stylesheet" href="/<?php print $html_root; ?>/includes/js/leaflet/leaflet.css" />
  <link rel="stylesheet" href="/sites/all/themes/datawiki/css/style.css"  />

  
  <link rel="stylesheet" href="/<?php print $html_root; ?>/includes/style/style.css" type="text/css" />
<!--[if lte IE 8]><link rel="stylesheet" href="/<?php print $html_root; ?>/includes/style/leaflet/leaflet.ie.css" /><![endif]-->
  <script type="text/javascript" src="/<?php print $html_root; ?>/includes/js/jquery-1.5.min.js"></script>
  <script type="text/javascript" src="/<?php print $html_root; ?>/includes/js/leaflet/leaflet.js"></script>
  <script type="text/javascript" src="/<?php print $html_root; ?>/includes/js/map.js"></script>
</head>
<body>
<div id="container" class="section container_12">
    <div id="header">
      <div class="header-logo-container grid_4 alpha">
        <div class="logo grid_6 alpha"><h1><a href="/"><img typeof="foaf:Image" src="http://datawiki.local/sites/all/themes/datawiki/images/city-groups-logo.png" alt="CityGroups" /></a></h1></div>
      </div>
      <div class="grid_6 omega">
        <ul class="menu">
          <li><a href="#popular-searches" id="popular-search">Popular Searches</a></li>
          <li><a href="node/add/community-group"  id="add-group">Add a Group</a></li>
        </ul>
      </div> 
    </div>
    <div id="page-content" class="grid_12"> 
      <h3>Map</h3>
      <div id="tagline">A public directory of groups in Seattle.</div>
    
      <div id="sidebar" class="grid_2 alpha">                 
        <div id="popular-terms" class="block">
                  <h4>Popular Searches</h4>
          <ul>
            <li><a href="#defaultPath">See All</a></li>
            <li><a href="#block-watch">Block Watch</a></li>
            <li><a href="#online-newspaper">Online Newspaper</a></li>
            <li><a href="groups/categories">All Categories</a></li>
          </ul>
        </div>
  
        <div id="search-map" class="block">
          <h4>Search the map</h4>
          <input type="text" id="search-map-input" name="search-map" value="" size="20" maxlength="64" class="form-text" placeholder="Enter your address">
          <input type="submit" id="search-map-submit" name="op" value="Go" class="form-submit">
        </div>
        
        <div id="block-add-groups" class="block">
          <h4>Get Listed</h4>
          <p></p>
          <ul>
            <li><a href="node/add/community-group">Add a Group</a></li>
          </ul>
        </div>

      </div>     
      <div id="map-area" class="grid_9 omega">
        <div id="map" style="height: 600px"></div>
        <div id="data"></div>
      </div>

      <div id="popup-content" class="block">
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
