#ifndef SOLUTION_H
#define SOLUTION_H
#include "Fitness_t.h"
#include "Chromosome.h"

class Solution
{
private:
	fitness_t mFitness;
	Chromosome mChromosome;

public:
	Solution(std::vector <bool> const & vect, std::vector <size_t> vectBit);
	fitness_t fitness() const;
	Chromosome & chromosome();
	Chromosome const & chromosome() const;

	virtual void processFitness()=0;
	virtual void randomize()=0;
	virtual void encode()=0;
	virtual void decode()=0;
	virtual Solution* clone();
private:
};

#endif // SOLUTION_H
