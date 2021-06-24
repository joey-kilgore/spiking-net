
all: directories main.exe thousandCell.exe cycle.exe
	rm *.o

directories:
	mkdir -p bin
	mkdir -p data

main.exe: main.o cell.o synapse.o fileHandler.o environment.o
	gcc -g -o bin/main.exe main.o environment.o cell.o synapse.o fileHandler.o

thousandCell.exe: thousandCell.o cell.o synapse.o fileHandler.o
	gcc -g -o bin/thousandCell.exe thousandCell.o cell.o synapse.o fileHandler.o
	
cycle.exe: cycle.o cell.o synapse.o fileHandler.o environment.o
	gcc -g -o bin/cycle.exe cycle.o cell.o synapse.o fileHandler.o environment.o

main.o: src/main.c src/cell.h src/synapse.h
	gcc -g -c src/main.c

thousandCell.o: src/thousandCell.c src/cell.h src/synapse.h
	gcc -g -c src/thousandCell.c

cycle.o: src/cycle.c src/cell.h src/synapse.h
	gcc -g -c src/cycle.c

environment.o: src/environment.c src/environment.h
	gcc -g -c src/environment.c

cell.o: src/cell.c src/cell.h src/environment.h
	gcc -g -c src/cell.c

synapse.o: src/synapse.c src/synapse.h src/cell.h src/environment.h
	gcc -g -c src/synapse.c

fileHandler.o: src/fileHandler.c src/fileHandler.h
	gcc -g -c src/fileHandler.c

clean:
	rm bin/*.exe
