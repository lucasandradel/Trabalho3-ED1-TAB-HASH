all: tab_hash.o
	gcc main.c tab_hash.o -o prog
	./prog


tab_hash.o: tab_hash.c
	gcc -c tab_hash.c

clean:

	rm *.o prog