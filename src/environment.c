#include "environment.h"

Environment* createEnvironment(){
	Environment* newEnv = (Environment*)malloc(sizeof(Environment));
	newEnv->timeStep = 0;
	newEnv->trainingRate = 1;
	newEnv->decayingTrainingRate = false;
	newEnv->decayingTrainingRateRatio = 0.9f;
	return newEnv;
}

void nextTimeStep(Environment* environment){
	environment->timeStep++;
	updateEnvironment(environment);
}

void updateEnvironment(Environment* environment){
	if(environment->decayingTrainingRate){
		environment->trainingRate *= environment->decayingTrainingRateRatio;
	}
}
