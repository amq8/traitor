#ifndef SESSION_MANAGER_HH
#define SESSION_MANAGER_HH

#include <stdio.h>
#include <stdlib.h>

#include "../session/session.h"

//holds the session_manager
struct _session_manager
{

		struct  _session_list * list;
};

struct _session_list_node
{
	struct _session_list_node * next;
	struct _session * data;

};

//singly linked list for session manager
struct _session_list
{
    struct _session_list_node * head;
	int size;
};


void session_manager_init( struct _session_manager ** sess_man);
void append_node(struct _session_list_node ** list, struct _session * session);
void delete_node(struct _session_list_node ** list, uuid_t uuid);
struct _session * get_session_handle(struct _session_list_node ** list, uuid_t uuid);

void add_session();
void remove_session();

#endif
