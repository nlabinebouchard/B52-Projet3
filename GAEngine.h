#pragma once

#include "GAParameters.h"
#include "PopulationEngine.h"
#include "FitnessHistory.h"

using Population = size_t; //à enlever

class GAEngine
{
public:


	GAEngine() = default;

	~GAEngine() = default;

	size_t & epoch();

	const Population & population();

	const FitnessStatistics & statistics(size_t epoch);

	void reset();

	void evolve(); //peut-être retourné un bool

	void setup(GAParameters parameters);



private:

	size_t mEpoch;

	GAParameters mParameters;

	std::vector<FitnessStatistics> mFitnessStatistics;

	std::vector<PopulationEngine> mPopulationEngines;
	std::vector<PopulationEngine>::iterator mPopEngIt;
	
	FitnessHistory mFitnessHistory;

};