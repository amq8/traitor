CC		  = gcc
PWD		  = $(shell pwd)
CFLAGS    = -g -Wall 
LDFLAGS   = -lconfig -lpthread -luuid
HDRS      = core.h server.h session.h sesion_manager.h \
			request.h module.h defines.h
SRCS      = core.c parser.c session.c server.c \
			session_manager.c 
OBJS      = $(SRCS:.c=.o)
EXEC	  = gbsd



default : all-libs 
	$(CC)  $(CFLAGS)  -I/usr/include/mysql -I$(PWD)/include core.o  parser.o server.o \
	 session.o session_manager.o  $(LDFLAGS) -o $(EXEC)

all-libs: parser.o server.o session.o session_manager.o core.o

clean : 
	rm -f *.o *.bak core *.so test gbsd *.out

core.o : core.c 
	$(CC) -c $(CFLAGS) core.c -I$(PWD)/include $(LDFLAGS) -I/usr/include/mysql -o core.o

parser.o : parser.c 
	$(CC) -c $(CFLAGS) parser.c -I$(PWD)/include $(LDFLAGS) -o parser.o

server.o : server.c 
	$(CC) -c $(CFLAGS) server.c -I$(PWD)/include $(LDFLAGS) -o server.o

session.o : session.c
	$(CC) -c $(CFLAGS) session.c -I$(PWD)/include $(LDFLAGS) -o session.o

session_manager.o : session_manager.c
	$(CC) -c $(CFLAGS) session_manager.c -I$(PWD)/include $(LDFlAGS) -o session_manager.o
