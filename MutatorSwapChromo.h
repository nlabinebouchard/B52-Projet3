#ifndef MUTATOR_SWAP_CHROMO_H
#define MUTATOR_SWAP_CHROMO_H

#include "Mutator.h"

class MutatorSwapChromo : public Mutator
{
public:
	MutatorSwapChromo() = default;
	~MutatorSwapChromo() override = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_SWAP_CHROMO_H