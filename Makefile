
all: directories main.exe
	rm *.o

directories:
	mkdir -p bin
	mkdir -p data

main.exe: main.o cell.o synapse.o fileHandler.o
	gcc -g -o bin/main.exe main.o cell.o synapse.o fileHandler.o
	
main.o: src/main.c src/cell.h src/synapse.h
	gcc -g -c src/main.c

cell.o: src/cell.c src/cell.h
	gcc -g -c src/cell.c

synapse.o: src/synapse.c src/synapse.h src/cell.h
	gcc -g -c src/synapse.c

fileHandler.o: src/fileHandler.c src/fileHandler.h
	gcc -g -c src/fileHandler.c

clean:
	rm bin/*.exe
