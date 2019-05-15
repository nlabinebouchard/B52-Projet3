#include "Population.h"

size_t Population::size() { return vectSolution.size(); }

void Population::processFitness()
{
	for (size_t i; i < vectSolution.size(); ++i) {
		vectSolution[i].fitness();
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
