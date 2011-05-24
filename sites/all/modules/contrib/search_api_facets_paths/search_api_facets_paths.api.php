<?php
/**
 * @file
 * API documentation for Pretty paths
 *
 * (C)2011 Michael Moritz miiimooo/at/drupal.org
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * return one or more path creation and parsing methods that can be used by
 * search_api_facets_paths to create a user friendly path instead of a
 * fragment
 *
 * The hook returns an array of this format:
 * "module_name_pathmaker_base" => t("Description of the pathmaker")
 *
 * Your module can implement the following functions:
 * module_name_pathmaker_base_make_path($vid, $names)
 *   take $vid, $names (array of taxonomy term names) and transform it into a
 *   (path) string that can be transformed back by _split_path() and _parse_path()
 * @see search_api_facets_paths_voc_slash_name_make_path
 * @see search_api_facets_paths_id_name_make_path
 * @see search_api_facets_paths_make_path
 *
 *
 * module_name_pathmaker_base_split_path($path)
 *   this function should split the path in a way that can be iterrated over
 *   by _parse_path(), return an array
 * @see search_api_facets_paths_split_path
 * @see search_api_facets_paths_voc_slash_name_split_path
 * @see search_api_facets_paths_id_name_split_path
 *
 * module_name_pathmaker_base_parse_path($path)
 *   convert back one part of the path (e.g. "type/briefing" - vocabulary name/
 *   term name) to vid, names
 * @see search_api_facets_paths_parse_path
 * @see search_api_facets_paths_voc_slash_name_parse_path
 * @see search_api_facets_paths_id_name_parse_path
 *
 * These three functions form a workflow in which _make_path() creates a string
 * that can be split (_split_path()) and transformed back into the original
 * vid and names array passed to _make_path().
 *
 * A simple but less useful implementation is the search_api_facets_paths_id_name
 * triple of functions.
 *
 * @see search_api_facets_paths_search_api_facets_paths_pathtypes
**/
function hook_search_api_facets_paths_pathtypes() {
  return array();
}
/**
 * @} End of "addtogroup hooks".
 */


