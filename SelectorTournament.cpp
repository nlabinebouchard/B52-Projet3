#include "SelectorTournament.h"
#include "RandomUtil.h"
#include "Population.h"
#include "Solution.h"
	
Solution & SelectorTournament::select(Population & population)
{
	size_t randTourPop = RandomUtil::randomInRange(2, population.size()-1);
	Solution * solution = NULL;

	mSolutionSelected.resize(randTourPop);

	for (size_t i = 0; i < randTourPop; ++i) {

		*solution = SelectorRouletteWheel::select(population);

		mSolutionSelected.insert(mSolutionSelected.begin()+i, solution);
	}
	std::sort(mSolutionSelected.begin(), mSolutionSelected.end(), ToBeCompare);

	return *mSolutionSelected.back();
}

bool SelectorTournament::ToBeCompare(Solution* s1, Solution* s2)
{
	return s1->fitness() < s2->fitness();
}
