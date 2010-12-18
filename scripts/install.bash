#!/bin/bash

echo "This script will help you build the environment and prepare talib,cakephp, and lua for development"
echo "Would you like to install talib"
echo -n "[Y/n] "
read -e INSTALL_TA_LIB
INSTALL_TA_LIB=`echo $INSTALL_TA_LIB | tr '[A-Z]' '[a-z]'`

if [ -z $INSTALL_TA_LIB ]; then
	INSTALL_TA_LIB="y"
fi

if [ $INSTALL_TA_LIB = "n" ]; then
	echo "No"
else
	echo "Yes"

fi



