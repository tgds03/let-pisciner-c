FLAGS = -Wall -Wextra
OUTFILE = ../../cmd/genparam-interpreter

all: interpret clean

interpret: main.o arithm-parser.o basic-ds.o
	cc -o $(OUTFILE) $(FLAGS) main.o arithm-parser.o basic-ds.o

main.o: main.c
	cc -o main.o -c $(FLAGS) main.c

arithm-parser.o: arithm-parser.c
	cc -o arithm-parser.o -c $(FLAGS) arithm-parser.c

basic-ds.o: basic-ds.c
	cc -o basic-ds.o -c $(FLAGS) basic-ds.c

clean:
	rm -r *.o