#pragma once
#include <stdbool.h>

typedef struct Cell{
	int input;
	int output;
	bool isFiring;
} Cell;

void updateCell(Cell* cell);
