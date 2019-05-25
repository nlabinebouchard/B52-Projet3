#pragma once

#include "GAParameters.h"
#include "PopulationEngine.h"
#include "FitnessHistory.h"
#include "Population.h"

class GAEngine
{
public:


	GAEngine() = default;

	~GAEngine() = default;

	size_t epoch() const;

	const Population & population(size_t populationEngine) const;

	const FitnessStatistics & statistics(size_t popIndex, size_t epoch) const;

	void reset();

	void evolve(); //peut-être retourné un bool

	void setup(GAParameters parameters);

	void standardDeviation(size_t epochNumber, size_t popEngine);

	GAParameters const& getParameters() const;




private:

	size_t mEpoch;

	GAParameters mParameters;

	std::vector<PopulationEngine> mPopulationEngines;
	std::vector<PopulationEngine>::iterator mPopEngIt;
	
	FitnessHistory mFitnessHistory;

};