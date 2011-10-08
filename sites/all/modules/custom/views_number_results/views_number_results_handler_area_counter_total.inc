<?php

/**
 * @file
 * 
 * Handler for number of results.
 */

/**
 * Provide the number of results for the view.
 *
 * @ingroup views_field_handlers
 */
class views_number_results_handler_area_counter_total extends views_handler_area {

  function query() {
    // Do nothing -- to override the parent query.
  }

  function render($values) {
    $count = '<div class="views-number-results">' . $this->view->total_rows . '<div class="label">' . t(' of these ') . '</div></div>';
    return $count;
  }

}
