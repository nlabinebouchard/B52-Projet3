#include "FitnessHistory.h"

void FitnessHistory::setup(size_t PopulationEngine)
{
	mStatisticsHistory.resize(PopulationEngine);
}

void FitnessHistory::insertNewStatistics(size_t PopulationEngine, FitnessStatistics statistics) {

	int size{ mStatisticsHistory[PopulationEngine].size() };
	mStatisticsHistory[PopulationEngine].resize(size + 1);
	mStatisticsHistory[PopulationEngine].at(size) = statistics;
	
	}

const FitnessStatistics & FitnessHistory::getStatistics(size_t PopulationEngine, size_t epoch) const
{

	return mStatisticsHistory[PopulationEngine][epoch];

}


void FitnessHistory::clearHistory(const size_t & popNumber)
{
	for (size_t i = 0; i < popNumber; ++i)
	{
		mStatisticsHistory[i].clear();
	}
}