#ifndef MODULE_H
#define MODULE_H

#include <dlfcn.h>
#include "session.h"

struct _module
{
	int (*execute)(struct _session * sess);
	
		

};

#endif
