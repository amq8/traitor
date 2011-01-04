#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "../defines.h"

int main()
{

	configuration * config;
	if(parser_init(&config,"./config.cfg") == SUCCESS)
	{
		parser_parse(&config);
		parser_print_configuration(&config);
		//parser_exit(config);
	}
	else
	{
		printf("Exit\n");
		return 0;
	}
	return 0;
}
