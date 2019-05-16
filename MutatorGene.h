#ifndef MUTATORGENE_H
#define MUTATORGENE_H

#include "Mutator.h"

class MutatorGene : public Mutator
{
public:

	void mutate(Solution & offspring) override;

private:
	int mBitFlip;

};

#endif // MUTATORGENE_H