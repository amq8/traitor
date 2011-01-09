#ifndef SESSION_H
#define SESSION_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <uuid/uuid.h>

#include "./request/request.h"



typedef struct _session
{
	uuid_t uuid;
	struct _generic_request * request;

	union 
	{
		struct _script_execution_request;
		struct _quote_execution_reuqest;
	} * request;
	
		


} session;


int session_init( struct _session ** session, request * req);
int session_cleanup(struct _session ** session);

#endif
