
#include "CrossoverGeneSinglePoint.h"
#include "RandomUtil.h"

void CrossoverGeneSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	for (int i{}; i < genitor1.chromosome().sizeGene(); ++i) {

		if (i > 0) {
			mBitFlip = RandomUtil::randomInRange(genitor1.chromosome.getValue(i-1), genitor1.chromosome.getValue(i));
		}
		else {
			mBitFlip = RandomUtil::randomInRange(0, genitor1.chromosome.getValue(i));
		}

		for (int j{}; j < genitor1.chromosome().getValue(i); ++j) {

			if (j < mBitFlip) {
				offspring.chromosome().write(j, genitor1.chromosome().read(i));
			}
			else {
				offspring.chromosome().write(j, genitor2.chromosome().read(i));
			}
		}
	}
}
