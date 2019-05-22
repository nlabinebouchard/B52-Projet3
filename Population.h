#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "Solution.h"
#include <algorithm>

class Population
{
public:
	size_t size() const;
	void set(size_t size, Solution *solutionSample);
	void processFitness();
	void sort();
	void randomize();

	Solution & operator[](size_t index);
	Solution const & operator[](size_t index)const;

private:
	static bool Comparator(Solution* plusPetit, Solution* plusGrand);
	std::vector <Solution*> vectSolution;
};


#endif // POPULATION_H