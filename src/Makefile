CC=gcc
CFLAGS=-O0 -g -Wall -Werror
LDFLAGS=
SOURCES=main.c
PROG=mycraft
OBJS=$(SOURCES:.c=.o)

all: $(SOURCES) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS) $(PROG)
