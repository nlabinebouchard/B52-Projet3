#ifndef MUTATOR_SCRAMBLE_GENE_H
#define MUTATOR_SCRAMBLE_GENE_H

#include "Mutator.h"

class MutatorScrambleGene : public Mutator
{
public:

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_SCRAMBLE_GENE_H