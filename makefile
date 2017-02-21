# set compiler type
#CC=/usr/local/arm/4.3.2/bin/arm-linux-gcc
CC=gcc
# set compiler argument
#-g to generate debug info for gdb
CFLAGS=-Wall -O2 -D_REENTRANT
LDFLAGS=-L./
TARGET=zlog_demo
#-static 

all:		$(TARGET)

$(TARGET):	demo.o
		$(CC) -o $(TARGET) demo.o $(CFLAGS) $(LDFLAGS) -lzlog
		chmod 777 $(TARGET)

demo.o:		demo.c		\
		demo.h		
		$(CC) -c demo.c $(CFLAGS) 

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f *.log
	rm -f *~

