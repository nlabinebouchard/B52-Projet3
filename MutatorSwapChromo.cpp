
#include "MutatorSwapChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorSwapChromo::mutate(Solution & offspring)
{
	size_t fstRandBit;
	size_t scdRandBit;
	bool tempo;
	bool notEqual = true;

	if (RandomUtil::generateEvent(mMutationRate)) {
		fstRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);

		while (notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = false;
			}
			scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		}

		tempo = offspring.chromosome().read(fstRandBit);
		offspring.chromosome().write(fstRandBit, offspring.chromosome().read(scdRandBit));
		offspring.chromosome().write(scdRandBit, tempo);
	}
}
