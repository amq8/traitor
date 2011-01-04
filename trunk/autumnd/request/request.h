#ifndef REQUEST_H
#define REQUEST_H



#define SCRIPT_EXECUTION_REQUEST ( 1 << 0 )
#define QUOTE_REQUEST			 ( 1 << 1 )

typedef struct _generic_request
{
	int size;
	int type;


}

typedef struct _script_execution_request
{

	unsigned char script_id[36];
	


} script_execution_request;


typedef struct _quote_request
{
	unsigned char symbol_id[36];
	

} quote_request;




#endif
