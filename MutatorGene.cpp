
#include "MutatorGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorGene::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)){
		for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
			if (i > 0) {
				mBitFlip = RandomUtil::randomInRange(offspring.chromosome().readGene(i-1), offspring.chromosome().readGene(i)-1);
			}
			else {
				mBitFlip = RandomUtil::randomInRange(0, offspring.chromosome().readGene(i)-1);
			}
			offspring.chromosome().flip(mBitFlip);
		}
	}
}
