
#include "MutatorSwapGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorSwapGene::mutate(Solution & offspring)
{
	size_t mPosBit{};
	size_t fstRandBit;
	size_t scdRandBit;
	bool tempo;
	bool notEqual = true;

	if (RandomUtil::generateEvent(mMutationRate)) {

		for (size_t z{}; z < offspring.chromosome().sizeGene(); ++z) {
			mPosBit += offspring.chromosome().readGene(z) - 1;

			if (z > 0) {
				fstRandBit = RandomUtil::randomInRange(mPosBit - (offspring.chromosome().readGene(z) - 1), mPosBit);
				scdRandBit = RandomUtil::randomInRange(mPosBit - (offspring.chromosome().readGene(z) - 1), mPosBit);
			}
			else {
				fstRandBit = RandomUtil::randomInRange(0, mPosBit);
				scdRandBit = RandomUtil::randomInRange(0, mPosBit);
			}

			while (notEqual) {
				if (fstRandBit != scdRandBit) {
					notEqual = false;
				}
				scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
			}

			tempo = offspring.chromosome().read(fstRandBit);
			offspring.chromosome().write(fstRandBit, offspring.chromosome().read(scdRandBit));
			offspring.chromosome().write(scdRandBit, tempo);

			++mPosBit;
			notEqual = true;
		}
	}
}
