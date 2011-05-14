<?php
/**
 * @file
 * web_resource.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function web_resource_taxonomy_default_vocabularies() {
  return array(
    'web_resource' => array(
      'name' => 'Web resource',
      'machine_name' => 'web_resource',
      'description' => 'Categories of web resources',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
