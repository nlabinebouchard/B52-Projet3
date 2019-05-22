#pragma once

#include "GAParameters.h"
#include "PopulationEngine.h"
#include "FitnessHistory.h"

using Population = size_t; //� enlever

class GAEngine
{
public:


	GAEngine() = default;

	~GAEngine() = default;

	size_t epoch() const;

	const Population & population(size_t populationEngine) const;

	const FitnessStatistics & statistics(size_t popIndex, size_t epoch) const;

	void reset();

	void evolve(); //peut-�tre retourn� un bool

	void setup(GAParameters parameters);



private:

	size_t mEpoch;

	GAParameters mParameters;

	std::vector<PopulationEngine> mPopulationEngines;
	std::vector<PopulationEngine>::iterator mPopEngIt;
	
	FitnessHistory mFitnessHistory;

};