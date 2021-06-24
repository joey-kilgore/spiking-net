#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef struct Environment{
	int timeStep;
	double trainingRate;

	// settings
	bool decayingTrainingRate;
	double decayingTrainingRateRatio;
} Environment;

Environment* createEnvironment();
void nextTimeStep(Environment* environment);
void updateEnvironment(Environment* environment);
