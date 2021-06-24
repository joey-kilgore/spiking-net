#pragma once
#include "cell.h"

typedef struct Synapse{
	Cell* in;
	Cell* out;
	double weight;
} Synapse;

void updateSynapse(Synapse* synpase);
