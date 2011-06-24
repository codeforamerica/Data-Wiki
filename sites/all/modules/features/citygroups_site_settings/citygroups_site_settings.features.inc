<?php
/**
 * @file
 * citygroups_site_settings.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function citygroups_site_settings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
