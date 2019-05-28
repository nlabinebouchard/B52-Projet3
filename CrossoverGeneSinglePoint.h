#ifndef CROSSOVER_GENE_SINGLE_POINT_H
#define CROSSOVER_GENE_SINGLE_POINT_H

#include "Crossover.h"
class Solution;

class CrossoverGeneSinglePoint : public Crossover
{
public:
	CrossoverGeneSinglePoint() = default;
	~CrossoverGeneSinglePoint() = default;

	void breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;

};

#endif // CROSSOVER_GENE_SINGLE_POINT_H