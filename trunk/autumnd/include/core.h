#ifndef CORE_H
#define CORE_H

#include <unistd.h>
#include <poll.h>


#define FALSE (0)
#define TRUE  (1)


struct sig_flags
{
	unsigned int need_quit;
};

struct _gbs_core {
	char config_file[1024];
	
	struct pollfd pfd;
	struct sig_flags flags;
	struct timeval tv;

	//our pipe fds
	int exiter_pipe[2];	


};

int monitor_sig_flags();
void init_core();
void print_version();
void print_help();

#endif
