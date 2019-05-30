
#include "MutatorGeneLeastSignificant.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorGeneLeastSignificant::mutate(Solution & offspring)
{
	size_t posBit{};
	size_t lastPosBit{};

	for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
		
		size_t mostSignificant{ offspring.chromosome().readGene(i) };
		posBit += offspring.chromosome().readGene(i) - 1;
		if (mostSignificant % 2 == 0) {
			mostSignificant = mostSignificant / 2;
		}
		else {
			mostSignificant = (mostSignificant -1) / 2;
		}

		offspring.chromosome().flip(RandomUtil::randomInRange(lastPosBit + mostSignificant, posBit));
		++posBit;
		lastPosBit = posBit;
	}
}
