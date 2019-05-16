#include "RandomUtil.h"


std::random_device RandomUtil::randomDevice;
std::mt19937 RandomUtil::randomGenerator(randomDevice());


bool RandomUtil::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

int RandomUtil::randomInRange(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);	
	return dist(randomGenerator);
}

size_t RandomUtil::randomInRange(size_t min, size_t max)
{
	std::uniform_int_distribution<size_t> dist(min, max);
	return dist(randomGenerator);
}

