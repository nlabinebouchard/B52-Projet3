#pragma once

#include "FitnessStatistics.h"
#include <vector>
#include "Solution.h"
#include "Selector.h"
#include "Crossover.h"
#include "Mutator.h"
#include "Population.h"

class PopulationEngine
{
public:


	PopulationEngine();

	~PopulationEngine() = default;

	bool isReady() const;

	size_t elitismSize() const;

	const Population & population() const;

	const FitnessStatistics & statistics();

	void setElitism(size_t size);

	void setPopulation(size_t size, Solution* solutionSample);

	void setSelector(Selector * selector);

	void setCrossover(Crossover * crossover);

	void setMutator(Mutator * mutator);

	void randomize();

	void evolve();

	




private:

	void processFitness();

	void processElitism();

	void processOneOffspring(size_t index);

	void processOffsprings();

	void swapPopulations();

	void processStatistics();

	Population & population();


	FitnessStatistics mFitessStatistics;
	Mutator* mMutator;
	Selector* mSelector;
	Crossover* mCrossover;
	Population mActivePopulation;
	Population mNextPopulation;
	Population * mActivePopPointer;  //les initialiser!!!!
	Population * mNextPopPointer;//les initialiser!!!!
	size_t mElitismSize;



};