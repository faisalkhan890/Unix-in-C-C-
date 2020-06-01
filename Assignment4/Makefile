LEX = flex
LFLAGS = 
CC = gcc
CFLAGS = -Werror
#	$(YACC) $(YFLAGS)
YACC = bison
YFLAGS = -dy

PROJECTNAME = Postal_address

EXECFILE = Program4

OBJS = yakk.o flex.o main.o

.PHONY: all clean

all: $(EXECFILE)
	ln -sf $(EXECFILE) scanner
	ln -sf $(EXECFILE) parser

clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h flex.c yakk.c *- \ *

$(EXECFILE):	$(OBJS)
	$(CC) $(OBJS) -o $@
backup:
	@make clean
	@mkdir -p ~/backups: chmod 700 ~/backups
	@$ 
