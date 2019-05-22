#include "FitnessHistory.h"



void FitnessHistory::insertNewStatistics(size_t PopulationEngine, FitnessStatistics statistics) {

	mStatisticsHistory[PopulationEngine].push_back(statistics);


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