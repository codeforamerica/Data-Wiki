<?php
/**
 * @file
 * community_groups_view.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function community_groups_view_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}
