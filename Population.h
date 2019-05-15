#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "Solution.h"
#include <algorithm>

class Population
{
public:
	std::vector <Solution> vectSolution;

	size_t size();
	void set(size_t size, Solution *solutionSample);
	void processFitness();

private:

	void sort();
	bool Comparator(size_t plusPetit, size_t plusGrand);
};

#endif // POPULATION_H