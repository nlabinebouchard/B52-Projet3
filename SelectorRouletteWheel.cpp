#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "RandomUtil.h"

void SelectorRouletteWheel::prepare(Population const & population)
{
	fitness_t mTotalFitness{};
	fitness_t mWeight;
	fitness_t mProbabilities;
	mValueMax = 100;

	mRankWeight.resize(population.size());

	for (size_t i{}; i < population.size(); ++i) {
		mTotalFitness += population[i].fitness();
	}

	for (size_t i{}; i < population.size(); ++i) {
		mWeight = population[i].fitness();
		mProbabilities = (mWeight * mValueMax) / mTotalFitness;
		mRankWeight[i] = mProbabilities;
	}
}

Solution & SelectorRouletteWheel::select(Population & population)
{
	fitness_t mMaxValueInterval{};
	fitness_t mValueRandom = RandomUtil::randomRangeHundred(0.00, mValueMax);

	for (size_t i{}; i < population.size(); ++i) {
		mMaxValueInterval += mRankWeight[i];
		if (mValueRandom < mMaxValueInterval) {
			return population[i];
		}
	}
	return population[population.size() - 1];
}
