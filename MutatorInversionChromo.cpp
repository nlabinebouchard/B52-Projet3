
#include "MutatorInversionChromo.h"
#include "RandomUtil.h"
#include "Solution.h"


void MutatorInversionChromo::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		std::vector<bool> vecValueTempo;
		bool notEqual{ false };
		size_t fstRandBit{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };
		size_t scdRandBit{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };

		while (!notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = true;
			}
			else {
				scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
			}
		}

		if (fstRandBit > scdRandBit) {
			size_t tempoBit{ fstRandBit };
			fstRandBit = scdRandBit;
			scdRandBit = tempoBit;
		}

		vecValueTempo.resize(scdRandBit - fstRandBit + 1);
		for (size_t i{ fstRandBit }; i <= scdRandBit; ++i) {
			vecValueTempo[i - fstRandBit] = offspring.chromosome().read(i);
		}
		std::reverse(vecValueTempo.begin(), vecValueTempo.end());
		for (size_t i{ fstRandBit }; i <= scdRandBit; ++i) {
			offspring.chromosome().write(i, vecValueTempo[i - fstRandBit]);
		}
	}
}
