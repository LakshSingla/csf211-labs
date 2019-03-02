SRC = main.c queue.c
OBJ = $(SRC:.c=.o)
EXE = a.out

CC = gcc
FLAGs = -Wall

queue: $(OBJ)
	gcc -o $(FLAGS) $(EXE) $(OBJ)

%.o: %.c
	gcc -c $(FLAGS) $*.c
