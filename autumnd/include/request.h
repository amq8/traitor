#ifndef REQUEST_H
#define REQUEST_H

#define SCRIPT_EXECUTION_REQUEST ( 1 << 0 )
#define QUOTE_REQUEST			 ( 1 << 1 )


#define MESSAGE_SEND_REQUEST	( 1 << 0 )
#define MESSAGE_ACCEPT_REQUEST	( 1 << 1 )

//FOR SENDING SIMPLE MESSAGES, IE. ID LIKE TO SEND A REQUEST
#define MESSAGE_SEND_MESSAGE	( 1 << 0)
#define MESSAGE_ACCEPT_MESSAGE	( 1 << 1)

//DEFINES FOR CAPABILITIES
//WE CAN OR THEM TOGETHER AND THEN DO A BIT
//MASK ON THE OTHER SIDE.
#define CAP_QUOTE				( 1 << 0 )
#define CAP_SCRIPT				( 1 << 1 )


typedef struct _generic_message
{
	size_t size;
	int message;

} generic_message;

typedef struct _peer_notify_message
{

	size_t size;
	unsigned int peer_ip[32];
	

} peer_notify_message;

struct _generic_request
{
	int size;
	int type;
	
	void * data;

};

typedef struct _script_execution_request
{

	unsigned char script_id[36];
	


} script_execution_request;


typedef struct _quote_request
{
	unsigned char symbol_id[36];
	

} quote_request;

#endif
