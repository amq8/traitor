#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "session_manager.h"
#include "session.h"
#include "defines.h"

void session_manager_init( struct _session_manager ** sess_man)
{
	(*sess_man) = (struct _session_manager * ) malloc(sizeof(struct _session_manager));
	memset( (*sess_man), '\0', sizeof(struct _session_manager));

	(*sess_man)->session_list = (struct _session_list *) malloc(sizeof(struct _session_list));
	memset( (*sess_man)->session_list, '\0', sizeof(struct _session_list));
	
	(*sess_man)->session_list->size = 0;
}

void append_node(struct _session_list ** list, struct _session * session)
{
	struct _session_list_node *t, *cur;
	cur = (*list)->head;
	t = (struct _session_list_node * ) malloc(sizeof(struct _session_list_node));
	memset(t, '\0', sizeof(struct _session_list_node));
	t->data = session;

	if( (*list)->size == 0)
	{
		(*list)->head = t;
		(*list)->size++;
	}
	else
	{
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		
		cur->next = t;
		(*list)->size++;
	}
	return;
}

int delete_node(struct _session_list ** list, uuid_t uuid)
{
	struct _session_list_node *prev, *cur;
	int dflag;
	dflag = 0;
	cur = (*list)->head;

	if( ((*list)->size == 1 ) && (cur->data == uuid) )
	{
		//Free the data but dont free the head, well just reuse it
		free(cur->data);
		memset(cur, '\0', sizeof(struct _session_list_node));
		(*list)->size = 0;
	}
	else
	{
		while(cur->data->uuid != uuid)
		{
			prev = cur;
			cur = cur->next;
			if(cur->data->uuid == uuid)
			{
				dflag = 1;
			}
		}
	}
	

	prev->next = cur->next;
	free(cur->data);
	free(cur);

	if(dflag == 1)
	{
		return SUCCESS;	
		(*list)->size--;
	}
	else
		return FAILURE;
}

struct _session * get_session_handle(struct _session_list ** list, uuid_t uuid)
{
	struct _session_list_node *cur;
	cur = (*list)->head;
	
	while( cur->data->uuid != uuid)
	{
		cur = cur->next;
	}

	return cur;
}
