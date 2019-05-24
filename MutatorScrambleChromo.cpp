
#include "MutatorScrambleChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorScrambleChromo::mutate(Solution & offspring)
{
	size_t fstRandBit;
	size_t scdRandBit;
	size_t fstRandPos;
	size_t scdRandPos;
	bool tempo;
	bool notEqual = true;
	std::vector<bool> mVecValueTempo;

	if (RandomUtil::generateEvent(mMutationRate)) {
		fstRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);
		scdRandBit = RandomUtil::randomInRange(1, offspring.chromosome().size() - 1);

		while (notEqual) {
			if (fstRandBit != scdRandBit) {
				notEqual = false;
			}
			scdRandBit = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
		}
		notEqual = true;

		if (fstRandBit < scdRandBit) {
			mVecValueTempo.resize(scdRandBit - fstRandBit + 1);
			for (size_t i = fstRandBit; i < scdRandBit; ++i) {
				mVecValueTempo.insert(mVecValueTempo.begin() + i, offspring.chromosome().read(i));
			}
			for (size_t i = fstRandBit; i < scdRandBit; ++i) {
				fstRandPos = RandomUtil::randomInRange(fstRandBit, offspring.chromosome().size() - 1);
				scdRandPos = RandomUtil::randomInRange(fstRandBit, offspring.chromosome().size() - 1);

				while (notEqual) {
					if (fstRandPos != scdRandPos) {
						notEqual=false;
					}
					scdRandPos = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
				}
				
				tempo = mVecValueTempo.at(fstRandPos);
				mVecValueTempo.insert(mVecValueTempo.begin()+fstRandPos, mVecValueTempo.at(scdRandPos));
				mVecValueTempo.insert(mVecValueTempo.begin() + scdRandPos, tempo);
				notEqual = true;
			}
			for (size_t i = fstRandBit; i < scdRandBit; ++i) {
				offspring.chromosome().write(i, mVecValueTempo.at(i));
			}
		}
		else {
			mVecValueTempo.resize(fstRandBit - scdRandBit + 1);
			for (size_t i = scdRandBit; i < fstRandBit; ++i) {
				mVecValueTempo.insert(mVecValueTempo.begin() + i, offspring.chromosome().read(i));
			}
			for (size_t i = scdRandBit; i < fstRandBit; ++i) {
				fstRandPos = RandomUtil::randomInRange(scdRandBit, offspring.chromosome().size() - 1);
				scdRandPos = RandomUtil::randomInRange(scdRandBit, offspring.chromosome().size() - 1);

				while (notEqual) {
					if (fstRandPos != scdRandPos) {
						notEqual=true;
					}
					scdRandPos = RandomUtil::randomInRange(0, offspring.chromosome().size() - 1);
				}
				tempo = mVecValueTempo.at(scdRandPos);
				mVecValueTempo.insert(mVecValueTempo.begin() + scdRandPos, mVecValueTempo.at(fstRandPos));
				mVecValueTempo.insert(mVecValueTempo.begin() + fstRandPos, tempo);
				notEqual = false;
			}
			for (size_t i = scdRandBit; i < fstRandBit; ++i) {
				offspring.chromosome().write(i, mVecValueTempo.at(i));
			}
		}
	}


}


//While(counterscra < randswathsize)
//	Dim swap1 = RAND.Next(0, randswathsize - 1)
//	Dim swap2 = RAND.Next(0, randswathsize - 1)
//	If(swap2 = swap1) Then
//	While(done = False)
//	swap2 = RAND.Next(0, randswathsize - 1)
//	If(swap2 <> swap1) Then
//	done = True
//	End If
//	End While
//	End If
//	TempK = K(swap1)
//	K(swap1) = K(swap2)
//	K(swap2) = TempK
//	counterscra += 1
//End While