#include "Population.h"

size_t Population::size() const 
{ 
	return vectSolution.size(); 
}

void Population::set(size_t size, Solution * solutionSample)
{
	//vectSolution.push_back(solutionSample);
	vectSolution.resize(size);
	for (auto & sol:vectSolution) {
		sol = solutionSample->clone();
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

void Population::randomize()
{
	for (size_t i{}; i < vectSolution.size(); ++i) {
		vectSolution[i]->randomize();
	}
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

