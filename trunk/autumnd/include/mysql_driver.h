#ifndef MYSQL_DRIVER_H
#define MYSQL_DRIVER_H

#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include "parser.h"

typedef struct _mysql_driver
{

	char mysql_host[64];
	char mysql_password[64];
	char mysql_user[64];
	char mysql_db[64];

	MYSQL * conn;
	MYSQL_RES * res;
	MYSQL_ROW * row;

} mysql_driver;


int mysql_driver_init(struct _mysql_driver ** sql, configuration **config);
int mysql_driver_get_script(struct _mysql_driver ** sql);
int mysql_driver_get_quote(struct _mysql_driver ** sql);
int mysql_driver_close(struct _mysql_driver ** sql);
	
#endif
