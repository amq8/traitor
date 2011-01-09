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
#include "../defines.h"
//#include "../request_handler/request_handler.h"
#include "../session/session.h"
#include "../session_manager/session_manager.h"

static struct _session_manager * session_man;

int init_server(server ** server, configuration * config)
{
	int n = 0;
	pthread_t t;
	

	*server = ( struct _server * ) malloc( (size_t) sizeof(struct _server) );
	
	(*server)->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bzero( (char *) &(*server)->serv_addr, sizeof((*server)->serv_addr));
	
	(*server)->portno = atoi(config->quote_port_number);
	(*server)->serv_addr.sin_family = AF_INET;
	(*server)->serv_addr.sin_addr.s_addr = INADDR_ANY;
	(*server)->serv_addr.sin_port = htons((*server)->portno);
	
	bind( (*server)->sockfd, (struct sockaddr *) &(*server)->serv_addr,sizeof( (*server)->serv_addr));
	pthread_create(&t, NULL, listener, (void * ) *server);	



	}	

	return SUCCESS;
}

void *listener( (void * ) data);
{
	//this prolly needs to be locked here, and...
	struct _server * server = (struct _server *) data;	
	struct pthread_mutex_t  mutex;
	
	mutex = PTHREAD_MUTEX_INITIALIZER;
	

	while(*server->listening)
	{
		//I think this needs to be here. 
		//not sure but id be concerned about newsockfd
		pthread_mutex_lock(&mutex);	
		listen( (*server)->sockfd, 10);
		(*server)->clientlength = sizeof( (*server)->cli_addr);
		printf("Socket fd %d\n" , (*server)->newsockfd);
		(*server)->newsockfd = accept( (*server)->sockfd, 
										(struct sockaddr *) &(*server)->cli_addr, 
										&(*server)->clientlength);
		
		//This is where we add a new session to the session manager;
		printf("Accepted new client\n");
		pthread_create(&t, NULL, handle_request, ( void * ) (*server)->newsockfd );
		pthread_mutex_unlock(&mutex);
	}
}

void handle_request(void * data)
{
	print("Got it in new thread\n");
		
	int * n;
	n = (int *) data;
	
	int count;
	char buffer[1024];
	bzero(buffer, 1024);

	while(count != 0)
	{
		count = read( n, buffer, 1024);
		printf("Buffer : %s\n",buffer);
		
	}
}


int add_session(struct * _request)
{

	
	


	return SUCCESS;

error:
	return FAILURE

}
