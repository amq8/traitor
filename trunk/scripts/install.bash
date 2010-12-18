#!/bin/bash

CURRENTDIR=`pwd`
TOPDIR=${CURRENTDIR}/..
TALIBDIR=${TOPDIR}/ta-lib
LUADIR=${TOPDIR}/lua
CAKEDIR=${TOPDIR}/cake
SCHEMEA=${TOPDIR}/cake/schema.sql

echo "This script will help you build the environment and prepare talib,cakephp, and lua for development"
echo "Would you like to install ta-lib?"
echo -n "[y/N] "
read -e INSTALL_TA_LIB
INSTALL_TA_LIB=`echo $INSTALL_TA_LIB | tr '[A-Z]' '[a-z]'`

if [ -z $INSTALL_TA_LIB ]; then
	INSTALL_TA_LIB="n"
fi

if [ $INSTALL_TA_LIB = "n" ]; then
	echo "Skipping ta-lib"
else
	cd $TALIBDIR
	./configure
	make
	sudo make install
fi


echo "Would you like to install lua?"
echo -n "[y/N] "
read -e INSTALL_LUA
INSTALL_LUA=`echo $INSTALL_LUA | tr '[A-Z]' '[a-z]'`

if [ -z $INSTALL_LUA ]; then
	INSTALL_LUA="n"
fi

if [ $INSTALL_LUA = "n" ]; then
	echo "Skipping LUA install"
else
	cd $LUADIR
	./configure
	make
	sudo make install	
fi

echo "Would you like to install cakephp?"
echo -n "[y/N] "
read -e INSTALL_CAKE
INSTALL_CAKE=`echo $INSTALL_CAKE | tr '[A-Z]' '[a-z]'`

if [ -z $INSTALL_CAKE ]; then
	INSTALL_CAKE="n"
fi

if [ $INSTALL_CAKE = "n" ]; then
	echo "Skipping cakephp install"
else
	echo "Please supply the path to your web server"
	read -e WEB_PATH
	sudo ln -s $CAKEDIR $WEB_PATH/traitor
fi

echo "Would you like to update your cakephp table definition?"
echo -n "[Y/n] "
read -e UPDATE_DB
UPDATE_DB=`echo $UPDATE_DB | tr '[A-Z]' '[a-z]'`

if [ -z $UPDATE_DB ]; then
	UPDATE_DB="y"
fi

if [ $UPDATE_DB = "n" ]; then
	echo "Skippping Update"
else
	if [ -e $SCHEMA ]; then

		echo "Found Configuration"
		echo "DB NAME " 
		read -e DB_NAME
		echo "USER NAME " 
		read -e USER_NAME
		mysql -p -u $USER_NAME $DB_NAME < $SCHEMA 
	
	else
	
		echo "No Configuration found"
	fi
fi


echo "Done"
echo ""
