#include "cell.h"
#include "synapse.h"
#include <stdio.h>

void testSynapse();

int main(int argc, char *argv[]){
	testSynapse();
}

void testSynapse(){
	Cell c1, c2;
	Synapse s1;

	c1.input = 0;
	c1.output = 0;

	c2.input = 0;
	c2.output = 0;

	s1.in = &c1;
	s1.out = &c2;
	s1.weight = 50;

	printf("c1 input : %i\n", c1.input);
	c1.input = 10000;
	printf("c1 input : %i\n", c1.input);

	printf("UPDATE C1\n");
	updateCell(&c1);	

	printf("c1 input : %i\n", c1.input);
	printf("c1 output : %i\n", c1.output);

	printf("UPDATE S1\n");
	updateSynapse(&s1);

	printf("c1 input : %i\n", c1.input);
	printf("c1 output : %i\n", c1.output);

	printf("c2 input : %i\n", c2.input);
	printf("c2 output : %i\n", c2.output);
}
