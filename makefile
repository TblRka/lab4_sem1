CC=gcc

CFLAGS=-c -Wall

LDFLAGS=

SRCS=lab4.c sorts.c processing.c readline.c output.c input.c

OBJS=$(SRCS:.c=.o)

EXE=lab4

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJS) $(EXE)