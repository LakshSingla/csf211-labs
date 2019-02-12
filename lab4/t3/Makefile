SRC = main.c create_list.c test_cycle.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall
EXE = a.out

$(EXE): $(OBJ)
	$(CC) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

clean:
	rm -f $(EXE) $(OBJ)
