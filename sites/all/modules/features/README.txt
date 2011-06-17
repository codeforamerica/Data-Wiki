# About the Features


## DataWiki Overview
We are using a very simple Features-based framework to set up structured
data types for the Data Wiki. The DataWiki is intended to be an open data
workbook that allows for offline data collection (mobile apps & printable
 maps) & reconciling crowd-sourced data feeds.


There are a lot of features, the idea is that each feature is 
broken into smaller components. 
This makes the features easier to debug.

## Structure

CityGroups is an installation profile that will theme your site, 
add content pages, and turn on all of the Drupal settings that will 
give you a datawiki for collecting information on community groups 
in your city.

The install profile lives here: drupal/profiles/citygroups

This install module triggers modules & dependent modules.
It also installs the theme, user roles and a few custom settings.


## Modules
sites/all
There are many modules that need installing, they are installed to
sites/all like a normal Drupal site. A custom make script could 
build this. These must be installed before installing CityGroups.

If you checkout the Data-Wiki codebase, you should have most of the
modules. There are a few modules we have checked out from 
git.drupal.org because we are doing active devlopment (ex. geofield, geoPHP).

Be sure you check out the correct branch: 
currently: datawiki_prealpha_v1.0

You will need to download and install these. (Use the master branch.)

## Features & Custom Modules Overview

(Will try to keep this up to date.)

DataWiki is the core feature that turns on the shared Drupal settings 
common for other types of datawikis. For example, in addition to collecting
crowd-sourced structured data for community groups, you can also collect 
social services information, information about community gardens, 
kitchens & farms.
Lives here: 

### DataWiki Install Feature
drupal/sites/all/modules/features/datawiki_install

Installs all dependent core & contrib modules.
The idea: anything that is not a feature.

This triggers the custom datawiki module, which sets
off the chain of triggering everything else.

### Datawiki Module
Provides blocks.
Installs Datawiki related submodules.

### datawiki_collection

Dev: will be deprecated.
The idea is to have a template demonstrate the implementation
of themed subsections.

requires: "datawiki_group_categories", "datawiki_group_map"

### datawiki_group_categories
Module that will handle special treatment of categories.

  @TODO For future dev.
  
### Datawiki group map
Special map display using leaflet.


### Seattle Blockwatch
Module does not belong here, but it is an active subsite.
requires: "datawiki_group_categories", "datawiki_group_map"

### DataWiki Features

#### datawiki_settings
Special site settings.

  @TODO Using this?

#### datawiki_views
Main views for datawiki site.

#### datawiki_feed_taxonomy_categories
Provides a feed importer for mapping imported taxonomy.

  @TODO This is dev. Needs more development and testing.

#### datawiki_basic_page
Provides a basic page content type.

#### datawiki_context
Contexts: relates paths to the display of blocks.

#### datawiki_content
Custom page content. Uses defaultcontent module.

#### datawiki_community_group_views
Special views for community groups.

#### datawiki_developer
Custom developer features.



### Citygroups Splash
Based off OpenPublic Splash page, this provides an overlay on installation.
Prompts administrators regarding what to do.

  @TODO Has JS bug that prevents it from loading.
  Uncaught TypeError: Cannot call method 'show' of undefined

### Views Number Results
Provides counts of Views results.

  @TODO Needs Label


---- ^ Current June 16, 2011 ---------------------------------------------------
The stuff below may be out of date.

## CityGroups

### datawiki_citygroups_install
A features that provides special handling for City Groups the site.

### CityGroups Views
General Views across all CityGroups content.
datawiki_citygroups_views

### DataWiki Community Group
A collection of features that make up the DataWiki Community Group App.

### DataWiki Community Group Content Type 
community_group_content_type
Contains all of the fields, taxonomies for the structured data.

### DataWiki Community Group Feed CSV Upload
Community Group Feed CSV Upload
community_group_feed_csv_upload
Feed that uploads CSVs into Community Group Content Type

### DataWiki Community Group Feed CSV Link
Community Group Feed CSV Link
community_group_feed_csv_link

### DataWiki Community Group Feed RSS Link
Community Group Feed RSS Link
community_group_feed_rss_link

### DataWiki Community Group Feed JSON Link
Community Group Feed JSON Link
community_group_feed_json_link

### DataWiki Community Group Upload CSV (Content Type)
community_group_upload_csv

A container content type & Feed that allow for importing CSVs in the same format as the content type.

### DataWiki Community Group Views
datawiki_community_group_views

Contains view of data & display.

A view that displays the data as JSON and CSV (CSV is an export CSV button, and there is also a previewable table.)
A view that displays the view to the user. Has search blocks.

### DataWiki Community Group Site Settings
Special Drupal site settings that pertain to the community group. Example: Permissions, Contexts.
datawiki_community_group_settings






Themes: datawiki, datawiki_admin, citygroups, citygroups_admin

  @TODO Themes needs some work.

