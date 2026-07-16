FLAGS = -Wall -Wextra

interpret: main.o
	cc -o _genparam-interpret $(FLAGS) main.o

main.o: main.c
	cc -o main.o -c $(FLAGS) main.c

clean:
	rm -r *.o
