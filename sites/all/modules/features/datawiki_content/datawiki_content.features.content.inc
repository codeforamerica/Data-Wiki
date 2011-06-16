<?php
/**
 * @file
 * datawiki_content.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function datawiki_content_content_defaults() {
$content = array();
$content['datawiki_page_welcome'] = (object)array(
  'exported_path' => 'home',
  'title' => 'Welcome',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308186396',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'datawiki_page_welcome',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is the welcome page.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is the welcome page.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}
