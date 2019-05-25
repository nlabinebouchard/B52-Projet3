#ifndef MUTATOR_SWAP_GENE_H
#define MUTATOR_SWAP_GENE_H

#include "Mutator.h"

class MutatorSwapGene : public Mutator
{
public:
	MutatorSwapGene() = default;
	~MutatorSwapGene() = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_SWAP_GENE_H