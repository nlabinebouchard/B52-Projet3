#include "Population.h"

size_t Population::size() 
{ 
	return vectSolution.size(); 
}

void Population::set(size_t size, Solution * solutionSample)
{
	for (size_t i{1}; i < size; ++i) {
		vectSolution.push_back(*vectSolution[0].clone());
	}
}

void Population::processFitness()
{
	for (size_t i{}; i < vectSolution.size(); ++i) {
		vectSolution[i].processFitness();
	}
}

void Population::sort()
{
	std::sort(vectSolution.begin(), vectSolution.end(), Comparator);
}

bool Population::Comparator(size_t plusPetit, size_t plusGrand)
{
	return vectSolution[plusPetit].mFitness > vectSolution[plusGrand].mFitness;
}
