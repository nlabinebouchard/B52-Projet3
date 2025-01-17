#ifndef MUTATORGENE_H
#define MUTATORGENE_H

#include "Mutator.h"

class MutatorGene : public Mutator
{
public:
	MutatorGene() = default;
	~MutatorGene() override= default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATORGENE_H