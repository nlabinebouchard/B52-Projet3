#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "RandomUtil.h"
#include "SelectorRankwise.h"

double SelectorRankwise::gamma() const
{
	return mGamma;
}

void SelectorRankwise::setGamma(double gamma)
{
	mGamma = gamma;
}

void SelectorRankwise::prepare(Population const & population)
{
	
}

