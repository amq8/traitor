#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mysql_driver.h"
#include "../parser/parser.h"

int main(int argc, char ** argv)
{
	struct _mysql_driver * driver;
	struct _configuration * config;
	void * lib_handle;
	char * error;

	int (*fn)(struct _mysql_driver **, struct _configuration **);	

	parser_init(&config, "../parser/config.cfg");
	parser_parse(&config);
	parser_print_configuration(&config);
	
	printf("__--Mysql Config--__\n");


	lib_handle = dlopen("./mysql_loadable.so",RTLD_NOW);
	if(!lib_handle)
	{
		printf("Error %s\n", dlerror());
		exit(1);
	}

	fn = dlsym(lib_handle,"mysql_driver_init");
	if(( error = dlerror()) != NULL)
	{
		printf("Error %s\n", error);
		exit(1);
	}
	
	(*fn)(&driver,&config);
	printf("Driver passwrod %s\n",driver->mysql_password);
	dlclose(lib_handle);	
	
	return 0;
}
