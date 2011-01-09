#include <stdlib.h>
#include <stdio.h>

#include "session_manager.h"
#include "../session/session.h"





void session_manager_init( struct _session_manager ** sess_man)
{
	(*sess_man) = (struct _session_manager * ) malloc(sizeof(struct _session_manager));
	memset( (*sess_man), '\0', sizeof(struct _session_manager));

	(*sess_man)->list = (struct _session_list_node *) malloc(sizeof(struct _session_list_node));
	memset( (*sess_man)->list, '\0', sizeof(struct _session_list_node));
	
	(*sess_man)->list.size = 0;
}

void append_node(struct _session_list_node ** list, struct _session * session)
{
	struct  _session_list_node * cur, *t;
	memset(t, '\0', sizeof(struct _session_list_node));
	t = (struct _session_list_node * ) malloc(sizeof(struct _session_list_node));
	t->data = session;

	if( (*list).size == 0)
	{
		(*list)->head = t;
	}
	else
	{
		cur = (*list)->head;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		
		cur->next = t;
		(*list).size++;
	}

	return;

}

int delete_node(struct _session_list_node ** list, uuid_t uuid)
{
	struct _session_list_node *prev, *cur, *t;
	int dflag;
	dflag = 0;
	cur = (*list)->head;

	if( ((*list).size == 1 ) && (cur.data == uuid) )
	{
		//Free the data but dont free the head, well just reuse it
		free(cur->data);
		memset(cur, '\0', sizeof(struct _session_list_node));
		(*list).size = 0;
		dflag = 1;	
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
	(*list).size--;
	free(cur->data);
	free(cur);

	if(dflag == 1)
		return SUCCESS;	
	else
		return FAILURE;
}

struct _session * get_session_handle(struct _session_list_node ** list, uuid_t uuid)
{
	struct _session *cur;
	cur = (*list)->head;

	while( cur->data.uuid != uuid)
	{
		cur = cur->next;
	}

	return cur;
}

