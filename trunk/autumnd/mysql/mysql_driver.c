#include "./mysql_driver.h"
#include "../defines.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int mysql_driver_init(struct _mysql_driver ** sql, configuration **config)
{

	(*sql) = (struct _mysql_driver *)  malloc(sizeof(struct _mysql_driver));
	bzero((*sql), sizeof(struct _mysql_driver));
	(*sql)->conn = mysql_init(NULL);

	strncpy((*sql)->mysql_host, (*config)->mysql_host, (size_t) 64);
	strncpy((*sql)->mysql_password, (*config)->mysql_password, (size_t) 64);
	strncpy((*sql)->mysql_user, (*config)->mysql_user,  (size_t) 64);
	strncpy((*sql)->mysql_db, (*config)->mysql_db, (size_t) 64);

	if(!mysql_real_connect((*sql)->conn, 
						(*sql)->mysql_host, 
						(*sql)->mysql_user, 
						(*sql)->mysql_password, 
						(*sql)->mysql_db, 0, NULL, 0))
	{
		printf("Error connecting to database : %s\n" , mysql_error((*sql)->conn));
		goto error;
	}

	error:
		return FAILURE;
}


int mysql_driver_get_script(struct _mysql_driver ** sql)
{
	
	return SUCCESS;

}

int mysql_driver_get_quote(struct _mysql_driver ** sql)
{
	
	if(mysql_query( (*sql)->conn, "show tables;"))
	{
		printf("Error in query %s\n", mysql_error( (*sql)->conn));
		goto error;
	}
	
	(*sql)->res = mysql_use_result( (*sql)->conn);

	while(( *(*sql)->row = mysql_fetch_row( (*sql)->res)))
	{
		printf("%s",*(*sql)->row[0]);
	}

	return SUCCESS;

	error:
		return FAILURE;
}

int mysql_driver_close(struct _mysql_driver ** sql)
{
	if( (*sql)->res)
		mysql_free_result( (*sql)->res);
	
	if( (*sql)->conn)
		mysql_close( (*sql)->conn);

	return SUCCESS;
}

