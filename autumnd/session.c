#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>

#include "defines.h"
#include "session.h"
#include "request.h"




int session_init(struct _session ** sess, struct _generic_request * req)
{

	(*sess) = (struct _session *) malloc(sizeof( struct _session ));
	bzero( (char * ) &(*sess), sizeof( (*sess)));
	
	uuid_generate( &(*sess)->uuid );

		
	



}
