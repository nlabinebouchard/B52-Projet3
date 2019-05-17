#ifndef MUTATOR_CHROMO_H
#define MUTATOR_CHROMO_H

#include "Mutator.h"

class MutatorChromo : public Mutator
{
public:
	MutatorChromo() = default;
	~MutatorChromo() = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATORCHROMO_H