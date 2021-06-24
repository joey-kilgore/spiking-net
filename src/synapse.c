#include "synapse.h"

// increase is the amount the weight will increase relative to the difference in time step
//	each index is the next time step difference
//	the increase is an exponential decay over 10 time steps
int increase[] = {0, 100, 50, 25, 12, 6, 3, 2, 1, 1};

// decrease is teh amount the weight will decrease if the in fires before the out cell
int decrease[] = {-100, -50, -25, -12, -6, -3, -2, -1, -1, -1};

void updateSynapse(Synapse* synapse){
	if(synapse->in->isFiring){
		synapse->out->input += synapse->in->output * synapse->weight;

		if(synapse->out->tSinceFire < 10){
			// if the out cell if firing before the in cell we will decrease the weight
			synapse->weight += decrease[synapse->out->tSinceFire];
			if(synapse->weight < 0) synapse->weight = 0;
		}
	}
	if(synapse->out->isFiring){
		if(synapse->in->tSinceFire < 10){
			// if the in cell is firing before the out cell we will increase the weight
			synapse->weight += increase[synapse->in->tSinceFire];
			if(synapse->weight > 500) synapse->weight = 500;
		}
	}
}

void updateSynapseEnv(Synapse* synapse, Environment* env){
	if(synapse->in->isFiring){
		synapse->out->input += synapse->in->output * synapse->weight;

		if(synapse->out->tSinceFire < 10){
			// if the out cell if firing before the in cell we will decrease the weight
			synapse->weight += env->trainingRate*decrease[synapse->out->tSinceFire];
			if(synapse->weight < 0) synapse->weight = 0;
		}
	}
	if(synapse->out->isFiring){
		if(synapse->in->tSinceFire < 10){
			// if the in cell is firing before the out cell we will increase the weight
			synapse->weight += env->trainingRate*increase[synapse->in->tSinceFire];
			if(synapse->weight > 500) synapse->weight = 500;
		}
	}
}
