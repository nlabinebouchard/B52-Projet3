#ifndef MUTATORCHROMO_H
#define MUTATORCHROMO_H

#include "Mutator.h"

class MutatorChromo : public Mutator
{
public:
	MutatorChromo() = default;
	~MutatorChromo() = default;

	void mutate(Solution & chromo) override;

private:
	int bitFlip;
};

#endif // MUTATORCHROMO_H