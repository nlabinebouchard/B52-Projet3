#include "FitnessHistory.h"

void FitnessHistory::setup(size_t PopulationEngine)
{
	mStatisticsHistory.resize(PopulationEngine);
}

void FitnessHistory::insertNewStatistics(size_t PopulationEngine, FitnessStatistics statistics) {

	size_t size{ mStatisticsHistory[PopulationEngine].size() };
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

//non utilisée
fitness_t FitnessHistory::standardDeviation(size_t epochNumber, size_t popEngine)
{
	fitness_t mean{ 0 };
	fitness_t variance{ 0 };
	fitness_t standardDeviation{ 0 };
	size_t lastEpoch{ mStatisticsHistory[0].size() };

	if (static_cast <int>(lastEpoch - epochNumber) >= 0)
	{

		for (size_t i = lastEpoch-1; i > lastEpoch - epochNumber; i--)
		{
			mean += mStatisticsHistory[popEngine][i].maximum;
		}

		mean /= epochNumber;

		for (size_t i = lastEpoch-1; i > lastEpoch - epochNumber; i--)
		{
			variance += sqrt(mStatisticsHistory[popEngine][i].maximum - mean);
		}

		standardDeviation = sqrt(variance / epochNumber);

		return standardDeviation;
	}
	else
	{
		return std::numeric_limits<fitness_t>::max();
	}


}