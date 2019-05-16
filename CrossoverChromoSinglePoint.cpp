
#include "CrossoverChromoSinglePoint.h"
#include "RandomUtil.h"


void CrossoverChromoSinglePoint::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{

	bitPivot = RandomUtil::randomInRange(0, genitor1.chromosome.size());
	offspring.chromosome().resize(genitor1.chromosome().size());

	genitor1.chromosome().read();
	genitor2.chromosome().read();

	//std::vector<bool> *cur = offspring.chromosome().begin()
	//std::vector<bool> *end = offspring.chromosome().end()

	//while(cur < end){
	//
	//}

	//	
	for (index=0; index < bitPivot; ++index) {
		offspring.chromosome().write(index, genitor1.chromosome().read(index));
	}

	for (index = bitPivot; index < genitor1.chromosome().size(); ++index) {
		offspring.chromosome().write(index, genitor2.chromosome().read(index));
	}

}
