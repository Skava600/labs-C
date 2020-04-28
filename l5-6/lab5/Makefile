all: build run

build: libque.a
    gcc main.c -L. -lque -o main

run:
    ./main

libque.a: libque.o
    ar rcs libque.a libque.o

libque.o: libque.c
    gcc -c libque.c -o libque.o -std=c89
