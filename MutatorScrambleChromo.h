#ifndef MUTATOR_SCRAMBLE_CHROMO_H
#define MUTATOR_SCRAMBLE_CHROMO_H

#include "Mutator.h"

class MutatorScrambleChromo : public Mutator
{
public:
	MutatorScrambleChromo() = default;
	~MutatorScrambleChromo() override = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_SCRAMBLE_CHROMO_H