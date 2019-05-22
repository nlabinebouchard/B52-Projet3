
#include "MutatorScrambleGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorScrambleGene::mutate(Solution & offspring)
{
	size_t mPosBit{};
	size_t fstRandBit;
	size_t scdRandBit;
	std::vector<bool> mVecValueTempo;

	if (RandomUtil::generateEvent(mMutationRate)) {

		for (size_t z{}; z < offspring.chromosome().sizeGene(); ++z) {

			mPosBit += offspring.chromosome().readGene(z) - 1;
			fstRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);
			scdRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);

			if (z > 0) {
				fstRandBit = RandomUtil::randomInRange(mPosBit - (offspring.chromosome().readGene(z) - 1), mPosBit);
				scdRandBit = RandomUtil::randomInRange(mPosBit - (offspring.chromosome().readGene(z) - 1), mPosBit);
			}
			else {
				fstRandBit = RandomUtil::randomInRange(0, mPosBit);
				scdRandBit = RandomUtil::randomInRange(0, mPosBit);
			}

			while (true) {
				if (fstRandBit != scdRandBit) {
					break;
				}
				scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
			}

			if (fstRandBit < scdRandBit) {
				mVecValueTempo.resize(scdRandBit - fstRandBit + 1);
				for (size_t i = fstRandBit; i < scdRandBit; ++i) {
					mVecValueTempo.insert(mVecValueTempo.begin() + i, offspring.chromosome().read(i));
				}
				//std::reverse(mVecValueTempo.begin(), mVecValueTempo.end());
				for (size_t i = fstRandBit; i < scdRandBit; ++i) {
					offspring.chromosome().write(i, mVecValueTempo.at(i));
				}
			}
			else {
				mVecValueTempo.resize(fstRandBit - scdRandBit + 1);
				for (size_t i = scdRandBit; i < fstRandBit; ++i) {
					mVecValueTempo.insert(mVecValueTempo.begin() + i, offspring.chromosome().read(i));
				}
				//std::reverse(mVecValueTempo.begin(), mVecValueTempo.end());
				for (size_t i = scdRandBit; i < fstRandBit; ++i) {
					offspring.chromosome().write(i, mVecValueTempo.at(i));
				}
			}
			++mPosBit;
		}
	}


	
}
