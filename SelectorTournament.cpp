#include "SelectorTournament.h"
#include "RandomUtil.h"
#include "Population.h"
#include "Solution.h"
	
Solution & SelectorTournament::select(Population & population)
{
	std::vector<Solution*> solutionSelected;
	size_t randTourPop;

	if (population.size() == 1) {
		return population[0];
	}
	else {
		randTourPop = RandomUtil::randomInRange(2, population.size() - 1);
	}

	solutionSelected.resize(randTourPop);
	for (auto & sol : solutionSelected) {
		sol = &SelectorRouletteWheel::select(population);
	}

	std::sort(solutionSelected.begin(), solutionSelected.end(), ToBeCompare);

	return *solutionSelected.back();
}

bool SelectorTournament::ToBeCompare(Solution* s1, Solution* s2)
{
	return s1->fitness() < s2->fitness();
}

