
#include "MutatorSwapGene.h"
#include "RandomUtil.h"
#include "Solution.h"


void MutatorSwapGene::mutate(Solution & offspring)
{
	size_t posBit{};
	size_t lastPosBit{};
	bool notEqual{ false };


	for (size_t z{}; z < offspring.chromosome().sizeGene(); ++z) {
		posBit += offspring.chromosome().readGene(z) - 1;

		size_t fstRandBit{ RandomUtil::randomInRange(lastPosBit, posBit) };
		size_t scdRandBit{ RandomUtil::randomInRange(lastPosBit, posBit) };

		while (!notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = true;
			}
			else {
				scdRandBit = RandomUtil::randomInRange(lastPosBit, posBit);
			}
		}

		bool tempo{ offspring.chromosome().read(fstRandBit) };
		offspring.chromosome().write(fstRandBit, offspring.chromosome().read(scdRandBit));
		offspring.chromosome().write(scdRandBit, tempo);

		++posBit;
		lastPosBit = posBit;
		notEqual = false;
	}

}

