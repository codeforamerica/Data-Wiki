<?php

/**
 * @file
 * Create test data for Taxonomy Filter module.
 *
 * This script creates:
 * - a content type of 'tf_test'
 * - content of type 'tf_test'
 * - three taxonomy vocabularies
 * - taxonomy terms to relate the content
 *
 * The taxonomy_filter_add_test_data() routine accepts two inflation parameters
 * that affect the number of content items and taxonomy terms created. With the
 * default values of one, the dataset created is targeted at providing sample
 * data for the automated tests. With greater inflation values, the dataset
 * created may be used to test the efficiency of the taxonomy_filter_tf_section()
 * query. The query efficiency has been tested with data created with
 * $node_inflate = 200 and $term_inflate = 10 which produces 25K content items,
 * 450 taxonomy terms, over 400K content tags, and 1.25M taxonomy index items.
 *
 * Suggestions for improving the complexity of the tagging to further stress
 * the query are welcome.
 *
 * This script may be invoked by saving a file in the root directory of the
 * Drupal installation and invoking it from a browser or command line.
 * @code
 * define('DRUPAL_ROOT', getcwd());
 * require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
 * drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
 * module_load_include('php', 'taxonomy_filter', 'tests/test_data_1');
 * taxonomy_filter_add_test_data($node_inflate = 1, $term_inflate = 1);
 * drupal_set_message('Done with taxonomy_filter_add_test_data()');
 * @endcode
 */

/**
  * Creates a custom content type based on default settings.
  *
  * Adapted from DrupalWebTestCase::drupalCreateContentType().
  *
  * @param $settings
  *   An array of settings to change from the defaults.
  *   Example: 'type' => 'foo'.
  * @return
  *   Created content type.
  */
function taxonomy_filter_content_type_add($settings = array()) {
  // Populate defaults array.
  $defaults = array(
    'type' => 'tf_test',
    'name' => 'tf_test',
    'base' => 'node_content',
    'description' => '',
    'help' => '',
    'has_title' => 1,
    'title_label' => 'Title',
    'custom' => 1,
    'modified' => 1,
    'locked' => 0,
    'orig_type' => '',
    'body_label' => 'Body',
    'has_body' => 1,
  );
  $type = $settings + $defaults;
  $type = (object) $type;

  if (node_type_get_type($type->type)) {
    node_type_delete($type->type);
    // Purge all field information
    // http://api.drupal.org/api/function/field_purge_batch/7
    field_purge_batch(1000);
  }
  $saved_type = node_type_save($type);
  node_types_rebuild();
  menu_rebuild();
  node_add_body_field($type); // Is this (or was this) automatically added by core?

  return $type;
}

function taxonomy_filter_fields_add($vid) {
  $field = array(
    'field_name' => 'taxonomy_vocab_' . $vid,
    'type' => 'taxonomy_term_reference',
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'settings' => array(
      'allowed_values' => array(
        array(
          'vid' => $vid,
          'parent' => 0,
        ),
      ),
    ),
  );
  $info = field_info_field($field['field_name']);
  if (!empty($info)) {
    field_delete_field($field['field_name']);
  }
  field_create_field($field);

  $instance = array(
    'field_name' => 'taxonomy_vocab_' . $vid,
    'entity_type' => 'node',
    'bundle' => 'tf_test', // TODO This won't exist by default -- need to add a content type
    'widget' => array(
      'type' => 'options_buttons',
      'weight' => 10,
    ),
//     'widget' => array(
//       'type' => 'options_select',
//     ),
//     'display' => array(
//       'default' => array(
//         'type' => 'taxonomy_term_reference_link',
//       ),
//     ),
  );
//   field_delete_instance($instance); // This is done by field_delete_field().
  field_create_instance($instance);
}

/**
 * Populates database with taxonomy (vocabularies and terms) and content.
 *
 * @todo Add term_relation data!!!
 */
