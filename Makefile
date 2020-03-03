main: main.o vendas.o arr.o sort.o
	gcc -g -Wall main.o vendas.o arr.o sort.o -o main

main.o: main.c headers.h
	gcc -g -c main.c

vendas.o: vendas.c headers.h
	gcc -g -c vendas.c

arr.o: arr.c headers.h
	gcc -g -c arr.c

sort.o: sort.c headers.h
	gcc -g -c sort.c

clean:
	rm -f main.o vendas.o arr.o main
