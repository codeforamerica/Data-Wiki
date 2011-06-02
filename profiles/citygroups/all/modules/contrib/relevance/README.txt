
SUMMARY
------

The main objective of relevancy module is to provide a block of related content that can be extensivelly configured, according to the website needs.

It seeks for relevant content by making a kind of 'score' rate for each relevant data. All the relevant data are summed and the greater ones are showed on a block.

For more details about Relevance, please see: http://en.wikipedia.org/wiki/Relevance_(information_retrieval)


Requirements
------------

Relevance module uses *taxonomy module* a lot. I've never tested it with Category, but I don't think there will be any problem (if anyone do, please tell me!).

Optionally, you can use the drupal generated statistics. The relevance by statistics generate a *bonus* for the most visited pages.


Installation
------------

Just unpack it on your modules folder and activate it on admin/build/modules page.


USAGE
-----

=> SETTINGS

After installing it, visit admin/settings/relevance. Basically, website admins must choose witch itens are important to define it's own relevance and also defines a factor - something like a 'weight' - for each one. 

The factor is a multiplier that's gonna increase/decrease the importance of that item. Please note that this value is not fixed; it depends on other values defined on the setting. Should be an integer between 1 and 9.

The settings are separated by groups:

-> taxonomy:
 All vocabularies of the current system will be displayed. Users can enable each one and, if enabled, should assign a factor for it.

-> statistics:
 [Depends on statistics module]
 It can be enabled or not. If enabled, you should set a value for it's factor.

-> dates:
 It's possible to enable relevancy by proximity. For all the kinds of dates, it's considered the period before and after. 
i.e.: the relevant period for the date nov 03 / 2008 will be all nodes between nov 2 / 2008 and nov 4 / 2008.

-> display options:
 Configure how many itens will appear on the block.

=> ACTIVATE THE BLOCK
 After configuring your personalized setttings, visit admin/build/block and place the block called 'relevant content' somewhere.
