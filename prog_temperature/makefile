all: prog

prog: main.o temp_api.o
	gcc -o prog main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c --std=c99 -o main.o main.c

temp_api.o: temp_api.c temp_api.h
	gcc -c --std=c99 -o temp_api.o temp_api.c

clean:
	rm -rf *.o prog.exe

