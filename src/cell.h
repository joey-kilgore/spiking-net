#pragma once
#include <stdbool.h>

typedef struct Cell{
	int input;
	int output;
	bool isFiring;
	int tSinceFire;
} Cell;

void updateCell(Cell* cell);
