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


void parser_parse(configuration **config)
{
	char temp[1024];
	int i = 0;
	int n = 0;
	
	int start;
	int end;
	

	//local  = 0
	//remote = 1
	int context;
	

	bzero(temp,1024);

	while(!feof( (*config)->pfile))
	{
		
		temp[i] = fgetc( (*config)->pfile);
	

	
		if(temp[i] == '\n')
		{
			printf("In new line\n");
			if(strstr(temp,"local"))
			{
				context = 0;
				
			}
			else if(strstr(temp,"remote"))
			{
				context = 1;
			}
			
			if(strstr(temp,"quote_port_number"))
			{
				printf("Found Quote Port number\n");
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->quote_port_number, (size_t) end-start, "%s", temp + start + 1);
			}
			else if(strstr(temp,"load") && (context == 0))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;
	
					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf(  (char *) (*config)->load[ (*config)->load_count ], (size_t) end-start, "%s", temp + start + 1);
				(*config)->load_count++;
			}
			else if(strstr(temp,"mysql_host"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->mysql_host, (size_t) end-start, "%s", temp + start + 1);

			}
			else if(strstr(temp, "mysql_password"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->mysql_password, (size_t) end-start, "%s", temp + start + 1);
			}
			else if(strstr(temp,"mysql_db"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->mysql_db, (size_t) end-start, "%s", temp + start + 1);
			}
			else if(strstr(temp,"mysql_user"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->mysql_user, (size_t) end-start, "%s", temp + start + 1);

			}
			else if(strstr(temp, "quote_ip_address"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->quote_ip_address, (size_t) end-start, "%s", temp + start + 1);

			}
			else if(strstr(temp,"script_ip_address"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->script_ip_address, (size_t) end-start, "%s", temp + start + 1);
			}
			else if(strstr(temp,"script_port_number"))
			{
				for(n = 0; n < 1024; n++)
				{
					if(temp[n] == '=')
						start = n;

					if(temp[n] == '\n')
					{
						end = n;
						break;
					}
				}
				snprintf((*config)->script_port_number, (size_t) end-start, "%s", temp + start + 1);
			}
		
			
			printf("Current line %s\n",temp);
			bzero(temp,1024);
			i = 0;
		}
		else
		{
			i++;
		}
	}	
}

void parser_print_configuration(configuration **config)
{
	int i = 0;
	printf("Using configuration file : %s\n",(*config)->file_name);
	printf("Script Port Number : %s\n", (*config)->script_port_number);
	printf("Script Ip Address : %s\n", (*config)->script_ip_address);
	printf("Quote Port : %s\n", (*config)->quote_port_number);
	printf("Quote Ip Address : %s\n", (*config)->quote_ip_address);
	printf("\nMysql Config - local\n");
	printf("Mysql User : %s\n", (*config)->mysql_user);
	printf("Mysql Db : %s\n", (*config)->mysql_db);
	printf("Mysql Password : %s\n", (*config)->mysql_password);
	printf("Mysql Host : %s\n", (*config)->mysql_host);

	for(i = 0; i < (*config)->load_count; i++)
	{
		printf("Load local modules : %s\n", (char * ) (*config)->load[i]);
	}
}

int parser_exit(configuration **config)
{

	if((*config)->pfile)
	//	fclose(config->pfile);
		
	if(config)
	//	free(config);
	
	return SUCCESS;
}

