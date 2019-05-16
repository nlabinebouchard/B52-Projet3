#include "FitnessHistory.h"



void FitnessHistory::insertNewStatistics(size_t PopolutationEngine, FitnessStatistics statistics) {

	mStatisticsHistory[PopolutationEngine].push_back(statistics);


	}

const FitnessStatistics & FitnessHistory::getStatistics(size_t PopolutationEngine, size_t epoch)
{

	return mStatisticsHistory[PopolutationEngine][epoch];

}