function taxonomy_filter_add_test_data($node_inflate = 1, $term_inflate = 1) {
  $version6 = function_exists('module_load_include'); // TODO this is not robust enough with D5-7

  tfdp("starting");
  taxonomy_filter_content_type_add();

  taxonomy_filter_add_vocabulary($node_inflate, $term_inflate);
//   taxonomy_filter_add_node($node_inflate, $term_inflate);
//   taxonomy_filter_add_term_data($node_inflate, $term_inflate);
//   taxonomy_filter_add_term_hierarchy($node_inflate, $term_inflate);
//   taxonomy_filter_add_index($node_inflate, $term_inflate, $version6);
}

function taxonomy_filter_add_vocabulary($node_inflate, $term_inflate) {
  $i = 0;
  while ($i < 3) {
    $i++;
    tfdp("inserted taxonomy_vocabulary $i");
    taxonomy_filter_fields_add($i);
  }
/*
//   $sql = "TRUNCATE {taxonomy_vocabulary}";
//   $result = db_query($sql);
//   if ($result === FALSE) {
//     tfdp("messed up");
//   }
//   tfdp("deleted vocabularies");
  $table = 'taxonomy_vocabulary';
  tf_truncate($table);

  $sql = "INSERT INTO {taxonomy_vocabulary} (vid, name, machine_name, description, hierarchy, module, weight)
          VALUES (:vid, :name, :machine_name, :description, :hierarchy, :module, :weight)"; // VALUES (%d, '%s', '%s', '%s', %d, '%s', %d)";

  $values = array();
  $values['hierarchy'] = 0; // Used to be 1
  $values['module'] = 'taxonomy';

  $i = 0;
  while ($i < 3) {
    $i++;
    $values['vid'] = $i;
    $values['name'] = 'Vocab #' . $i;
    $values['machine_name'] = 'vocab_' . $i;
    $values['description'] = 'Description of vocab #' . $i;
    $values['weight'] = $i;
    $result = db_query($sql, $values /*$vid, $name, $machine_name, $description, $hierarchy, $module, $weight*//*);
    if ($result === FALSE) {
      tfdp("messed up taxonomy_vocabulary $i");
    }
    else {
//       tfdp("inserted taxonomy_vocabulary $i");
//       tfdp("$sql");
    }
    tfdp("inserted taxonomy_vocabulary $i");
    taxonomy_filter_fields_add($i);
  }
*/
  ///////////////////////////////////////
/*
  $sql = "TRUNCATE {vocabulary_node_types}";
  $result = db_query($sql);
  if ($result === FALSE) {
    tfdp("messed up", FILE_APPEND);
  }
  tfdp("deleted vocabulary_node_types");

  $type = 'tf_test';

  $sql = "INSERT INTO {vocabulary_node_types} (vid, type)
          VALUES (%d, '%s')";
  $values = array();

  $i = 0;
  while ($i < 3) {
    $i++;
    $vid = $i;
    $result = db_query($sql, $vid, $type);
    if ($result === FALSE) {
      tfdp("messed up vocabulary_node_types");
    }
    else {
      tfdp("inserted vocabulary_node_types $i");
      tfdp("$sql");
    }
  }
*/
}

  ///////////////////////////////////////

