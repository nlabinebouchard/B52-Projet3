#include "Solution.h"

Solution::Solution(std::vector<bool> const & vect, std::vector<size_t> vectBit)
	:mChromosome{ Chromosome(vect,vectBit) }
{}

fitness_t Solution::fitness() { return fitness_t(); }

Chromosome Solution::chromosome() { return mChromosome; }

Solution* Solution::clone() { return this; }
