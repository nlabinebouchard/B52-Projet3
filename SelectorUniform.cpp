#include "SelectorUniform.h"
#include "Population.h"
#include "RandomUtil.h"

void SelectorUniform::prepare(Population const & population)
{
	endPop = population.size() - 1;
}

Solution & SelectorUniform::select(Population & population)
{
	size_t mValueRandom = RandomUtil::randomInRange(0, endPop);
	return population[mValueRandom];
}

