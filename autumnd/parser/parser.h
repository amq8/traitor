#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct _configuration
{

	//Internal variables
	char file_name[1024];
	FILE * pfile;
	
	//storage for local modules to load
	char load[16][64];
	int load_count;

	//Configuration variables
	char quote_port_number[32];
	char quote_ip_address[128];

	char script_port_number[32];
	char script_ip_address[128];

	
	char mysql_host[64];
	char mysql_password[64];
	char mysql_user[64];
	char mysql_db[64];


} configuration;


int  parser_init( configuration ** config, const char * file);
void parser_parse( configuration ** config);
void parser_print_configuration(configuration ** config);
int  parser_exit(configuration ** config);

#endif
