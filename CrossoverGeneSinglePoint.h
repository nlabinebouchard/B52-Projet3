#ifndef CROSSOVERGENESINGLEPOINT_H
#define CROSSOVERGENESINGLEPOINT_H

#include "Crossover.h"
class Solution;

class CrossoverGeneSinglePoint : public Crossover
{
public:
	CrossoverGeneSinglePoint() = default;
	~CrossoverGeneSinglePoint() = default;

	void breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;

private:




};

#endif // CROSSOVERGENESINGLEPOINT_H