function taxonomy_filter_add_node($node_inflate, $term_inflate) {
//   $sql = "TRUNCATE {node}";
//   $result = db_query($sql);
//   if ($result === FALSE) {
//     tfdp("messed up");
//   }
//   tfdp("deleted nodes");
  $table = 'node';
  tf_truncate($table);

  $sql = "INSERT INTO {node} (nid, vid, type, language, title, uid, status, created, changed, comment, promote)
          VALUES (:nid, :vid, :type, :language, :title, :uid, :status, :created, :changed, :comment, :promote)";

  $values = array();
  $values['type'] = 'tf_test';
  $values['language'] = 'und';
  $values['uid'] = 1;
  $values['status'] = 1;
  $values['created'] = 1242224668;
  $values['changed'] = 1242224668;
  $values['comment'] = 2;
  $values['promote'] = 1;

  $i = 0;
  while ($i < 125 * $node_inflate) {
    $i++;
    $values['nid'] = $i;
    $values['vid'] = $values['nid'];
    $values['title'] = 'Story #' . $i;
    $result = db_query($sql, $values /*$nid, $vid, $type, $title, $uid, $status, $created, $changed, $comment, $promote*/);
    if ($result === FALSE) {
      tfdp("messed up node $i");
    }
    else {
//       tfdp("inserted node $i");
//       tfdp("$sql");
    }
  }
  tfdp("inserted node");

  ///////////////////////////////////////

//   $sql = "TRUNCATE {node_revision}";
//   $result = db_query($sql);
  $table = 'node_revision';
  tf_truncate($table);

  // body, teaser, format
  // CONCAT('Content #', nid), CONCAT('Content #', nid), 1

  $sql = "INSERT INTO {node_revision} (nid, vid, uid, title, log, timestamp)
          SELECT nid, vid, uid, title, '', 1242224668
          FROM node
          WHERE type = 'tf_test'";
  $result = db_query($sql);
/*
  $sql = "TRUNCATE {node_comment_statistics}";
  $result = db_query($sql);

  $sql = "INSERT INTO {node_comment_statistics} (nid, last_comment_timestamp, last_comment_name, last_comment_uid, comment_count)
          SELECT nid, 1242224668, NULL, 1, 0
          FROM node";
  $result = db_query($sql);
*/

  foreach (array('field_data_body', 'field_revision_body') as $table) {
//     $sql = "TRUNCATE {$table}";
//     $result = db_query($sql);
    tf_truncate($table);

    $sql = "INSERT INTO {$table} (etid, bundle, deleted, entity_id, revision_id, language, delta, body_value, body_summary, body_format)
            SELECT 1, 'tf_test', 0, nid, vid, 'und', 0, CONCAT('Content #', nid), CONCAT('Content #', nid), 1
            FROM node
            WHERE type = 'tf_test'";
    $result = db_query($sql);
    tfdp("inserted $table");
  }
}

  ///////////////////////////////////////

function taxonomy_filter_add_term_data($node_inflate, $term_inflate) {
//   $sql = "TRUNCATE {taxonomy_term_data}";
//   $result = db_query($sql);
  $table = 'taxonomy_term_data';
  tf_truncate($table);

  $sql = "INSERT INTO {taxonomy_term_data} (tid, vid, name, description, format, weight)
          VALUES (:tid, :vid, :name, :description, :format, :weight)"; // VALUES (%d, %d, '%s', '%s', %d, %d)";
  $values = array();

  $i = 0;
  while ($i < 45 * $term_inflate) {
    $i++;
    $tid = $i;/*
    if ($tid < 11) {
      $vid = 1;
    }
    elseif ($tid < 21) {
      $vid = 2;
    }
    elseif ($tid < 31) {
      $vid = 3;
    }
    elseif ($tid < 41) {
      $vid = 1;
    }
    else {
      $vid = 2;
    }*/
    $vid = $tid % 3 + 1; // 3=vid count; make a variable
    $values['tid'] = $tid;
    $values['vid'] = $vid;
    $values['name'] = 'term #' . $i;
    $values['description'] = 'description #' . $i;
    $values['format'] = 1;
    $values['weight'] = $i;

    $result = db_query($sql, $values /*$tid, $vid, $name, $description, $weight*/);
    if ($result === FALSE) {
      tfdp("messed up taxonomy_term_data $i");
    }
    else {
//       tfdp("inserted taxonomy_term_data $i");
//       tfdp("$sql");
    }
  }
  tfdp("inserted taxonomy_term_data");
}
  ///////////////////////////////////////

function taxonomy_filter_add_term_hierarchy($node_inflate, $term_inflate) {
//   $sql = "TRUNCATE {taxonomy_term_hierarchy}";
//   $result = db_query($sql);
  $table = 'taxonomy_term_hierarchy';
  tf_truncate($table);

  $sql = "INSERT INTO {taxonomy_term_hierarchy} (tid, parent)
          VALUES (:tid, :parent)"; // VALUES (%d, %d)";
  $values = array();

  $i = 0;
  while ($i < 45 * $term_inflate) {
    $i++;
    $values['tid'] = $i;
    $values['parent'] = ($values['tid'] % 5) == 1 ? 0 : $values['tid'] - 1;

    $result = db_query($sql, $values /*$tid, $parent*/);
    if ($result === FALSE) {
      tfdp("messed up taxonomy_term_hierarchy $i");
    }
    else {
//       tfdp("inserted taxonomy_term_hierarchy $i");
//       tfdp("$sql");
    }
  }
  tfdp("inserted taxonomy_term_hierarchy");
}

  ///////////////////////////////////////

  // Add term_relation!!! No longer exists!!!

  ///////////////////////////////////////

