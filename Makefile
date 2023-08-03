CFLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: mysystem clear

mysystem: main.o mysystem.o
	gcc $(CFLAGS) -o mysystem main.o mysystem.o

main.o: main.c mysystem.h
	gcc -c main.c mysystem.h

mysystem.o: mysystem.c mysystem.h
	gcc -c mysystem.c mysystem.h

clear:
	rm -f *.o *.h.gch

clean:
	rm -f mysystem *.o *.h.gch