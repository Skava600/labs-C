all:	build clean run

build:	main.o Tree.o
	gcc main.o Tree.o -o lab6

main.o:	main.c
	gcc  -c main.c -lm -std=c89

Tree.o: 	Tree.c
	gcc -c Tree.c -lm -std=c89
	

run:	build
	./lab6.exe

clean:	build
	del main.o Tree.o