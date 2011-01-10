#include <stdlib.h>
#include <stdio.h>

#include "../include/defines.h"
#include "session.h"
#include "../request/request.h"




int session_init(struct _session ** sess, request * req);
{

	(*sess) = (struct _session *) malloc(sizeof( struct _session ));
	bzero( (char * ) &(*sess), sizeof( (*sess)));
	
	uuid_generate( &(*sess)->uuid );

		
	



}
