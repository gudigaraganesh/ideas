#          File             : Makefile
#          Description      : Building for package Applications
#          Author           : Ganesh Gudigara
#          Copyright        : Nirmitsu Technologies @ 2006
#          Created          : 28/11/2006
#
#
#          Modification   
#               History   :
#                           
#    
#
#
#
#
#
#
#

###########################################################################################################################

CC=gcc
CFLAGS += $(shell pkg-config --cflags  gtk+-2.0)
CFLAGS += -DDEBUG -I/usr/include/mysql -I./include

LDFLAGS += $(shell pkg-config --libs  gtk+-2.0) 
LDFLAGS += -L/usr/lib -L. -lz -lmysqlclient

SRCS := \
	events.c \
	database.c \
	uicontrol.c \
	inv.c \
	petrotrack.c \
	support.c 

OBJS := $(SRCS:.c=.o)

TARGET := petrotrack

all: $(TARGET)



$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)


%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $^






















clean:
	rm -f *.o $(TARGET)
