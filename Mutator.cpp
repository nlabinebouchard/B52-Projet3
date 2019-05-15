
#include "Mutator.h"

double Mutator::mutationRate() const
{
	return mMutationRate;
}

void Mutator::setMutationRate(double newRate)
{
	if (newRate >= 0.00 && newRate <= 1.00) {
		mMutationRate = newRate;
	}
}
