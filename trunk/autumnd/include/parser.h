#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct _configuration
{

	//Internal variables
	char file_name[1024];

	//config variable
	config_t * config;
	config_setting_t * settings;
	int count;

} configuration;


int  parser_init( configuration ** config, const char * file);
void parser_parse( configuration ** config);
void parser_print_configuration(configuration ** config);
int  parser_exit(configuration ** config);

#endif
