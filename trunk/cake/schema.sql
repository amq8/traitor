-- MySQL dump 10.13  Distrib 5.1.37, for debian-linux-gnu (i486)
--
-- Host: localhost    Database: traitor
-- ------------------------------------------------------
-- Server version	5.1.37-1ubuntu5.4

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `dashboards`
--

DROP TABLE IF EXISTS `dashboards`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dashboards` (
  `uuid` binary(36) NOT NULL,
  `user_id` binary(36) NOT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dashboards`
--

LOCK TABLES `dashboards` WRITE;
/*!40000 ALTER TABLE `dashboards` DISABLE KEYS */;
/*!40000 ALTER TABLE `dashboards` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quotes`
--

DROP TABLE IF EXISTS `quotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quotes` (
  `uuid` varchar(36) NOT NULL,
  `date` date NOT NULL,
  `open` float NOT NULL,
  `high` float NOT NULL,
  `low` float NOT NULL,
  `close` float NOT NULL,
  `volume` float NOT NULL,
  `adj_close` float NOT NULL,
  `symbol` varchar(32) NOT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quotes`
--

LOCK TABLES `quotes` WRITE;
/*!40000 ALTER TABLE `quotes` DISABLE KEYS */;
INSERT INTO `quotes` VALUES ('4d0c74f0-22f8-419d-a6aa-5bc78d6a6177','2010-12-17',321.63,321.79,320.23,320.61,1.38189e+07,320.61,'appl'),('4d0c74f0-5c1c-4255-bc90-5bc78d6a6177','2010-12-16',321.09,322.61,320.1,321.25,1.14835e+07,321.25,'appl'),('4d0c74f0-ea8c-4ea4-9092-5bc78d6a6177','2010-12-15',320,323,319.19,320.36,1.4836e+07,320.36,'appl'),('4d0c74f0-dc50-46fe-a4c0-5bc78d6a6177','2010-12-14',321.73,322.54,319,320.29,1.2536e+07,320.29,'appl'),('4d0c74f0-c5a0-40ff-88f7-5bc78d6a6177','2010-12-13',324.37,325.06,321,321.67,1.5674e+07,321.67,'appl'),('4d0c74f0-1ae4-4d0f-8a92-5bc78d6a6177','2010-12-10',319.65,321.05,318.6,320.56,9.3754e+06,320.56,'appl');
/*!40000 ALTER TABLE `quotes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tools`
--

DROP TABLE IF EXISTS `tools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tools` (
  `uuid` binary(36) NOT NULL,
  `dashboard_id` binary(36) NOT NULL,
  `name` text NOT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tools`
--

LOCK TABLES `tools` WRITE;
/*!40000 ALTER TABLE `tools` DISABLE KEYS */;
/*!40000 ALTER TABLE `tools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `uuid` binary(36) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(64) NOT NULL,
  `group_id` int(10) NOT NULL,
  `active` tinyint(1) NOT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2010-12-18  4:12:57
