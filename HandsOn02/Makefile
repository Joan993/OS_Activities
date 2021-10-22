EXEC     = $(shell basename $$(pwd))
CC       = gcc

CFLAGS   = -Wall -Wextra
LDLIBS = -lm
LDFLAGS = 

SRC      = $(wildcard *.c)
OBJ      = $(SRC:.c=.o)
EXEC = $(SRC:%.c=%)



all: ${EXEC}

%.o.:
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean run

clean:
	@rm -rf *.o $(EXEC)

# Per fer-ho anar:
# make
# make ACT-02
# make ACT-03
# make ACT-04
# make clean per netejar


