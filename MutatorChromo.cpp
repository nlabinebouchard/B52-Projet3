
#include "MutatorChromo.h"
#include "RandomUtilEvoChromo.h"


void MutatorChromo::mutate(Solution & chromoMu)
{
	if (RandomUtilEvoChromo::generateEvent(mMutationRate)) {
		//bitFlip = RandomUtilEvoChromo::randomInRange(0, chromoMu.chromosome.size()-1);
		bitFlip = RandomUtilEvoChromo::randomInRange(0, chromoMu.chromosome.size());
		chromoMu.chromosome().flip(bitFlip);
	}
}
