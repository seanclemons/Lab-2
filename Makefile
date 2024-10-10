CC = gcc
CFLAGS = -Wall

all: signal timer

signal: signal.c
	$(CC) $(CFLAGS) -o signal signal.c

timer: timer.c
	$(CC) $(CFLAGS) -o timer timer.c

clean:
	rm -f signal timer

prog1: main.c
	gcc main.c -o prog1

prog2: main2.c
	gcc main2.c -o prog2

my3proc: main3.c
	gcc main3.c -o my3proc

