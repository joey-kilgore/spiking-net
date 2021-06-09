#include "cell.h"

void updateCell(Cell* cell){
	if(cell->input >= 1000){
		cell->output = 1;
		cell->input = 0;
		cell->isFiring = true;
	}
	else{
		cell->isFiring = false;
	}
}
