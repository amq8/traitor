#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "../defines.h"

int parser_init(configuration ** config, const char * file)
{
	*config = (configuration * ) malloc(sizeof(configuration));
	//bzero( (*config)->file_name,1024);
	bzero( (*config),  sizeof(configuration));
	strcpy( (*config)->file_name, file);
	
		
	//bzero((*config)->quote_port_number,32);
	//bzero((*config)->quote_ip_address,128);
	//bzero((*config)->script_port_number,32);
	//bzero((*config)->script_ip_address,128);



	printf("Opening file %s\n", file);
	(*config)->pfile = fopen((*config)->file_name, "r");
	if( (*config)->pfile == NULL)
		goto error;


	//this always returns SUCCESS i think*
	return SUCCESS;
	
	error:
		printf("Error in parser init\n");
		return FAILURE;

}


int parser_parse(configuration **config)
{
	int i = 0;
	int n = 0;
	
	int start;
	int end;
	

	//local  = 0
	//remote = 1
	int context;
	
	if( CONFIG_FALSE == config_read_file( &(*config)->config, (*config)->file_name))
	{
		printf("Error opening configuration file");
		config_error_file( &(*config)->config);
		config_error_line( &(*config)->config);
		config_error_text( &(*config)->config);
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

	if((*config)->pfile)
	//	fclose(config->pfile);
		
	if(config)
	//	free(config);
	
	return SUCCESS;
}

