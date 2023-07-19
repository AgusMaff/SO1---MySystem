CFLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: mysystem clear

mysystem: main.o
	gcc $(CFLAGS) -o mysystem main.o

main.o: main.c
	gcc -c main.c main.h

clear:
	rm -f *.o *.h.gch

clean:
	rm -f mysystem *.o *.h.gch