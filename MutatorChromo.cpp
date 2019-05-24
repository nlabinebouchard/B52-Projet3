
#include "MutatorChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorChromo::mutate(Solution & offspring)
{
	size_t bitFlip;
	if (RandomUtil::generateEvent(mMutationRate)) {
		bitFlip = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		offspring.chromosome().flip(bitFlip);
	}
}
