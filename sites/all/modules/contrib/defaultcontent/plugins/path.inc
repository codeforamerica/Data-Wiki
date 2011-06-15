<?php
/**
 * @file
 *
 * is an alter plugin for defaultcontent
 *
 * Handles the exporting and importing of current path
 */
$plugin = array();

/**
 * Handles the loading of the current path in export
 */
function path_export_alter(&$node, &$export) {
  if(isset($node->nid)) {
    $path = path_load("node/". $node->nid);
    if ($path) {
      $export->exported_path = $path['alias'];
    }
  }
    
}

/**
 * handles the loading of the current path after the node
 * is loaded
 */
function path_post_import($node) {
    if(isset($node->nid) && 
       ($path = path_load("node/". $node->nid)) &&
       isset($node->exported_path)
       ) {
      $path['alias'] = $node->exported_path;
      path_save($path);
    }
}

