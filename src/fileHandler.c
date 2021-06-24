#include "fileHandler.h"
#include <stdio.h>

FILE *cellFile;
FILE *synapseFile;
FILE *firingFile;

void openCellFile(char fileName[]){
	cellFile = fopen(fileName, "w+");
}

void closeCellFile(){
	fclose(cellFile);
}

void openFiringFile(char fileName[]){
	firingFile = fopen(fileName, "w+");
}

void closeFiringFile(char fileName[]){
	fclose(firingFile);
}

void openSynapseFile(char fileName[]){
	synapseFile = fopen(fileName, "w+");
}

void closeSynapseFile(){
	fclose(synapseFile);
}

void saveCells(Cell cells[], int numCells, int timeStep){
	// save the cell current value to file
	fprintf(cellFile, "%i,", timeStep);
	for(int i=0; i<numCells; i++){
		fprintf(cellFile, "%f,", cells[i].input);
	}
	fprintf(cellFile, "\n");
}

void saveSynapses(Synapse synapses[], int numSynapses, int timeStep){
	// save the synapses weights to file
	fprintf(synapseFile, "%i,", timeStep);
	for(int i=0; i<numSynapses; i++){
		fprintf(synapseFile, "%f,", synapses[i].weight);
	}
	fprintf(synapseFile, "\n");
}

void saveFiring(Cell cells[], int numCells, int timeStep){
	// save the cells that are currently firing
	fprintf(firingFile, "%i,", timeStep);
	for(int i=0; i<numCells; i++){
		fprintf(firingFile, "%i,", (cells[i].isFiring) ? i+1 : 0);
	}
	fprintf(firingFile, "\n");
}
