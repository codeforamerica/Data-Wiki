<?php
/**
 * @file
 * citygroups_content.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function citygroups_content_content_defaults() {
$content = array();
$content['about_groups'] = (object)array(
  'exported_path' => 'about/groups',
  'title' => 'About the Groups',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314045685',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'about_groups',
  'body' => array(),
);
$content['api'] = (object)array(
  'exported_path' => 'api',
  'title' => 'API',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314045618',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'api',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>API page</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>API page</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['citygroups_page_about'] = (object)array(
  'exported_path' => 'about',
  'title' => 'About',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189591',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'citygroups_page_about',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h1>CityGroups</h1>
<h3><strong>A public directory of community groups in your city.</strong></h3>
<p>CityGroups is a searchable public directory that allows community organizers and residents to find community groups by location and topic. In cities across the country, there is amazing work being done by community organizers to mobilize their neighbors and take on community problems. CityGroups helps connect and publicize these less-visible groups by working with local community groups, governments and local technologists to make an open platform for finding &amp; recommending groups working to make your city better.</p>
<p>&nbsp;</p>
<h3>Main Features</h3>
<ul>
	<li><strong>Searchable.</strong> Search by location or topic. Generate lists of community groups in your neighborhood.</li>
	<li><strong>Community Editable.</strong> Like a wiki, anyone can add or update information about local groups.</li>
	<li><strong>Social Directory. </strong>Groups can be categorized, mapped &amp; shared.</li>
	<li><strong>Any and all groups included.</strong> We make it easier to find the little groups, be they &ldquo;over the fence&rdquo;, e-mail lists or any group with a link to a web page.</li>
	<li><strong>Quality control. </strong>CityGroups provides simple tools for reporting if a group is recommended, or &ldquo;dead.&rdquo; Imagine if email lists and blog sites from 3 years ago had Yelp and Meetup-like features.</li>
	<li><strong>Standardized, open data.</strong> Using a simple data standard, humans and computers can import and export data from the system. Supports CSV import and JSON export (API).</li>
	<li><strong>Supports Data Collection Projects.</strong> We support reaching out to collect community groups by neighborhood, by topic, or in partnership with local community focused non-profits. Provides customizable front-end for data collection efforts.</li>
</ul>
<h4>&nbsp;</h4>
<h4>Goals</h4>
<ul>
	<li>Help neighborhoods promote their many little working groups to facilitate collaboration.</li>
	<li>Increase participation in local initiatives through better visibility.</li>
	<li>Support data collection projects: For example, Block Watch Captains in Seattle are finding each other by building upon the CityGroups platform.</li>
	<li>Help people find new groups that make their lives better.</li>
	<li>Improve group data. People update, correct and mark as &ldquo;dead&rdquo; out-dated group information.</li>
</ul>
<h4>&nbsp;</h4>
<h4>Find out more &amp; get CityGroups in your city</h4>
<p>On the web: <a href="http://citygroups.org">http://citygroups.org</a><br />
	Check out CityGroups in Seattle: <a href="http://seattle.citygroups.org">http://seattle.citygroups.org</a><br />
	Email: citygroups@codeforamerica.org or Chach Sikes, chacha@codeforamerica.org<br />
	Twitter: <a href="http://twitter.com/AllCityGroups">@AllCityGroups</a></p>
<p>Created as Open Source by <a href="http://codeforamerica.org">Code for America.</a></p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>CityGroups</p>
<h3><strong>A public directory of community groups in your city.</strong></h3>
<p>CityGroups is a searchable public directory that allows community organizers and residents to find community groups by location and topic. In cities across the country, there is amazing work being done by community organizers to mobilize their neighbors and take on community problems. CityGroups helps connect and publicize these less-visible groups by working with local community groups, governments and local technologists to make an open platform for finding &amp; recommending groups working to make your city better.<br />
 </p>
<h3>Main Features</h3>
<ul><li><strong>Searchable.</strong> Search by location or topic. Generate lists of community groups in your neighborhood.</li>
<li><strong>Community Editable.</strong> Like a wiki, anyone can add or update information about local groups.</li>
<li><strong>Social Directory. </strong>Groups can be categorized, mapped &amp; shared.</li>
<li><strong>Any and all groups included.</strong> We make it easier to find the little groups, be they “over the fence”, e-mail lists or any group with a link to a web page.</li>
<li><strong>Quality control. </strong>CityGroups provides simple tools for reporting if a group is recommended, or “dead.” Imagine if email lists and blog sites from 3 years ago had Yelp and Meetup-like features.</li>
<li><strong>Standardized, open data.</strong> Using a simple data standard, humans and computers can import and export data from the system. Supports CSV import and JSON export (API).</li>
<li><strong>Supports Data Collection Projects.</strong> We support reaching out to collect community groups by neighborhood, by topic, or in partnership with local community focused non-profits. Provides customizable front-end for data collection efforts.</li>
</ul><h4> </h4>
<h4>Goals</h4>
<ul><li>Help neighborhoods promote their many little working groups to facilitate collaboration.</li>
<li>Increase participation in local initiatives through better visibility.</li>
<li>Support data collection projects: For example, Block Watch Captains in Seattle are finding each other by building upon the CityGroups platform.</li>
<li>Help people find new groups that make their lives better.</li>
<li>Improve group data. People update, correct and mark as “dead” out-dated group information.</li>
</ul><h4> </h4>
<h4>Find out more &amp; get CityGroups in your city</h4>
<p>On the web: <a href="http://citygroups.org">http://citygroups.org</a><br />
	Check out CityGroups in Seattle: <a href="http://seattle.citygroups.org">http://seattle.citygroups.org</a><br />
	Email: <a href="mailto:citygroups@codeforamerica.org">citygroups@codeforamerica.org</a> or Chach Sikes, <a href="mailto:chacha@codeforamerica.org">chacha@codeforamerica.org</a><br />
	Twitter: <a href="http://twitter.com/AllCityGroups">@AllCityGroups</a><br />
Created as Open Source by <a href="http://codeforamerica.org">Code for America.</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['citygroups_page_data_group'] = (object)array(
  'exported_path' => 'data-standard-community-groups',
  'title' => 'Data Standard: Community Groups',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189720',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'citygroups_page_data_group',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'CityGroups CSV Data Structure for Groups


All of this appears on this webpage:
http://citygroups.org/data-standard

Updated 6/14/2011

<h3>Column Headers</h3>
name, url, calendar_url, email, contact, type_group, categories, description, notes, source, activity_level, audience_size, ownership, image, location, address, neighborhood, district, city, zipcode, state, region, area_code, latitude, longitude, location_geo

Last updated June 14, 2011

<h4>Name</h4>
name
The name of the online community, ideally from the page or mailing list title.

<h4>URL</h4>
url
Link to the best page to find a description of the group and know how to join the group.

<h4>Calendar URL</h4>
calendar_url
Link to the page that best describes how to get information about events for this group.

<h4>Email</h4>
email
If a mailing list, the email address that someone would use to subscribe. (If subscription is complicated, just list the URL)

<h4>Contact</h4>
contact
Name, email and/or phone number of contact

<h4>Type of Group</h4>
type_group
Type of online community, for example: Yahoo Group, Facebook page, Ning network, Mailing list, etc.

<h4>Categories</h4>
categories
Comma-separated list of tags and keywords that best describe the content of the site.

An important part of CityGroups is having good category listings. We will have a Civic Taxonomy that you can use in addition to freetags. You can also tag groups by your values.

<h4>Description</h4>
description
A general description of the group.

<h4>Notes</h4>
notes
Any additional information about the group.

<h4>Source</h4>
source
Where the original data was from.

<h4>Activity Level</h4>
activity_level

* We will probably have a table here for the values, like GTFS.
General activity level of the group

Values:
Multiple Daily
Daily
Every few days
Weekly
Monthly
Yearly 
Apparently Inactive

<h4>Audience Size</h4>
audience_size
* We will probably have a table here for the values, like GTFS.
General size of audience

Values
1-10
10-100
100-1000
1,000-10,000
10,000-100,000
100,000 - 1,000,000
1,000,000+



<h4>Ownership</h4>
ownership
Possible values: community, commercial, personal, government

<h4>Image</h4>
image
A url pointing to an image for the group.






<h3>About Location Data<h3>
Enter what you know, and we can help you fill in the rest.

Some location data is helpful. 

The goal is to map out the service area that the group actually applies to. City-wide is an option for general discussions, but some groups may just apply to a block, or even just a small plot of land like a garden or a vacant lot.

<h4>Location</h4>
location

Freetext for location, if stored & not geocoded.





<h4>Address</h4>
address
Enter the Street Address. This is optional and we use it to pinpoint your group on the map.

<h4>Neighborhood</h4>
neighborhood
Name of the neighborhood

In cities, the name of a neighborhood is often a complicated issue. Enter as many neighborhood names as can be used to map the service area of the group.

<h4>District</h4>
district
Name of the District

<h4>City</h4>
city
Name of the city.

<h4>State</h4>
state
Name of the State (abbreviated, ex: WA, CA, MN, MA.)

<h4>Zipcode</h4>
zipcode
Zipcode for the area, feel free to include the 4 
digit zipcode extension if you know it.

<h4>Region</h4>
region
If the group extends into the greater metro area, include county names or other useful data. 

<h4>Area Code</h4>
area_code
The three digit area code. Not required, though any location data is useful if you do not know anything else.


<h4>Latitude</h4>
latitude
The latitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)


<h4>Longitude</h4>
longitude
The longitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)




<h4>Location Geo</h4>
* May rename this to geometry, which matches the GeoJSON specification which we use a lot.

location_geo
A Well-known-text shape definition for the service area of the community, or GeoJSON description, or textfield describing the location. If you do not know this, we have a map tool that can help you draw the service area of the group. Import your data, and then go back and update it.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>CityGroups CSV Data Structure for Groups</p>
<p>All of this appears on this webpage:<br /><a href="http://citygroups.org/data-standard">http://citygroups.org/data-standard</a></p>
<p>Updated 6/14/2011</p>
<h3>Column Headers</h3>
<p>name, url, calendar_url, email, contact, type_group, categories, description, notes, source, activity_level, audience_size, ownership, image, location, address, neighborhood, district, city, zipcode, state, region, area_code, latitude, longitude, location_geo</p>
<p>Last updated June 14, 2011</p>
<h4>Name</h4>
<p>name<br />
The name of the online community, ideally from the page or mailing list title.</p>
<h4>URL</h4>
<p>url<br />
Link to the best page to find a description of the group and know how to join the group.</p>
<h4>Calendar URL</h4>
<p>calendar_url<br />
Link to the page that best describes how to get information about events for this group.</p>
<h4>Email</h4>
<p>email<br />
If a mailing list, the email address that someone would use to subscribe. (If subscription is complicated, just list the URL)</p>
<h4>Contact</h4>
<p>contact<br />
Name, email and/or phone number of contact</p>
<h4>Type of Group</h4>
<p>type_group<br />
Type of online community, for example: Yahoo Group, Facebook page, Ning network, Mailing list, etc.</p>
<h4>Categories</h4>
<p>categories<br />
Comma-separated list of tags and keywords that best describe the content of the site.</p>
<p>An important part of CityGroups is having good category listings. We will have a Civic Taxonomy that you can use in addition to freetags. You can also tag groups by your values.</p>
<h4>Description</h4>
<p>description<br />
A general description of the group.</p>
<h4>Notes</h4>
<p>notes<br />
Any additional information about the group.</p>
<h4>Source</h4>
<p>source<br />
Where the original data was from.</p>
<h4>Activity Level</h4>
<p>activity_level</p>
<p>* We will probably have a table here for the values, like GTFS.<br />
General activity level of the group</p>
<p>Values:<br />
Multiple Daily<br />
Daily<br />
Every few days<br />
Weekly<br />
Monthly<br />
Yearly<br />
Apparently Inactive</p>
<h4>Audience Size</h4>
<p>audience_size<br />
* We will probably have a table here for the values, like GTFS.<br />
General size of audience</p>
<p>Values<br />
1-10<br />
10-100<br />
100-1000<br />
1,000-10,000<br />
10,000-100,000<br />
100,000 - 1,000,000<br />
1,000,000+</p>
<h4>Ownership</h4>
<p>ownership<br />
Possible values: community, commercial, personal, government</p>
<h4>Image</h4>
<p>image<br />
A url pointing to an image for the group.</p>
<h3>About Location Data<br /><h3>
Enter what you know, and we can help you fill in the rest.
</h3></h3><p>Some location data is helpful. </p>
<p>The goal is to map out the service area that the group actually applies to. City-wide is an option for general discussions, but some groups may just apply to a block, or even just a small plot of land like a garden or a vacant lot.</p>
<h4>Location</h4>
<p>location</p>
<p>Freetext for location, if stored &amp; not geocoded.</p>
<h4>Address</h4>
<p>address<br />
Enter the Street Address. This is optional and we use it to pinpoint your group on the map.</p>
<h4>Neighborhood</h4>
<p>neighborhood<br />
Name of the neighborhood</p>
<p>In cities, the name of a neighborhood is often a complicated issue. Enter as many neighborhood names as can be used to map the service area of the group.</p>
<h4>District</h4>
<p>district<br />
Name of the District</p>
<h4>City</h4>
<p>city<br />
Name of the city.</p>
<h4>State</h4>
<p>state<br />
Name of the State (abbreviated, ex: WA, CA, MN, MA.)</p>
<h4>Zipcode</h4>
<p>zipcode<br />
Zipcode for the area, feel free to include the 4<br />
digit zipcode extension if you know it.</p>
<h4>Region</h4>
<p>region<br />
If the group extends into the greater metro area, include county names or other useful data. </p>
<h4>Area Code</h4>
<p>area_code<br />
The three digit area code. Not required, though any location data is useful if you do not know anything else.</p>
<h4>Latitude</h4>
<p>latitude<br />
The latitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)</p>
<h4>Longitude</h4>
<p>longitude<br />
The longitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)</p>
<h4>Location Geo</h4>
<p>* May rename this to geometry, which matches the GeoJSON specification which we use a lot.</p>
<p>location_geo<br />
A Well-known-text shape definition for the service area of the community, or GeoJSON description, or textfield describing the location. If you do not know this, we have a map tool that can help you draw the service area of the group. Import your data, and then go back and update it.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['citygroups_page_get_involved'] = (object)array(
  'exported_path' => 'get-involved',
  'title' => '(PreAlpha) Get Involved',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308202164',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'citygroups_page_get_involved',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<em>This site is under active development.</em>

Updated June 15, 2011

We are doing a few things.

<h4>Drupal Product</h4>
Building this site as a Drupal product (similar to Managing News), which can be easily installed by anyone wishing to collect community data on a topic.

<h4>Code is on Github</h4>
https://github.com/codeforamerica/Data-Wiki
(codeforamerica, chachasikes, Data-Wiki)

The documentation may be out of sync, but the idea is for the project to be an installation profile.


<h4>Development</h4>
Currently this is a project of Team Seattle (Chach Sikes & Anna Bloom) as a tool for our <a href="http://codeforamerica.org">"Engagement Toolkit"</a> - tools that help community organizers work together.

We are testing the site with various community members in the city of Seattle. This includes Block Watch Captains & people involved with local food systems.

<h4>We are looking for community organizer partners</h4>
If your neighborhood or favorite topic does not have all the best groups, you can share them.

If you have data that should be listed on the site, by all means let us know. We are making it really easy to share group information - and you can upload properly formatted CSV files. If you are interested, contact Chach. chacha at codeforamerica dot org, @chachasikes on Twitter.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p><em>This site is under active development.</em></p>
<p>Updated June 15, 2011</p>
<p>We are doing a few things.</p>
<h4>Drupal Product</h4>
<p>Building this site as a Drupal product (similar to Managing News), which can be easily installed by anyone wishing to collect community data on a topic.</p>
<h4>Code is on Github</h4>
<p><a href="https://github.com/codeforamerica/Data-Wiki">https://github.com/codeforamerica/Data-Wiki</a><br />
(codeforamerica, chachasikes, Data-Wiki)</p>
<p>The documentation may be out of sync, but the idea is for the project to be an installation profile.</p>
<h4>Development</h4>
<p>Currently this is a project of Team Seattle (Chach Sikes &amp; Anna Bloom) as a tool for our <a href="http://codeforamerica.org">"Engagement Toolkit"</a> - tools that help community organizers work together.</p>
<p>We are testing the site with various community members in the city of Seattle. This includes Block Watch Captains &amp; people involved with local food systems.</p>
<h4>We are looking for community organizer partners</h4>
<p>If your neighborhood or favorite topic does not have all the best groups, you can share them.</p>
<p>If you have data that should be listed on the site, by all means let us know. We are making it really easy to share group information - and you can upload properly formatted CSV files. If you are interested, contact Chach. chacha at codeforamerica dot org, @chachasikes on Twitter.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['citygroups_page_welcome'] = (object)array(
  'exported_path' => 'home',
  'title' => 'Home',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308186396',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'citygroups_page_welcome',
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
$content['community_data'] = (object)array(
  'exported_path' => 'community-data',
  'title' => 'Community Data',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314038655',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'community_data',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Community Data</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Community Data</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['data_page_community_data'] = (object)array(
  'exported_path' => 'community-data-api',
  'title' => 'Community Data & API',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189616',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'data_page_community_data',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'There is a reason why we do not already have a city-wide groups directory already: it requires the participation of a community to keep the data up to date.

We want this directory to be useful to everyone in the city, so we are working with city staff and community groups to build a community of people who need up-to-date information about groups. We want new residents to be able to find useful groups in their neighborhood, or for a community organizer to be able to invite all the groups along a parade route to participate in the parade.

<h3>Our goals</h3>
<ul>
<li>To make it easy to find groups. <a href="/contact">Not easy? Please contact us to give us your feedback.</a></li>
<li>To keep our service simple. We just list groups by geography & topic. We aim to do that well. We provide an API for everything else.</li>
<li>To be technology agnostic with respect to the technology used by a community group. We aim to list groups from any technology that provides a URL or Email address. These could be Meetup, Facebook pages, or just simply a personal email address for someone who reaches out to communities that are not online.</li>
<li>To make it easy to add data you already have. <a href="/user">Join</a> our community to import CSV data.</li>
<li>To provide structure for describing groups. <a href="/data-standard-community-groups">See our data standard.</a></li>
<li>To make it easy for community organizers and city employees to keep the information up to date.</li>
<li>To make it easy for community members to add new groups and update out-of-date groups</li>
<li>To make it easy to add helpful information about the groups, like geographic service area (location) and metadata (tags)</li>
<li>To make it easy to get information out of the directory, using a public API (<a href="/data/community-group/csv">CSV</a> & <a href="/data/community-group">JSON</a>). (Then developers can build new services on top of the group listings, such as a cool map, or an text-message service, or group-to-group notification system.</li>
</ul>',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>There is a reason why we do not already have a city-wide groups directory already: it requires the participation of a community to keep the data up to date.</p>
<p>We want this directory to be useful to everyone in the city, so we are working with city staff and community groups to build a community of people who need up-to-date information about groups. We want new residents to be able to find useful groups in their neighborhood, or for a community organizer to be able to invite all the groups along a parade route to participate in the parade.</p>
<h3>Our goals</h3>
<ul><li>To make it easy to find groups. <a href="/contact">Not easy? Please contact us to give us your feedback.</a></li>
<li>To keep our service simple. We just list groups by geography &amp; topic. We aim to do that well. We provide an API for everything else.</li>
<li>To be technology agnostic with respect to the technology used by a community group. We aim to list groups from any technology that provides a URL or Email address. These could be Meetup, Facebook pages, or just simply a personal email address for someone who reaches out to communities that are not online.</li>
<li>To make it easy to add data you already have. <a href="/user">Join</a> our community to import CSV data.</li>
<li>To provide structure for describing groups. <a href="/data-standard-community-groups">See our data standard.</a></li>
<li>To make it easy for community organizers and city employees to keep the information up to date.</li>
<li>To make it easy for community members to add new groups and update out-of-date groups</li>
<li>To make it easy to add helpful information about the groups, like geographic service area (location) and metadata (tags)</li>
<li>To make it easy to get information out of the directory, using a public API (<a href="/data/community-group/csv">CSV</a> &amp; <a href="/data/community-group">JSON</a>). (Then developers can build new services on top of the group listings, such as a cool map, or an text-message service, or group-to-group notification system.</li>
</ul>',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['developers'] = (object)array(
  'exported_path' => 'developers',
  'title' => 'Developers',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1314038594',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'developers',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Developers...</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Developers...</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}
