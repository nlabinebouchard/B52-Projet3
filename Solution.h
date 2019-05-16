#ifndef SOLUTION_H
#define SOLUTION_H
#include "Fitness_t.h"

class Solution
{
public:
	fitness_t mFitness;

	fitness_t fitness();

private:
	virtual void processFitness();
	virtual void randomize();
	virtual void encode();
	virtual void decode();
	virtual Solution clone();
};

#endif // SOLUTION_H
