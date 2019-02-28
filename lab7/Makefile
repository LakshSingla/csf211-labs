SRC = main.c utils.c sort.c
OBJ = $(SRC:.c=.o)
EXE = a.out
LIB = 

CC = gcc
FLAGS = -Wall

main: $(OBJ)
	$(CC) $(FLAGS) -o $(LIB) $(EXE) $(OBJ) 

%.o: %.c
	$(CC) $(FLAGS) -c $*.c

