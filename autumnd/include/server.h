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

#include "defines.h"
#include "parser.h"
#include "request.h"

struct _gbsd_server
{
    int sockfd;
	int newsockfd;
	long portno;
	int clientlength;
	int listening;	

    char buffer[MAX_DATA];
    
	struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
	struct hostent *host;
	

	struct _configuration * config;

};

int init_server(struct _gbsd_server **server, configuration * configuration);
int add_session(struct  _generic_request * req);
void *listener( void *  data);
void handle_request(void * data);
void *handle_connection(void * data);

		


#endif
