#ifndef SERVER_HH
#define SERVER_HH

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#include <netinet/in.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "../defines.h"
#include "../parser/parser.h"

typedef struct _server
{
    int sockfd;
	int newsockfd;
	int portno;
	int clientlength;

    char buffer[MAX_DATA];
    
	struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
	struct hostent *host;
	

	struct _configuration * config;

}server;

int init_server(server **server, configuration * configuration);
//int register_request_handler(server ** server, request_handler * handler);

void *handle_connection(void * data);

		


#endif
