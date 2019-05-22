#ifndef MUTATOR_INVERSION_CHROMO_H
#define MUTATOR_INVERSION_CHROMO_H

#include "Mutator.h"

class MutatorInversionChromo : public Mutator
{
public:

	void mutate(Solution & offspring) override;

};

#endif // MUTATOR_INVERSION_CHROMO_H