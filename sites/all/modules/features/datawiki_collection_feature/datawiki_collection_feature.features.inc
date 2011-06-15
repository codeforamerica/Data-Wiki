<?php
/**
 * @file
 * datawiki_collection_feature.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function datawiki_collection_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}
