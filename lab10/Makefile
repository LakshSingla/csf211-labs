SRC = main.c bst.c stats.c
OBJ = $(SRC:.c=.o)
EXE = a.out

CC = gcc
FLAGS = -Wall

main: $(OBJ)
	$(CC) $(FLAGS) -o $(EXE) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $*.c

clean:
	rm -rf $(OBJ) $(EXE)
