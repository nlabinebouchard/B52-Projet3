#include "PopulationEngine.h"



bool PopulationEngine::isReady()
{

}

size_t PopulationEngine::elitismSize()
{
	return mElitismSize;
}

const Population & PopulationEngine::population() 
{
	return *mActivePopPointer;
}


const FitnessStatistics & PopulationEngine::statistics()
{
	return mFitessStatistics;
}

void PopulationEngine::setElitism(size_t size)
{
	mElitismSize = size;
}

void PopulationEngine::setPopulation(size_t size, Solution* solutionSample)
{
	mActivePopulation.set(size, solutionSample);
	mNextPopulation.set(size, solutionSample);
}

void PopulationEngine::setSelector(Selector * selector)
{

}

void PopulationEngine::setCrossover(Crossover * crossover)
{

}

void PopulationEngine::setMutator(Mutator * mutator)
{

}

void PopulationEngine::randomize()
{

}

void PopulationEngine::evolve()
{

}

//private functions

void PopulationEngine::processFitness()
{

}

void PopulationEngine::processElitism()
{

}

void PopulationEngine::processOneOffspring(size_t index)
{

}

void PopulationEngine::processOffsprings()
{

}

void PopulationEngine::swapPopulations()
{
	std::swap(mActivePopPointer, mNextPopPointer);
}

void PopulationEngine::processStatistics()
{

}