function taxonomy_filter_add_index($node_inflate, $term_inflate, $version6) {
//   $sql = "TRUNCATE {taxonomy_index}";
//   $result = db_query($sql);
  $table = 'taxonomy_index';
  tf_truncate($table);

  if ($version6) {
    $sql = "INSERT INTO {taxonomy_index} (nid, tid, sticky, created)
            VALUES (:nid, :tid, :sticky, :created)"; // VALUES (%d, %d, %d)";
  }
  else {
    $sql = "INSERT INTO {taxonomy_index} (nid, tid)
            VALUES (%d, %d)";
  }
  $values = array();
  $timestamp = time();
/*
  $i = 0;
  while ($i < 125 * $node_inflate) {
    $i++;
    $values['nid'] = $nid = $i;
//     $values['vid'] = $nid;
    $values['sticky'] = 0;
    $values['created'] = $timestamp;

    $first_tid = ($nid - 1) % (25 * $term_inflate) + 1; // $first_tid = ($nid - 1) % 25 + 1;
    $j = 0;
    while ($j < 5 * $term_inflate) {
      $values['tid'] = $first_tid + 5 * $j;

      if ($version6) {
        $result = db_query($sql, $values /*$nid, $tid, $sticky, $created*//*);
      }
//       else {
//         $result = db_query($sql, $nid, $tid);
//       }
      if ($result === FALSE) {
        tfdp("messed up taxonomy_index $i");
      }
      else {
//         tfdp("inserted taxonomy_index $i");
//         tfdp("$sql");
      }
      $j++;
    }
  }
*/


  $j = 0;
  while ($j < 5 * $term_inflate) {
    $sql = "INSERT INTO {taxonomy_index} (nid, tid, sticky, created)
            SELECT nid, (nid - 1) % (25 * $term_inflate) + 1 + 5 * $j, 0, $timestamp
            FROM node
            WHERE type = 'tf_test'";

    if ($version6) {
      $result = db_query($sql, $values /*$nid, $tid, $sticky, $created*/);
    }
    if ($result === FALSE) {
      tfdp("messed up taxonomy_index $i");
    }
    else {
//         tfdp("inserted taxonomy_index $i");
//         tfdp("$sql");
    }
    $j++;
  }
  tfdp("inserted taxonomy_index");

  ///////////////////////////////////////

  $i = 0;
  while ($i < 3) {
    $i++;
    foreach (array('field_data_taxonomy_vocab_' . $i, 'field_revision_taxonomy_vocab_' . $i) as $table) {
//       $sql = "TRUNCATE {$table}";
//       $result = db_query($sql);
      tf_truncate($table);

      // SELECT 1 as etid, 'tf_test', 0 as deleted, nid as entity_id, nid as revision_id, 'und' as language, a.tid as delta, a.tid FROM taxonomy_index a JOIN taxonomy_term_data b ON b.tid = a.tid WHERE b.vid = 1
      // ORDER BY etid, entity_id, deleted, delta, language
      // Problem is delta needs an incrementing value

      $sql = "INSERT INTO {$table} (etid, bundle, deleted, entity_id, revision_id, language, delta, taxonomy_vocab_{$i}_tid)
              SELECT 1, 'tf_test', 0, a.nid, a.nid, 'und', a.tid, a.tid
              FROM taxonomy_index a
              JOIN taxonomy_term_data b ON b.tid = a.tid
              WHERE b.vid = $i";
      $result = db_query($sql);
    }
    tfdp("inserted $table");
  }

  tfdp("done with changes");
}

function tfdp($text) {
  static $path = '';

  if (!$path) {
    $path = file_directory_path() . '/debug.txt';
  }
  file_put_contents($path, $text . "\n", FILE_APPEND);
}

function tf_truncate($table) {
  if (db_table_exists($table)) {
    db_truncate($table)->execute();
    tfdp("truncated $table");
  }
}
