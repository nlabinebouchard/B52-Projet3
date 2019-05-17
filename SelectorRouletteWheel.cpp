#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "RandomUtil.h"

void SelectorRouletteWheel::prepare(Population const & population)
{
	fitness_t mTotalFitness{};
	fitness_t mWeight;
	fitness_t mProbabilities;

	mRankWeight.resize(population.size());

	for (size_t i{}; i < population.size(); ++i) {
		mTotalFitness+=population[i].fitness();
	}

	for (size_t i{}; i < population.size(); ++i) {
		mWeight = population[i].fitness();
		mProbabilities = (mWeight / mTotalFitness) * 100;
		mRankWeight.insert(mRankWeight.begin()+i, mProbabilities);
	}
}

Solution & SelectorRouletteWheel::select(Population & population)
{
	fitness_t mMaxValueIntervalGene{};
	fitness_t mValueRandom = RandomUtil::randomRangeHundred(0.00, 100.00);

	for (size_t i{}; i < population.size(); ++i) {
		if (mValueRandom < mRankWeight.at(i)) {
			return population[i];
		}
	}
	return population[population.size() - 1];
}
