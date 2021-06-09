#include "synapse.h"

void updateSynapse(Synapse* synapse){
	if(synapse->in->isFiring){
		synapse->out->input += synapse->in->output * synapse->weight;
	}
}

