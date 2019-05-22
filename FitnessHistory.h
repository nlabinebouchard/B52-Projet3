#pragma once

#include "FitnessStatistics.h"
#include <vector>



class FitnessHistory
{
public:


	FitnessHistory() = default;

	~FitnessHistory() = default;

	void insertNewStatistics(size_t PopulationEngine, FitnessStatistics statistics);

	const FitnessStatistics & getStatistics(size_t PopulationEngine, size_t epoch) const;

	void clearHistory(const size_t & popNumber);


private:

	std::vector<std::vector<FitnessStatistics>> mStatisticsHistory;


};
