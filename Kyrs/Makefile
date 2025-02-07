all : prog

prog: main.o integral.o
	gcc -o prog main.o integral.o

main.o: main.c integral.h
	gcc -c -o main.o main.c

integral.o: integral.c
	gcc -c -o integral.o integral.c

clean:
	rm -rf *.o *.exe prog
