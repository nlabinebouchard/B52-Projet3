#pragma once

#include "Solution.h"
#include "Selector.h"
#include "Crossover.h"
#include "Mutator.h"

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
