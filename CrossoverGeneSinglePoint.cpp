
#include "CrossoverGeneSinglePoint.h"
#include "RandomUtil.h"
#include "Solution.h"


void CrossoverGeneSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	size_t mPosBit{};
	for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
		mPosBit += offspring.chromosome().readGene(i);
		if (i > 0) {
			mBitPivot = RandomUtil::randomInRange((mPosBit - genitor1.chromosome().readGene(i)), mPosBit - 1);

			for (size_t j = (mPosBit - genitor1.chromosome().readGene(i)); j < mPosBit; ++j) {
				if (j < mBitPivot) {
					offspring.chromosome().write(j, genitor1.chromosome().read(j));
				}
				else {
					offspring.chromosome().write(j, genitor2.chromosome().read(j));
				}
			}
		}
		else {
			mBitPivot = RandomUtil::randomInRange(0, mPosBit - 1);

			for (size_t j{}; j < mPosBit; ++j) {
				if (j < mBitPivot) {
					offspring.chromosome().write(j, genitor1.chromosome().read(j));
				}
				else {
					offspring.chromosome().write(j, genitor2.chromosome().read(j));
				}
			}
		}
	}
}
