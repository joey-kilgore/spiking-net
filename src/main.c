#include "cell.h"
#include "synapse.h"
#include "fileHandler.h"
#include "environment.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void testSynapse();
void multiCell();

int main(int argc, char *argv[]){
	time_t t;
	srand((unsigned) time(&t));

	testSynapse();
	multiCell();
}

void testSynapse(){
	Cell c1, c2;
	Synapse s1;

	c1.input = 0;
	c1.output = 0;

	c2.input = 0;
	c2.output = 0;

	s1.in = &c1;
	s1.out = &c2;
	s1.weight = 50;

	printf("c1 input : %f\n", c1.input);
	c1.input = 10000;
	printf("c1 input : %f\n", c1.input);

	printf("UPDATE C1\n");
	updateCell(&c1);	

	printf("c1 input : %f\n", c1.input);
	printf("c1 output : %f\n", c1.output);

	printf("UPDATE S1\n");
	updateSynapse(&s1);

	printf("c1 input : %f\n", c1.input);
	printf("c1 output : %f\n", c1.output);

	printf("c2 input : %f\n", c2.input);
	printf("c2 output : %f\n", c2.output);
}

void multiCell(){
	openCellFile("./data/cells.csv");
	openSynapseFile("./data/synapses.csv");

	Cell cells[10];
	for(int i=0; i<10; i++){
		cells[i].input = 0;
		cells[i].output = 0;
		cells[i].isFiring = false;
	}

	Synapse synapses[100];
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			synapses[i*10+j].weight = rand()%200;
			synapses[i*10+j].in = &cells[i];
			synapses[i*10+j].out = &cells[j];
		}
	}

	// output synapses
	printf("SYNAPSE CONNECTIONS\n");
	printf("in\\out\t|C0\t|C1\t|C2\t|C3\t|C4\t|C5\t|C6\t|C7\t|C8\t|C9\t|\n");
	for(int i=0; i<10; i++){
		printf("C%i\t",i);
		for(int j=0; j<10; j++){
			printf("|%0.2f\t",synapses[i*10+j].weight);
		}
		printf("|\n");
	}
	printf("\n");


	int inputs[10];
	for(int i=0; i<10; i++){
		inputs[i] = rand()%300 + 200;	
	}

	// setup output
	printf("CELL INPUTS\n");
	printf("C0\t|C1\t|C2\t|C3\t|C4\t|C5\t|C6\t|C7\t|C8\t|C9\t|\n");
	for(int i=0; i<10; i++){
		printf("%0.2f\t|",cells[i].input);
	}
	printf("\n");

	Environment* env = createEnvironment();
	env->decayingTrainingRate = true;

	// loop through each time step
	for(; env->timeStep<50; nextTimeStep(env)){
		// set all the input values
		if(env->timeStep<25){
			for(int i=0; i<10; i++){
				cells[i].input+=inputs[i];
			}
		}else{
			cells[0].input += 500;
			cells[9].input += 500;
		}

		// update cells checking for a spike
		for(int i=0; i<10; i++){
			updateCellEnv(&cells[i], env);
		}

		// display output
		for(int i=0; i<10; i++){
			if(cells[i].isFiring){
				// firing shown in red
				printf("\033[1;31m");
			}

			printf("%0.2f\t\033[1;0m|",cells[i].input);
		}
		printf("\n");
		saveCells(cells,10,env->timeStep);

		// update synapses
		for(int i=0; i<100; i++){
			updateSynapseEnv(&synapses[i], env);
		}
		saveSynapses(synapses,100,env->timeStep);
	}

	// output synapses
	printf("FINAL SYNAPSE WEIGHTS\n");
	printf("in\\out\t|C0\t|C1\t|C2\t|C3\t|C4\t|C5\t|C6\t|C7\t|C8\t|C9\t|\n");
	for(int i=0; i<10; i++){
		printf("C%i\t",i);
		for(int j=0; j<10; j++){
			printf("|%0.2f\t",synapses[i*10+j].weight);
		}
		printf("|\n");
	}
	printf("\n");

	closeCellFile();
	closeSynapseFile();
}
