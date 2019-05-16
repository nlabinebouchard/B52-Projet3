#include "Solution.h"

Solution::Solution(std::vector<bool> const & vect, std::vector<size_t> vectBit)
	:mChromosome{ Chromosome(vect,vectBit) }
{}

//fitness_t Solution::fitness() const
//{ 
//	return fitness_t(); 
//}

fitness_t Solution::fitness() const
{
	return mFitness;
}

Chromosome & Solution::chromosome()
{ 
	return Solution::mChromosome; 
}

Chromosome const & Solution::chromosome() const
{
	return Solution::mChromosome;
}

Chromosome const & Solution::chromosome() const
{
	return Solution::mChromosome;
}

Solution* Solution::clone() 
{ 
	return this; 
}