
#include "MutatorGene.h"
#include "RandomUtil.h"

void MutatorGene::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)){

		for (int i{}; i < offspring.chromosome().sizeGene(); ++i) {
			if (i > 0) {
				mBitFlip = RandomUtil::randomInRange(offspring.chromosome.getValueGene(i-1), offspring.chromosome.getValueGene(i));
			}
			else {
				mBitFlip = RandomUtil::randomInRange(0, offspring.chromosome.getValueGene(i));
			}
			offspring.chromosome().flip(mBitFlip);
		}
	}
}
