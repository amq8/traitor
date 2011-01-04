CC		  = gcc
PWD		  = `pwd`
CFLAGS    = -g -Wall 
LDFLAGS   =
HDRS      = mysql_driver.h
SRCS      = mysql_driver.c 
TEST	  = test.c
OBJS      = $(SRCS:.c=.o)
EXEC	  = mysql_driver

default : $(SRCS) 
	$(CC) -c $(CFLAGS) $(SRCS) -o $(EXEC) -I/usr/include/mysql

loadable: $(SRCS)
	$(CC) -Wall -fPIC -c $(SRCS) -I/usr/include/mysql -lmysqlclient
	$(CC) -shared -Wl,-soname,mysql_loadable.so -o mysql_loadable.so *.o -lmysqlclient

test : test.c ../parser/parser.c
	echo "Building Reg Test"
	$(CC) $(CFLAGS) -o test $(SRCS) ../parser/parser.c $(TEST) -I/usr/include/mysql

test-loadable : $(TEST) ../parser/parser.c
	$(CC) -rdynamic -o test test.c ../parser/parser.c -ldl -g -I/usr/include/mysql
		
clean : 
	rm -f *.o *.bak core *.so test mysql_driver *.out

