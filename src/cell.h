#pragma once
#include <stdbool.h>
#include "environment.h"

typedef struct Cell{
	double input;
	double output;
	bool isFiring;
	int tSinceFire;
} Cell;

void updateCell(Cell* cell);
void updateCellEnv(Cell* cell, Environment* env);
