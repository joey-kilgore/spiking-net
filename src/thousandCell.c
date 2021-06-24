#include "cell.h"
#include "synapse.h"
#include "fileHandler.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CELL 1000
#define NUM_GROUP 10
#define CELL_PER_GROUP NUM_CELL/NUM_GROUP
#define NUM_SYNAPSE 101000
#define DEBUG 1

Cell cells[NUM_CELL];
Synapse synapses[NUM_SYNAPSE];

int main(int argc, char *argv[]){
	time_t t;
	srand((unsigned) time(&t));

	for(int i=0; i<NUM_CELL; i++){
		cells[i].input = 0;
		cells[i].output = 0;
		cells[i].isFiring = false;
	}

	// setup pools
	for(int g=0; g<NUM_GROUP; g++){
		for(int i=0; i<NUM_CELL/NUM_GROUP; i++){
			for(int j=0; j<NUM_CELL/NUM_GROUP; j++){
				synapses[g*(NUM_CELL/NUM_GROUP)+i*NUM_CELL+j].weight = (i==j) ? 0 : rand()%200;
				synapses[g*(NUM_CELL/NUM_GROUP)+i*NUM_CELL+j].in = &cells[g*(NUM_CELL/NUM_GROUP)+i];
				synapses[g*(NUM_CELL/NUM_GROUP)+i*NUM_CELL+j].out = &cells[g*(NUM_CELL/NUM_GROUP)+j];
			}
		}
	}

	// setup across pool connections
	for(int g=0; g<NUM_GROUP; g++){
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				synapses[NUM_GROUP*NUM_GROUP+i*NUM_CELL+j].weight = (i==j) ? 0 : rand()%200;
				synapses[g*(NUM_CELL/NUM_GROUP)+i*NUM_CELL+j].in = &cells[g*(NUM_CELL/NUM_GROUP)+i];
				synapses[g*(NUM_CELL/NUM_GROUP)+i*NUM_CELL+j].out = &cells[g*(NUM_CELL/NUM_GROUP)+j];
			}
		}
	}

	int inputs[NUM_CELL];
	for(int i=0; i<NUM_CELL; i++){
		inputs[i] = rand()%400;
	}

#ifdef DEBUG
	printf("SETUP COMPLETE\n");
#endif

	openCellFile("./data/cells1000.csv");
	openSynapseFile("./data/synapses1000.csv");

	for(int t=0; t<50; t++){

#ifdef DEBUG
		printf("Time Step:\t%i\n",t);
#endif

		// feed input
		if(t<10){
			for(int i=0; i<NUM_CELL; i++){
				cells[i].input+=inputs[i];
			}
		}else{
			for(int i=0; i<10; i++){
				cells[i].input+=inputs[i];
			}
		}

		// update the cells
		for(int i=0; i<NUM_CELL; i++){
			updateCell(&cells[i]);
		}

		// save cells
		saveCells(cells,NUM_CELL,t);

		// update synapses
		for(int i=0; i<NUM_SYNAPSE; i++){
			updateSynapse(&synapses[i]);
		}

		// save synapses
		// saveSynapses(synapses,NUM_SYNAPSE,t);
	}

	closeCellFile();
	closeSynapseFile();
}
