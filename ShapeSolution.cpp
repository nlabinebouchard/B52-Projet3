#include "ShapeSolution.h"


ShapeSolution::ShapeSolution(Canevas  * ref)
	:refCanevas{ ref }
{}

void ShapeSolution::processFitness()
{

	if (outOfCanvas()) {
		setFitness(0.0);
	}
	else {
		double fitness = area();
		for (auto & obs : refCanevas->obstacles())
		{
			if (distance(obs) == -1) {
				fitness /= 100.0;
			}
		}

		setFitness(pow(fitness,2));
	}
}

