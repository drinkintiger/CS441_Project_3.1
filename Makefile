#####################################################################
# Josh Hursey
# Nov. 2, 2012
#
# CS 441/541 : Project 3 Part 1 Template
#
#####################################################################
#
# Type "make" or "make all" to compile your code
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

CC=gcc
CFLAGS=-Wall -O0 -g
# Linker flag for Mac OS X
LDFLAGS=-lm
# Linker flag for Linux
#LDFLAGS=-lm -lrt

PROGS=scalarmult matrixmult

all: $(PROGS)

scalarmult: support.o scalarmult.c scalarmult.h
	$(CC) -o scalarmult support.o $(CFLAGS) $(LDFLAGS) scalarmult.c

matrixmult: support.o matrixmult.c matrixmult.h
	$(CC) -o matrixmult support.o $(CFLAGS) $(LDFLAGS) matrixmult.c

support.o: support.c support.h
	$(CC) -c -o support.o $(CFLAGS) support.c

clean:
	$(RM) $(PROGS) *.o
	$(RM) -rf *.dSYM
