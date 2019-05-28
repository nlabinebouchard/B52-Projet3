
#include "MutatorScrambleChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorScrambleChromo::mutate(Solution & offspring)
{
	std::vector<bool> vecValueTempo;
	size_t lengVecTempo;
	bool notEqual{ false };


	size_t fstRandRange{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };
	size_t scdRandRange{ RandomUtil::randomInRange(0, offspring.chromosome().size() - 1) };

	while (!notEqual) {
		if (fstRandRange != scdRandRange) {
			notEqual = true;
		}
		else {
			scdRandRange = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		}
	}
	notEqual = false;

	if (fstRandRange > scdRandRange) {
		size_t tempoBit{ fstRandRange };
		fstRandRange = scdRandRange;
		scdRandRange = tempoBit;
	}

	lengVecTempo = scdRandRange - fstRandRange + 1;
	vecValueTempo.resize(lengVecTempo);
	for (size_t i{ fstRandRange }; i <= scdRandRange; ++i) {
		vecValueTempo[i - fstRandRange] = offspring.chromosome().read(i);
	}
	for (size_t i{ 0 }; i < vecValueTempo.size(); ++i) {
		size_t fstRandBit{ RandomUtil::randomInRange(0, lengVecTempo - 1) };
		size_t scdRandBit{ RandomUtil::randomInRange(0, lengVecTempo - 1) };

		while (!notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = true;
			}
			else {
				scdRandBit = RandomUtil::randomInRange(0, lengVecTempo - 1);
			}
		}

		bool tempo = vecValueTempo[fstRandBit];
		vecValueTempo[fstRandBit] = vecValueTempo[scdRandBit];
		vecValueTempo[scdRandBit] = tempo;
		notEqual = false;
	}
	for (size_t i{ fstRandRange }; i <= scdRandRange; ++i) {
		offspring.chromosome().write(i, vecValueTempo[i - fstRandRange]);
	}
	
}
