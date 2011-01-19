#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <poll.h>

#include "core.h"
#include "defines.h"
#include "module.h"
#include "mysql_driver.h"
#include "parser.h"
#include "server.h"
#include "request.h"
#include "session.h"
#include "session_manager.h"


#define GBSD_PACKAGE "gbsd"
#define GBSD_VERSION "wicked alpha"

static struct _gbs_core core;

void init_core()
{
	pipe(core.exiter_pipe);
	bzero(&core, sizeof(struct _gbs_core));
	core.pfd.fd = core.exiter_pipe[0];
	core.pfd.events = POLLIN;
	core.tv.tv_usec = 0;
	core.tv.tv_sec = 1;
	core.flags.need_quit = FALSE;
	
	return;	
}

int main(int argc, char * argv[])
{
	int opt;
	
	//initialize the gbs_core variable
	init_core();

	//Start up object things
	struct _configuration * config;
	struct _server * server;
	
	while((opt = getopt(argc, argv, "hVc:")) != FAILURE)
	{
		switch(opt)
		{	
			case 'h':
				print_help();
			break;
			
			case 'V':
				print_version();
			break;
			
			case 'c':
				printf("Got config file\n");		
				strncpy(core.config_file, optarg, 1024);
			break;

			case '?':
				if(optopt == 'c')
				{
					printf("c requires an option");
				}
				else
					printf("Error in getopt\n");
				exit(1);
			break;
		}
	}	
	
	if(parser_init(&config,core.config_file) == FAILURE)
	{
		goto error;
	}

	if(FAILURE == parser_parse(&config))
	{
		goto error;
	}
		
	init_server(&server,config);
	
	monitor_sig_flags();
	
	return 0;

error:
	printf("Failed on startup\n");
	return 0;
}


int monitor_sig_flags()
{
	int ipoll;
	char buffer[1024];
	for(;;)
	{
		ipoll = poll(&core.pfd , 1 , core.tv.tv_sec);
		if(ipoll > 0)
		{
			bzero(buffer,1024);
			if(-1 != read(core.exiter_pipe[0], buffer, (size_t) 1024))
			{
				if(strstr(buffer,"NEED_QUIT"))
				{
					core.flags.need_quit = TRUE;
				}
			}
	
		}
		
		if(core.flags.need_quit)
		{
			//Call cleanup stuff here
			printf("Quit Here\n");
			exit(0);
		}
	}
}

void print_help()
{
	printf("%s,%s gbsd server options usage\n", GBSD_PACKAGE, GBSD_VERSION); 
	printf("%s [-h] [-V] [-c FILE]\n\n", GBSD_PACKAGE);
	printf("  -h              print this help and exit\n");
	printf("  -V              print version and exit\n");
 	printf("  -c FILE         configuration file\n\n");

	exit(0);
}

void print_version()
{
	printf("gbsd Version %s\n",GBSD_VERSION);
	exit(0);
}
