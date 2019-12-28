#include "RandomUtil.h"


std::random_device RandomUtil::randomDevice;
std::mt19937 RandomUtil::randomGenerator(randomDevice());


bool RandomUtil::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

size_t RandomUtil::randomInRange(size_t min, size_t max)
{
	std::uniform_int_distribution<size_t> dist(min, max);
	return dist(randomGenerator);
}

double RandomUtil::randomRangeHundred(double min, double max)
{
	std::uniform_real_distribution<double> dist(min, max);
	return dist(randomGenerator);
}

