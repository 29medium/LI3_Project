main: main.o vendas.o arr.o
	gcc -g -Wall main.o vendas.o arr.o -o main

main.o: main.c vendas.h arr.h
	gcc -g -c main.c

vendas.o: vendas.c vendas.h
	gcc -g -c vendas.c

arr.o: arr.c arr.h
	gcc -g -c arr.c

clean:
	rm -f main.o vendas.o arr.o main
