IDIR=../include
ODIR=obj

CC = gcc
CFLAGS = -O3 -Wall -g -I$(IDIR)

_DEPS = headers.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o sales.o arr.o sort.o tests.o hash.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f exe
	rm -f ..file/Vendas_1MValidas.txt
