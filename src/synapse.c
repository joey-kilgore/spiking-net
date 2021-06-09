#include "synapse.h"

void updateSynapse(Synapse* synapse){
	synapse->out->input = synapse->in->output * synapse->weight;
}

