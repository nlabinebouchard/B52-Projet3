
#include "MutatorChromo.h"
#include "RandomUtil.h"
#include "Solution.h"

void MutatorChromo::mutate(Solution & offspring)
{
	offspring.chromosome().flip(RandomUtil::randomInRange(0, offspring.chromosome().size() - 1));
}
