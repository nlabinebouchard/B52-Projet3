
#include "MutatorInversionChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorInversionChromo::mutate(Solution & offspring)
{
	size_t fstRandBit;
	size_t scdRandBit;
	std::vector<bool> mVecValueTempo;
	bool notEqual = false;

	if (RandomUtil::generateEvent(mMutationRate)) {
		fstRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);
		scdRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);

		while (!notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = true;
			}
			else {
				scdRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);
			}
		}

		if (fstRandBit < scdRandBit) {
			mVecValueTempo.resize(scdRandBit - fstRandBit + 1);
			for (size_t i = fstRandBit; i <= scdRandBit; ++i) {
				mVecValueTempo.at(i - fstRandBit) = offspring.chromosome().read(i);
			}
			std::reverse(mVecValueTempo.begin(), mVecValueTempo.end());
			for (size_t i = fstRandBit; i <= scdRandBit; ++i) {
				offspring.chromosome().write(i, mVecValueTempo.at(i - fstRandBit));
			}
		}
		else {
			mVecValueTempo.resize(fstRandBit - scdRandBit + 1);
			for (size_t i = scdRandBit; i <= fstRandBit; ++i) {
				mVecValueTempo.at(i - scdRandBit) = offspring.chromosome().read(i);
			}
			std::reverse(mVecValueTempo.begin(), mVecValueTempo.end());
			for (size_t i = scdRandBit; i <= fstRandBit; ++i) {
				offspring.chromosome().write(i, mVecValueTempo.at(i - scdRandBit));
			}
		}
	}
}
