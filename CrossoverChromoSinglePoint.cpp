
#include "CrossoverChromoSinglePoint.h"
#include "RandomUtil.h"
#include "Solution.h"


void CrossoverChromoSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	size_t bitPivot;
	size_t index{};

	bitPivot = RandomUtil::randomInRange(0, offspring.chromosome().size());
	offspring.chromosome().resize(genitor1.chromosome().size());

	for (index; index < bitPivot; ++index) {
		offspring.chromosome().write(index, genitor1.chromosome().read(index));
	}

	for (index = bitPivot; index < offspring.chromosome().size(); ++index) {
		offspring.chromosome().write(index, genitor2.chromosome().read(index));
	}
}
