#ifndef MUTATOR_GENE_LEAST_SIGNIFICANT_H
#define MUTATOR_GENE_LEAST_SIGNIFICANT_H

#include "Mutator.h"

class MutatorGeneLeastSignificant : public Mutator
{
public:
	MutatorGeneLeastSignificant() = default;
	~MutatorGeneLeastSignificant() = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_GENE_LEAST_SIGNIFICANT_H