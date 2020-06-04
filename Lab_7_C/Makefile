all:	build clean run

build:	main.o Students.o
	gcc main.o Students.o -o lab7

main.o:	main.c
	gcc  -c main.c -lm -std=c89

Students.o: 	Students.c
	gcc -c Students.c -lm -std=c89
	

run:	build
	./lab7.exe

clean:	build
	del main.o Students.o