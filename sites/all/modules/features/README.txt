# About the Features

## CityGroups Overview
We are using a very simple Features-based framework to set up structured
data types for CityGroups.

There are a lot of features, the idea is that each feature is 
broken into smaller components. 
This makes the features easier to debug & easier to work with.

## Structure

CityGroups is an installation profile that will theme your site, 
add content pages, and turn on all of the Drupal settings that will 
give you a toolset for collecting information on community groups 
in your city.

#Install Profile
The install profile lives here: drupal/profiles/citygroups

This install module triggers:
* features 
* citygroups module

It also installs the theme, user roles and a few custom settings.


## Modules
sites/all
There are many modules that need installing, they are installed to
sites/all like a normal Drupal site. 

#Make Script
A custom make script could be used to download and set up the 
modules & 3rd party libraries.
 
These must be installed before installing CityGroups.

Cloning the CityGroups codebase from GitHub, you should have most of the
modules. 

There are a few modules we have checked out from 
git.drupal.org because we are doing active devlopment (ex. geofield, geoPHP).


Be sure you check out the correct branch: 
currently: citygroups_v2


## Features & Custom Modules Overview


CityGroups is the core module that turns on the shared Drupal settings 
common for other types of citygroups.


## CUSTOM MODULES
### sites/all/modules/custom/citygroups

#### citygroups
#### citygroups_group_categories
#### citygroups_group_map
#### citygroups_splash
#### citygroups_group_form

### citygroups_projects
#### sea_blockwatch

### views number results



## FEATURES


### citygroups Install Feature
drupal/sites/all/modules/features/citygroups_install

Installs all dependent core & contrib modules.
The idea: anything that is not a feature.

This triggers the custom citygroups module, which sets
off the chain of triggering everything else.

### citygroups Module
Provides blocks.
Installs citygroups related submodules.

### citygroups_sub

Dev: will be deprecated.
The idea is to have a template demonstrate the implementation
of themed subsections.

requires: "citygroups_group_categories", "citygroups_group_map"

### citygroups_group_categories
Module that will handle special treatment of categories.

  @TODO For future dev.
  
### citygroups group map
Special map display using leaflet.


### Seattle Blockwatch
Module does not belong here, but it is an active subsite.
requires: "citygroups_group_categories", "citygroups_group_map"

### citygroups Features

#### citygroups_settings
Special site settings.

  @TODO Using this?

#### citygroups_views
Main views for citygroups site.

#### citygroups_feed_taxonomy_categories
Provides a feed importer for mapping imported taxonomy.

  @TODO This is dev. Needs more development and testing.

#### citygroups_basic_page
Provides a basic page content type.

#### citygroups_context
Contexts: relates paths to the display of blocks.

#### citygroups_content
Custom page content. Uses defaultcontent module.

#### citygroups_community_group_views
Special views for community groups.

#### citygroups_developer
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

### citygroups_citygroups_install
A features that provides special handling for City Groups the site.

### CityGroups Views
General Views across all CityGroups content.
citygroups_citygroups_views

### citygroups Community Group
A collection of features that make up the citygroups Community Group App.

### citygroups Community Group Content Type 
community_group_content_type
Contains all of the fields, taxonomies for the structured data.

### citygroups Community Group Feed CSV Upload
Community Group Feed CSV Upload
community_group_feed_csv_upload
Feed that uploads CSVs into Community Group Content Type

### citygroups Community Group Feed CSV Link
Community Group Feed CSV Link
community_group_feed_csv_link

### citygroups Community Group Feed RSS Link
Community Group Feed RSS Link
community_group_feed_rss_link

### citygroups Community Group Feed JSON Link
Community Group Feed JSON Link
community_group_feed_json_link

### citygroups Community Group Upload CSV (Content Type)
community_group_upload_csv

A container content type & Feed that allow for importing CSVs in the same format as the content type.

### citygroups Community Group Views
citygroups_community_group_views

Contains view of data & display.

A view that displays the data as JSON and CSV (CSV is an export CSV button, and there is also a previewable table.)
A view that displays the view to the user. Has search blocks.

### citygroups Community Group Site Settings
Special Drupal site settings that pertain to the community group. Example: Permissions, Contexts.
citygroups_community_group_settings






Themes: citygroups, citygroups_admin, citygroups, citygroups_admin

  @TODO Themes needs some work.

