test: test.c linalglib.o
	gcc -o test test.c linalglib.o -lm

linalglib.o: linalglib.h linalglib.c
	gcc -c linalglib.c
