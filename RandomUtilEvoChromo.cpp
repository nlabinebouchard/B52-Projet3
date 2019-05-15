#include "RandomUtilEvoChromo.h"


std::random_device RandomUtilEvoChromo::randomDevice;
std::mt19937 RandomUtilEvoChromo::randomGenerator(randomDevice());


bool RandomUtilEvoChromo::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

int RandomUtilEvoChromo::randomInRange(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);	
	return dist(randomGenerator);
}

