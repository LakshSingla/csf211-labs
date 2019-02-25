SRC = main.c sort.c reader.c
OBJ = $(SRC:.c=.o)

main: $(OBJ)
	gcc $(OBJ)

%.o: %.c
	gcc -c $*.c

