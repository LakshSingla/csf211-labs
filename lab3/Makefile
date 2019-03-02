SRC = main.c queue.c multi_queue.c reader.c
OBJ = $(SRC:.c=.o)
EXE = a.out

CC = gcc
FLAGs = -Wall

queue: $(OBJ)
	gcc -o $(FLAGS) $(EXE) $(OBJ)

%.o: %.c
	gcc -c $(FLAGS) $*.c

clean: 
	rm -rf $(OBJ) $(EXE)
