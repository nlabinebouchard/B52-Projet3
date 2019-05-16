
#include "CrossoverGeneSinglePoint.h"
#include "RandomUtil.h"
#include "Solution.h"

void CrossoverGeneSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
		
		if (i > 0) {
			mBitPivot = RandomUtil::randomInRange(genitor1.chromosome().readGene(i-1), genitor1.chromosome().readGene(i)-1);
			
			for (size_t j=offspring.chromosome().readGene(i-1); j < offspring.chromosome().readGene(i); ++j) {
				if (j < mBitPivot) {
					offspring.chromosome().write(j, genitor1.chromosome().read(i));
				}
				else {
					offspring.chromosome().write(j, genitor2.chromosome().read(i));
				}
			}
		}
		else {
			mBitPivot = RandomUtil::randomInRange(0, genitor1.chromosome().readGene(i)-1);
			
			for (size_t j{}; j < offspring.chromosome().readGene(i); ++j) {
				if (j < mBitPivot) {
					offspring.chromosome().write(j, genitor1.chromosome().read(i));
				}
				else {
					offspring.chromosome().write(j, genitor2.chromosome().read(i));
				}
			}
		}

	}
}
