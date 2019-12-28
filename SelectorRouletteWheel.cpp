#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "RandomUtil.h"

void SelectorRouletteWheel::prepare(Population const & population)
{
	fitness_t totalFitness{};
	fitness_t weight;
	fitness_t probabilities;
	mValueMax = 100;

	mRankWeight.resize(population.size());

	for (size_t i{}; i < population.size(); ++i) {
		totalFitness += population[i].fitness();
	}

	for (size_t i{}; i < population.size(); ++i) {
		weight = population[i].fitness();
		probabilities = (weight * mValueMax) / totalFitness;
		mRankWeight[i] = probabilities;
	}
}

Solution & SelectorRouletteWheel::select(Population & population)
{
	fitness_t maxValueInterval{};
	fitness_t valueRandom = RandomUtil::randomRangeHundred(0.00, mValueMax);

	for (size_t i{}; i < population.size(); ++i) {
		maxValueInterval += mRankWeight[i];
		if (valueRandom < maxValueInterval) {
			return population[i];
		}
	}
	return population[population.size() - 1];
}

