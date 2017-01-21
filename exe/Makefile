# Переменная CC указывает компилятор, используемый для сборки
CC=g++
#В переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: run

run: main.o
	$(CC) main.o -o run

main.o: ../src/main.cpp
	$(CC) $(CFLAGS) ../src/main.cpp -I ../src/containers/ -I ../src/sorting_problem

clean:
	rm -rf *.o run
