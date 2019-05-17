#include "Population.h"

size_t Population::size() const 
{ 
	return vectSolution.size(); 
}

void Population::set(size_t size, Solution * solutionSample)
{
	for (size_t i{1}; i < size; ++i) {
		vectSolution.push_back((*vectSolution[0]).clone());
	}
}

void Population::processFitness()
{
	for (size_t i{}; i < vectSolution.size(); ++i) {
		(*vectSolution[i]).processFitness();
	}
}

void Population::sort()
{
	std::sort(vectSolution.begin(), vectSolution.end(), Comparator);
}

Solution & Population::operator[](size_t index)
{
	return *vectSolution.at(index);
}

Solution const & Population::operator[](size_t index) const
{
	return *vectSolution.at(index);
}

bool Population::Comparator(Solution* s1, Solution* s2)
{
	return s1->fitness() > s2->fitness();
}

