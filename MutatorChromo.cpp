
#include "MutatorChromo.h"
#include "RandomUtil.h"


void MutatorChromo::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		//bitFlip = RandomUtilEvoChromo::randomInRange(0, chromoMu.chromosome.size()-1);
		bitFlip = RandomUtil::randomInRange(0, offspring.chromosome.size());
		offspring.chromosome().flip(bitFlip);
	}
}
