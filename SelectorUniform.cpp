#include "SelectorUniform.h"
#include "Population.h"
#include "RandomUtil.h"

void SelectorUniform::prepare(Population const & population)
{
	mEndPop = population.size() - 1;
}

Solution & SelectorUniform::select(Population & population)
{
	size_t valueRandom = RandomUtil::randomInRange(0, mEndPop);
	return population[valueRandom];
}

