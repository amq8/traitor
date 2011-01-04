

#include <dlfcn.h>


struct _module
{
	int (*execute)(struct _session * sess);
	
};



