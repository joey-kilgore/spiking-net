#pragma once
#include "cell.h"
#include "synapse.h"

void openCellFile(char fileName[]);
void closeCellFile();

void openSynapseFile(char fileName[]);
void closeSynapseFile();

void saveCells(Cell cells[], int numCells, int timeStep);
void saveSynapses(Synapse synapses[], int numSynapses, int timeStep);
