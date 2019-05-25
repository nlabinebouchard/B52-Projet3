#ifndef MUTATOR_INVERSION_CHROMO_H
#define MUTATOR_INVERSION_CHROMO_H

#include "Mutator.h"

class MutatorInversionChromo : public Mutator
{
public:
	MutatorInversionChromo() = default;
	~MutatorInversionChromo() = default;

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_INVERSION_CHROMO_H