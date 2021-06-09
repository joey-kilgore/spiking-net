#pragma once
#include "cell.h"

typedef struct Synapse{
	Cell* in;
	Cell* out;
	int weight;
} Synapse;

void updateSynapse(Synapse* synpase);
