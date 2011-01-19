#ifndef SESSION_H
#define SESSION_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <uuid/uuid.h>

#include "request.h"

union spec_request
{
		struct _script_execution_request * s_req;
		struct _quote_execution_reuqest * q_req;

};


typedef struct _session
{
	uuid_t uuid;
	struct _generic_request * request;

	union spec_request * srequest;	
		


} session;


int session_init( struct _session ** session, struct _generic_request * req);
int session_cleanup(struct _session ** session);

#endif
