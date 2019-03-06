SRC = main.c qsort.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall
EXE = a.out

main: $(OBJ)
	gcc -o $(EXE) $(FLAG) $(OBJ)

%.o: %.c
	gcc -c $(FLAG) $*.c
