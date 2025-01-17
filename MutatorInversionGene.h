#ifndef MUTATOR_INVERSION_GENE_H
#define MUTATOR_INVERSION_GENE_H

#include "Mutator.h"

class MutatorInversionGene : public Mutator
{
public:
	MutatorInversionGene() = default;
	~MutatorInversionGene() override = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_INVERSION_GENE_H