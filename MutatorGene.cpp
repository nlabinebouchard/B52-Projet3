
#include "MutatorGene.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorGene::mutate(Solution & offspring)
{
	size_t posBit{};
	size_t lastPosBit{};

	for (size_t i{}; i < offspring.chromosome().sizeGene(); ++i) {
		posBit += offspring.chromosome().readGene(i) - 1;

		offspring.chromosome().flip(RandomUtil::randomInRange(lastPosBit, posBit));
		++posBit;
		lastPosBit = posBit;
	}

}
