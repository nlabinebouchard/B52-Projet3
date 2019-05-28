#include "Solution.h"

Solution::Solution(std::vector<bool> const & vect, std::vector<size_t> vectBit)
	:mChromosome{ Chromosome(vect,vectBit) }
{}

fitness_t Solution::fitness() const
{
	return mFitness;
}

Chromosome & Solution::chromosome()
{ 
	return mChromosome; 
}

Chromosome const & Solution::chromosome() const
{
	return mChromosome;
}

void Solution::setFitness(double num)
{
	mFitness = num;
}