program: bSearch.o bubble.o database.o db.o parse.o set.o stack.o
	gcc -o program bSearch.o bubble.o database.o db.o parse.o set.o stack.o

bSearch.o: bSearch.c defs.h sortAndSearch.h
	gcc -c bSearch.c

bubble.o: bubble.c defs.h
	gcc -c bubble.c

database.o: database.c defs.h parse.h
	gcc -c database.c

db.o: db.c defs.h
	gcc -c db.c

parse.o: parse.c parse.h
	gcc -c parse.c

set.o: set.c set.h db.h
	gcc -c set.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm -f  *o program

run:
	./program < data

