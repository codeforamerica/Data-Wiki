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
class views_number_results_handler_field_counter_total extends views_handler_field {

  function query() {
    // Do nothing -- to override the parent query.
  }

  function render($values) {
    $count = $this->view->total_rows;
    return $count;
  }

}
