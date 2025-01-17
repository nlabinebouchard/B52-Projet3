#ifndef FITNESS_HISTORY_H
#define FITNESS_HISTORY_H

#include "FitnessStatistics.h"
#include <vector>

class FitnessHistory
{
public:


	FitnessHistory() = default;

	~FitnessHistory() = default;

	void insertNewStatistics(size_t PopulationEngine, FitnessStatistics statistics);

	void setup(size_t PopulationEngine);

	const FitnessStatistics & getStatistics(size_t PopulationEngine, size_t epoch) const;

	void clearHistory(const size_t & popNumber);

	fitness_t standardDeviation(size_t epochNumber, size_t popEngine);


private:

	std::vector<std::vector<FitnessStatistics>> mStatisticsHistory;

};
#endif // FITNESS_HISTORY_H
