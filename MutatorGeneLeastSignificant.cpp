
#include "MutatorGeneLeastSignificant.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorGeneLeastSignificant::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		size_t posBit{};
		size_t lastPosBit{};

		for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {

			size_t leastSignificant{ offspring.chromosome().readGene(i) };
			posBit += offspring.chromosome().readGene(i) - 1;
			if (leastSignificant % 2 == 0) {
				leastSignificant = leastSignificant / 2;
			}
			else {
				leastSignificant = (leastSignificant - 1) / 2;
			}

			offspring.chromosome().flip(RandomUtil::randomInRange(lastPosBit + leastSignificant, posBit));
			++posBit;
			lastPosBit = posBit;
		}
	}
}
