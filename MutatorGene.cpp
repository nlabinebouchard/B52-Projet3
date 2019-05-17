
#include "MutatorGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorGene::mutate(Solution & offspring)
{
	size_t mBitFlip;
	size_t mPosBit{};

	if (RandomUtil::generateEvent(mMutationRate)){
		for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
			mPosBit += offspring.chromosome().readGene(i)-1;
			if (i > 0) {
				mBitFlip = RandomUtil::randomInRange(mPosBit - offspring.chromosome().readGene(i), mPosBit);
			}
			else {
				mBitFlip = RandomUtil::randomInRange(0, mPosBit);
			}
			++mPosBit;
			offspring.chromosome().flip(mBitFlip);
		}
	}
}
