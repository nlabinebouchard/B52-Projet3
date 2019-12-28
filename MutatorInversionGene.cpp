
#include "MutatorInversionGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorInversionGene::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		std::vector<bool> vecValueTempo;
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
			++posBit;
			lastPosBit = posBit;
			notEqual = false;
		}
	}
}

