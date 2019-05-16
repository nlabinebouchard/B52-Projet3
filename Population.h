#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "Solution.h"
#include <algorithm>

class Population
{
public:
	size_t size();
	void set(size_t size, Solution *solutionSample);
	void processFitness();
	void sort();

private:

	bool Comparator(size_t plusPetit, size_t plusGrand);
	std::vector <Solution> vectSolution;
};

#endif // POPULATION_H