<?php
/**
 * @file
 * sfo_food_context.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function sfo_food_context_content_defaults() {
$content = array();
$content['sfo_food_about'] = (object)array(
  'exported_path' => 'food/about',
  'title' => 'About',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314038735',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'sfo_food_about',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>About Block Watch Captain Directory</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>About Block Watch Captain Directory</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['sfo_food_api'] = (object)array(
  'exported_path' => 'food/api',
  'title' => 'Block Watch Captain Directory API',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314038898',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'sfo_food_api',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Block Watch Captain Directory API</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Block Watch Captain Directory API</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['sfo_food_get_involved'] = (object)array(
  'exported_path' => 'food/get-involved',
  'title' => 'Get Involved',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314038822',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'sfo_food_get_involved',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Get involved with Block Watch Captain Directory.</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Get involved with Block Watch Captain Directory.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}
