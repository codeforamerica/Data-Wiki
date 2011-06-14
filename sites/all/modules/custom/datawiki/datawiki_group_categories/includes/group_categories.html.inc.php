<?php
  $html_root = drupal_get_path('module', 'datawiki_group_categories');
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta charset="utf-8">
  <title>CityGroups: Categories of Community Groups in Seattle</title>
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/fluid_grid.css" type="text/css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/boilerplate.css" type="text/css" />
  <link rel="stylesheet" href="sites/all/themes/datawiki/css/style.css"  />

  
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/style.css" type="text/css" />
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/jquery-1.5.min.js"></script>
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/topics.js"></script>
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
      <h3>Categories</h3>
      <div id="tagline">A public directory of groups in Seattle.</div>
<!--
    
      <div id="sidebar" class="grid_2 alpha">                 
      </div>
-->
  
<!--
        <div id="search-map" class="block">
          <h4>Search the map</h4>
          <input type="text" id="search-map-input" name="search-map" value="" size="20" maxlength="64" class="form-text" placeholder="Enter your address">
          <input type="submit" id="search-map-submit" name="op" value="Go" class="form-submit">
        </div>
        
-->
<!--
        <div id="block-add-groups" class="block">
          <h4>Get Listed</h4>
          <p></p>
          <ul>
            <li><a href="node/add/community-group">Add a Group</a></li>
          </ul>
        </div>
-->

      </div>     
      <div id="topics-area" class="grid_9 omega">
        <div id="data">TOPICS</div>
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
