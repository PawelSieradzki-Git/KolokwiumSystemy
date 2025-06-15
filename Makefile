CC = gcc
CFLAGS = -Wall -Wextra
OBJ = coordinator.o agent.o

all: coordinator agent main

coordinator: coordinator.c coordinator.h
	$(CC) $(CFLAGS) -c coordinator.c -o coordinator.o

agent: agent.c agent.h
	$(CC) $(CFLAGS) -c agent.c -o agent.o

main: main.c $(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o koordynator

clean:
	rm -f *.o koordynator