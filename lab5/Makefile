SRC = main.c reader.c sort.c
OBJ = $(SRC:.c=.o)
EXE = a.out

CC = gcc
CFLAGS = -Wall

main: $(OBJ)
	$(CC) -o $(EXE) $(OBJ)	

%.o : %.c
	$(CC) -pg $(CFLAGS) -c $*.c

debug: $(OBJ)
	$(CC) -pg -o $(EXE) $(OBJ)	

clean:
	rm -rf $(OBJ) $(EXE)
