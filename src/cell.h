#pragma once
#include <stdbool.h>

typedef struct Cell{
	double input;
	double output;
	bool isFiring;
	int tSinceFire;
} Cell;

void updateCell(Cell* cell);
