#pragma once

#include "FitnessStatistics.h"
#include <vector>



class FitnessHistory
{
public:


	FitnessHistory() = default;

	~FitnessHistory() = default;

	void insertNewStatistics(size_t PopolutationEngine, FitnessStatistics statistics);

	const FitnessStatistics & getStatistics(size_t PopolutationEngine, size_t epoch);


private:

	std::vector<std::vector<FitnessStatistics>> mStatisticsHistory;

};
