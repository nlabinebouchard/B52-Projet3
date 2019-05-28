
#include "MutatorSwapChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorSwapChromo::mutate(Solution & offspring)
{

	size_t fstRandBit{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };
	size_t scdRandBit{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };

	bool notEqual{ false };
	while (!notEqual) {
		if (fstRandBit != scdRandBit) {
			notEqual = true;
		}
		else {
			scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		}
	}

	bool tempo{ offspring.chromosome().read(fstRandBit) };
	offspring.chromosome().write(fstRandBit, offspring.chromosome().read(scdRandBit));
	offspring.chromosome().write(scdRandBit, tempo);
	
}