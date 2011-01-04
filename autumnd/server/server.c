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
//#include "../session/session.h"
//#include "../session_manager/session_manager.h"

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

	
	while(1)
	{
		listen( (*server)->sockfd, 10);
		(*server)->clientlength = sizeof( (*server)->cli_addr);
	
		(*server)->newsockfd = accept( (*server)->sockfd, 
										(struct sockaddr *) &(*server)->cli_addr, 
										&(*server)->clientlength);

		printf("Socket fd %d\n" , (*server)->newsockfd);
		pthread_create(&t, NULL, handle_connection, ( void * ) (*server)->newsockfd );

	}	

	//n = read( (*server)->newsockfd, (*server)->buffer, MAX_DATA);
	//printf("Buffer %s\n",(*server)->buffer);
}


void *handle_connection(void * data)
{
		
	int * n;
	n = (int *) data;
	
	int count;
	char buffer[1024];
	bzero(buffer, 1024);

	count = read( n, buffer, 1024);
	printf("Buffer : %s\n",buffer);


}

