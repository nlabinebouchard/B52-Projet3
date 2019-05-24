#include "SelectorRankwise.h"
#include "Population.h"
#include "RandomUtil.h"

double SelectorRankwise::gamma() const
{
	return mGamma;
}

void SelectorRankwise::setGamma(double gamma)
{
	if (gamma > 1) {
		mGamma = gamma;
	}
}

void SelectorRankwise::prepare(Population const & population)
{
	fitness_t mProbabilities;
	mValueMax = 1;

	mRankWeight.resize(population.size());
	for (size_t i{}; i < population.size(); ++i) {
		mProbabilities = (mGamma - 1) / (pow(mGamma, i + 1));
		mRankWeight.at(i) = mProbabilities;
	}
}


