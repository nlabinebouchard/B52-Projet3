#ifndef SOLUTION_H
#define SOLUTION_H
#include "Fitness_t.h"
#include "Chromosome.h"

class Solution
{
public:
	fitness_t mFitness;
	Chromosome mChromosome;

	Solution(std::vector <bool> const & vect, std::vector <size_t> vectBit);
	fitness_t fitness();
	Chromosome chromosome();

private:
	virtual void processFitness();
	virtual void randomize();
	virtual void encode();
	virtual void decode();
	virtual Solution clone();
};

#endif // SOLUTION_H
