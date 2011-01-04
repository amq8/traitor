
#include <stdio.h>
#include <stdlib.h>

#include "server.h"
#include "../parser/parser.h"


int main()
{
	
	server * server;
	configuration * configuration;
		

	parser_init(&configuration,"../parser/config.cfg");
	parser_parse(&configuration);

	init_server(&server,configuration);

	return 0;
}
