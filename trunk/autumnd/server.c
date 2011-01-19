#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#include "server.h"
#include "defines.h"
#include "session.h"
#include "session_manager.h"

static struct _session_manager * session_man;

int init_server(struct _gbsd_server ** server, configuration * config)
{
	int n;
	pthread_t t;
	config_t *cf;
	
	n = 0;
	*server = ( struct _gbsd_server * ) malloc( (size_t) sizeof(struct _gbsd_server) );
	
	(*server)->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bzero( (char *) &(*server)->serv_addr, sizeof((*server)->serv_addr));
	(*server)->listening = 1;
	//Get Port Number out of config file
	if(CONFIG_FALSE == config_lookup_int( config->config, "server.local.port_number", &(*server)->portno))
	{
		goto error;
	}
	(*server)->serv_addr.sin_family = AF_INET;
	(*server)->serv_addr.sin_addr.s_addr = INADDR_ANY;
	(*server)->serv_addr.sin_port = htons((*server)->portno);
	
	bind( (*server)->sockfd, (struct sockaddr *) &(*server)->serv_addr,sizeof( (*server)->serv_addr));
	pthread_create(&t, NULL, listener, (void * ) *server);	
	printf("Starting Server\n");
	return SUCCESS;

error:
	cf = &(*server)->config;
	printf("Error : %s\n",config_error_text(cf));
	printf("Error (line number): %d\n",config_error_line(cf));
	return FAILURE;
}

void *listener( void *  data)
{
	//this prolly needs to be locked here, and...
	struct _gbsd_server * server = (struct _gbsd_server *) data;	
	pthread_t t;
	

	while(server->listening)
	{
		//I think this needs to be here. 
		//not sure but id be concerned about newsockfd
		listen( (server)->sockfd, 10);
		(server)->clientlength = sizeof( (server)->cli_addr);
		printf("Socket fd %d\n" , (server)->sockfd);
		printf("Port number %d\n", (server)->portno);
		(server)->newsockfd = accept( (server)->sockfd, 
										(struct sockaddr *) &(server)->cli_addr, 
										&(server)->clientlength);
		
		//This is where we add a new session to the session manager;
		printf("Accepted new client\n");
		pthread_create(&t, NULL, handle_request, ( void * ) (server)->newsockfd );
	}
}

void handle_request(void * data)
{
	printf("Got it in new thread\n");
		
	int * n;
	n = (int *) data;
	
	int count;
	char buffer[1024];
	bzero(buffer, 1024);

		count = read( n, buffer, 1024);
		printf("Buffer : %s\n",buffer);
		
}


int add_session(struct  _generic_request * req)
{
	return SUCCESS;

//error:
//	return FAILURE;

}
