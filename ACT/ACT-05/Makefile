main_v2: pokemon.o main_v2.o
	gcc main_v2.o pokemon.o -o main_v2
main_v2.o: pokemon.c main_v2.c
	gcc -Wall -Wextra -std=c11 -c pokemon.c main_v2.c
clean:
	/bin/rm -rf *.o main_v2
execute:
	./main_v2