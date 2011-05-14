-- phpMyAdmin SQL Dump
-- version 3.3.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1:4469
-- Generation Time: Feb 23, 2011 at 09:10 PM
-- Server version: 5.1.41
-- PHP Version: 5.2.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `drupal`
--

-- --------------------------------------------------------

--
-- Table structure for table `feeds_importer`
--

CREATE TABLE IF NOT EXISTS `feeds_importer` (
  `id` varchar(128) NOT NULL DEFAULT '' COMMENT 'Id of the fields object.',
  `config` text COMMENT 'Configuration of the feeds object.',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Configuration of feeds objects.';

-- --------------------------------------------------------

--
-- Table structure for table `feeds_item`
--

CREATE TABLE IF NOT EXISTS `feeds_item` (
  `entity_type` varchar(64) NOT NULL DEFAULT '' COMMENT 'The entity type.',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The imported entity’s serial id.',
  `id` varchar(128) NOT NULL DEFAULT '' COMMENT 'The id of the importer that created this item.',
  `feed_nid` int(10) unsigned NOT NULL COMMENT 'Node id of the source, if available.',
  `imported` int(11) NOT NULL DEFAULT '0' COMMENT 'Import date of the feed item, as a Unix timestamp.',
  `url` text NOT NULL COMMENT 'Link to the feed item.',
  `guid` text NOT NULL COMMENT 'Unique identifier for the feed item.',
  `hash` varchar(32) NOT NULL DEFAULT '' COMMENT 'The hash of the source item.',
  PRIMARY KEY (`entity_type`,`entity_id`),
  KEY `id` (`id`),
  KEY `feed_nid` (`feed_nid`),
  KEY `lookup_url` (`entity_type`,`id`,`feed_nid`,`url`(100)),
  KEY `lookup_guid` (`entity_type`,`id`,`feed_nid`,`guid`(100)),
  KEY `global_lookup_url` (`entity_type`,`url`(100)),
  KEY `global_lookup_guid` (`entity_type`,`guid`(100)),
  KEY `imported` (`imported`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Tracks items such as nodes, terms, users.';

-- --------------------------------------------------------

--
-- Table structure for table `feeds_log`
--

CREATE TABLE IF NOT EXISTS `feeds_log` (
  `flid` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Primary Key: Unique feeds event ID.',
  `id` varchar(128) NOT NULL DEFAULT '' COMMENT 'The id of the importer that logged the event.',
  `feed_nid` int(10) unsigned NOT NULL COMMENT 'Node id of the source, if available.',
  `log_time` int(11) NOT NULL DEFAULT '0' COMMENT 'Unix timestamp of when event occurred.',
  `request_time` int(11) NOT NULL DEFAULT '0' COMMENT 'Unix timestamp of the request when the event occurred.',
  `type` varchar(64) NOT NULL DEFAULT '' COMMENT 'Type of log message, for example "feeds_import"."',
  `message` longtext NOT NULL COMMENT 'Text of log message to be passed into the t() function.',
  `variables` longblob NOT NULL COMMENT 'Serialized array of variables that match the message string and that is passed into the t() function.',
  `severity` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'The severity level of the event; ranges from 0 (Emergency) to 7 (Debug)',
  PRIMARY KEY (`flid`),
  KEY `id` (`id`),
  KEY `id_feed_nid` (`id`,`feed_nid`),
  KEY `request_time` (`request_time`),
  KEY `log_time` (`log_time`),
  KEY `type` (`type`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COMMENT='Table that contains logs of feeds events.' AUTO_INCREMENT=5 ;

-- --------------------------------------------------------

--
-- Table structure for table `feeds_push_subscriptions`
--

CREATE TABLE IF NOT EXISTS `feeds_push_subscriptions` (
  `domain` varchar(128) NOT NULL DEFAULT '' COMMENT 'Domain of the subscriber. Corresponds to an importer id.',
  `subscriber_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'ID of the subscriber. Corresponds to a feed nid.',
  `timestamp` int(11) NOT NULL DEFAULT '0' COMMENT 'Created timestamp.',
  `hub` text NOT NULL COMMENT 'The URL of the hub endpoint of this subscription.',
  `topic` text NOT NULL COMMENT 'The topic URL (feed URL) of this subscription.',
  `secret` varchar(128) NOT NULL DEFAULT '' COMMENT 'Shared secret for message authentication.',
  `status` varchar(64) NOT NULL DEFAULT '' COMMENT 'Status of subscription.',
  `post_fields` text COMMENT 'Fields posted.',
  PRIMARY KEY (`domain`,`subscriber_id`),
  KEY `timestamp` (`timestamp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='PubSubHubbub subscriptions.';

-- --------------------------------------------------------

--
-- Table structure for table `feeds_source`
--

CREATE TABLE IF NOT EXISTS `feeds_source` (
  `id` varchar(128) NOT NULL DEFAULT '' COMMENT 'Id of the feed configuration.',
  `feed_nid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Node nid if this particular source is attached to a feed node.',
  `config` text COMMENT 'Configuration of the source.',
  `source` text NOT NULL COMMENT 'Main source resource identifier. E. g. a path or a URL.',
  `state` longtext COMMENT 'State of import or clearing batches.',
  `fetcher_result` longtext COMMENT 'Cache for fetcher result.',
  `imported` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Timestamp when this source was imported last.',
  PRIMARY KEY (`id`,`feed_nid`),
  KEY `id` (`id`),
  KEY `feed_nid` (`feed_nid`),
  KEY `id_source` (`id`,`source`(128))
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Source definitions for feeds.';
