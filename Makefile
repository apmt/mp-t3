G++ = g++

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = linhas.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_linhas.o linhas.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

testa_linhas: testa_linhas.cpp linhas.cpp $(DEPS)
	$(G++) -g $< -o $@ -fprofile-arcs -ftest-coverage $(CFLAGS) -pthread /usr/lib/libgtest.a

.PHONY: clean

clean:
	rm *.gcov *.gcno *.gcda -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 


