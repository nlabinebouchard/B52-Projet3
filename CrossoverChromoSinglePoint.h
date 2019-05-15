#ifndef CROSSOVERCHROMOSINGLEPOINT_H
#define CROSSOVERCHROMOSINGLEPOINT_H

#include "Crossover.h"
class Solution;

class CrossoverChromoSinglePoint : public Crossover
{
public:
	CrossoverChromoSinglePoint()=default;
	~CrossoverChromoSinglePoint()=default;

	void breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;

private:




};

#endif // CROSSOVERCHROMOSINGLEPOINT_H