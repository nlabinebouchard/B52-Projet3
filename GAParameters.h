#pragma once

#include "Solution"
#include "Selector"
#include "Crossover"
#include "Mutator"

	struct GAParameters
	{
		size_t populationSize;
		size_t elitismsize;
		double mutationRate;
		double convergenceRate;
		size_t maximumGenerationCount;
		Solution * solutionSample;
		Selector * selector;
		Crossover * crossover;
		Mutator * mutator;
	};
