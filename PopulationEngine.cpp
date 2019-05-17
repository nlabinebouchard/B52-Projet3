#include "PopulationEngine.h"
#include <algorithm>



bool PopulationEngine::isReady()//à voir!!!!!!!!!!!!!
{
	return true;
}

size_t PopulationEngine::elitismSize()
{
	return mElitismSize;
}

/*const*/ Population & PopulationEngine::population() //à vérifier pour le const bug pour l'utilisation du mSelector sinon
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
	mSelector = selector;
}

void PopulationEngine::setCrossover(Crossover * crossover)
{
	mCrossover = crossover;
}

void PopulationEngine::setMutator(Mutator * mutator)
{
	mMutator = mutator;
}

void PopulationEngine::randomize() //randomize active population??
{
	mActivePopPointer->randomize();
}

void PopulationEngine::evolve()
{
	processElitism();
	processOffsprings();
	swapPopulations();
	processStatistics();


	//MUTATION A A JOUR

}

//private functions

void PopulationEngine::processFitness()
{
	mActivePopPointer->processFitness();
}

void PopulationEngine::processElitism()
{
	mActivePopPointer->sort();
	for (size_t i = 0; i < mElitismSize; i++)
	{
		mNextPopPointer[i] = mActivePopPointer[i];
	}
}

void PopulationEngine::processOneOffspring(size_t index)
{
	mCrossover->breed(mSelector->select(population()), mSelector->select(population()),(*mNextPopPointer)[index]);
}

void PopulationEngine::processOffsprings()
{
	for (size_t i = mElitismSize; i < mActivePopPointer->size(); i++)  //commence après les éléments élites
	{
		processOneOffspring(i);
	}
}

void PopulationEngine::swapPopulations()
{
	std::swap(mActivePopPointer, mNextPopPointer);
}

void PopulationEngine::processStatistics()
{

}
