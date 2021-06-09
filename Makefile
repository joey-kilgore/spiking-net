
all: main.exe
	rm *.o

main.exe: main.o cell.o synapse.o
	gcc -g -o bin/main.exe main.o cell.o synapse.o
	
main.o: src/main.c src/cell.h src/synapse.h
	gcc -g -c src/main.c

cell.o: src/cell.c src/cell.h
	gcc -g -c src/cell.c

synapse.o: src/synapse.c src/synapse.h src/cell.h
	gcc -g -c src/synapse.c

clean:
	rm *.o
	rm bin/*.exe
