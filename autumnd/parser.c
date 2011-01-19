#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libconfig.h>

#include "parser.h"
#include "defines.h"

int parser_init(configuration ** config, const char * file)
{
	if(strlen(file) == 0)
	{
		goto error;
	}

	*config = (configuration * ) malloc(sizeof(configuration));
	bzero( (*config),  sizeof(configuration));
	strcpy( (*config)->file_name, file);
	
	(*config)->config = (struct config_t *) malloc( sizeof( struct config_t));
	bzero( (*config)->config, sizeof(struct config_t));
		
	config_init( (*config)->config);
	//this always returns SUCCESS i think*
	return SUCCESS;

error:
	return FAILURE;
}


int parser_parse(configuration **config)
{
	struct config_t * cf;
	cf = (*config)->config;

	if( CONFIG_FALSE == config_read_file( (*config)->config, (*config)->file_name))
	{
		printf("Error opening configuration file");
		printf("Error %s\n", config_error_text(cf));
		printf("Error line number %d\n", config_error_line(cf));
		goto error;
	}
	return SUCCESS;

error:
	return FAILURE;	
	
}

void parser_print_configuration(configuration **config)
{

	printf("This needs to be implemented\n");
	
}

int parser_cleanup(configuration **config)
{

	if( (*config))
		free(config);
	
	return SUCCESS;
}

