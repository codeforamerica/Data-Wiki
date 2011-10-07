<?php
/**
 * @file
 * sfo_food_context.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function sfo_food_context_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
