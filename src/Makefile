CC=gcc
CFLAGS=-O0 -g -Wall -Werror
LDFLAGS=-lGLU -lGL -lglut -lGLEW
SOURCES=main.c
PROG=mycraft
OBJS=$(SOURCES:.c=.o)

all: $(SOURCES) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS) $(PROG)
