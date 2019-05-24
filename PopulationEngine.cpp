#include "PopulationEngine.h"
#include <algorithm>
#include "RandomUtil.h"





PopulationEngine::PopulationEngine()
	:mMutator{nullptr},
	mSelector{ nullptr },
	mCrossover{ nullptr },
	mActivePopPointer{ nullptr },
	mNextPopPointer{ nullptr }
{
}

bool PopulationEngine::isReady() const//à voir!!!!!!!!!!!!!
{
	return true;
}

size_t PopulationEngine::elitismSize() const
{
	return mElitismSize;
}

const Population & PopulationEngine::population() const //à vérifier pour le const bug pour l'utilisation du mSelector sinon
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
	mActivePopPointer=&mActivePopulation;
	mNextPopPointer=&mNextPopulation;

	processFitness();
	processStatistics();
}

void PopulationEngine::setSelector(Selector * selector)
{
	delete mSelector;
	mSelector = selector;
}

void PopulationEngine::setCrossover(Crossover * crossover)
{

	delete mCrossover;
	mCrossover = crossover;
	
}

void PopulationEngine::setMutator(Mutator * mutator)
{

	delete mMutator;
	mMutator = mutator;
}

void PopulationEngine::randomize() //randomize active population??
{
	mActivePopPointer->randomize();
	mNextPopPointer->randomize();
}

void PopulationEngine::evolve()
{
	processElitism();
	processOffsprings();
	swapPopulations();
	processFitness();
	processStatistics();

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
		(*mNextPopPointer)[i] = (*mActivePopPointer)[i];
	}
}

void PopulationEngine::processOneOffspring(size_t index)
{
	mCrossover->breed(mSelector->select(population()), mSelector->select(population()),(*mNextPopPointer)[index]);
	if (RandomUtil::generateEvent(mMutator->mutationRate()) == true)
	{
		(*mMutator).mutate((*mNextPopPointer)[index]);
	}
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
	mFitessStatistics.average = 0;
	mFitessStatistics.minimum = 0;
	mFitessStatistics.maximum = 0;



	for (size_t i = 0; i < mActivePopPointer->size(); i++)
	{
		mFitessStatistics.average+=(*mActivePopPointer)[i].fitness();

		if (mFitessStatistics.minimum>(*mActivePopPointer)[i].fitness())
		{
			mFitessStatistics.minimum = (*mActivePopPointer)[i].fitness();
		}

		if ((mFitessStatistics.maximum<(*mActivePopPointer)[i].fitness()))
		{
			(mFitessStatistics.maximum = (*mActivePopPointer)[i].fitness());
		}

	}

	mFitessStatistics.average /= mActivePopPointer->size();
}


Population & PopulationEngine::population() 
{
	return *mActivePopPointer;
}
