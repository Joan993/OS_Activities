main_v2: Pokemon.o Main.o
	gcc Main.o Pokemon.o -o Main
main_v2.o: Pokemon.c Main.c
	gcc -Wall -Wextra -std=c11 -c Pokemon.c Main.c
clean:
	/bin/rm -rf *.o Main
execute:
	./Main