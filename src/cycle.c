// cycle.c is a test of training a set of cells to try and learn to cycle in a 
//	"round robin" pattern

#include "cell.h"
#include "synapse.h"
#include "fileHandler.h"
#include "environment.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// there are 6 cells total
//	0 - a constant stimulated cell
//  1:5 - 5 fully connected cells that will learn to fire in order and cycle back
Cell cells[6];

// there are 30 synapses totai
//	0:4 - connection cell 0 to the other 5
//	5:29 - 25 synapses to fully connect the 5 cells
Synapse synapses[30];


int main(int argc, char *argv[]){
	time_t t;
	srand((unsigned) time(&t));

	Environment* env = createEnvironment();
	env->decayingTrainingRate = true;
	env->decayingTrainingRateRatio = 0.97f;

	// setup cells
	for(int i=0; i<6; i++){
		cells[i].input = 0;
		cells[i].output = 0;
		cells[i].isFiring = false;
	}

	// setup synapses
	for(int i=1; i<6; i++){
		synapses[i-1].weight = rand()%200;
		synapses[i-1].in = &cells[0];
		synapses[i-1].out = &cells[i];
	}

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			synapses[i*5+j+5].weight = (i==j) ? 0 : rand()%200;
			synapses[i*5+j+5].in = &cells[i+1];
			synapses[i*5+j+5].out = &cells[j+1];
		}
	}

	openCellFile("./data/cellCycle.csv");
	openFiringFile("./data/firingCycle.csv");
	openSynapseFile("./data/synapsesCycle.csv");

	for(; env->timeStep<200; nextTimeStep(env)){
		// feed input to cells
		if(env->timeStep<100){
			// give round robin stimulation
			cells[(env->timeStep%6)].input += 1000;
		}else{
			for(int i=0; i<5; i++){
				cells[i+1].input += 200;
			}
		}
		cells[0].input += 250;

		for(int i=0; i<6; i++){
			updateCellEnv(&cells[i], env);
		}
		saveCells(cells,6,env->timeStep);
		saveFiring(cells,6,env->timeStep);

		for(int i=0; i<30; i++){
			updateSynapseEnv(&synapses[i], env);
		}
		saveSynapses(synapses,30,env->timeStep);
	}	
	
	closeCellFile();
	closeFiringFile();
	closeSynapseFile();
}
