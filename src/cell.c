#include "cell.h"

void updateCell(Cell* cell){
	if(cell->input >= 1000){
		cell->output = 1;
		cell->input = 0;
		cell->isFiring = true;
		cell->tSinceFire = 0;
	}
	else{
		cell->isFiring = false;
		cell->tSinceFire++;
		cell->input *= 4.0f/5.0f;
	}
}

void updateCellEnv(Cell* cell, Environment* env){
	if(cell->input >= 1000){
		cell->output = 1;
		cell->input = 0;
		cell->isFiring = true;
		cell->tSinceFire = 0;
	}
	else{
		cell->isFiring = false;
		cell->tSinceFire++;
		cell->input *= 4.0f/5.0f;
	}
}
