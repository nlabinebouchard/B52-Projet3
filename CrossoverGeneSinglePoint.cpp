
#include "CrossoverGeneSinglePoint.h"
#include "RandomUtil.h"
#include "Solution.h"

void CrossoverGeneSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	size_t mPosBit{};
	size_t lastPosBit{};

	for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
		mPosBit += offspring.chromosome().readGene(i);
		size_t bitPivot{ RandomUtil::randomInRange(lastPosBit, mPosBit - 1) };

		for (size_t j{ lastPosBit }; j < bitPivot; ++j) {
			offspring.chromosome().write(j, genitor1.chromosome().read(j));
		}
		for (size_t j{ bitPivot }; j < mPosBit; ++j) {
			offspring.chromosome().write(j, genitor2.chromosome().read(j));
		}
		lastPosBit = mPosBit;
	}
}
