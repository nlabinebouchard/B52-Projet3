#include "ShapeSolution.h"


ShapeSolution::ShapeSolution(Canevas  * ref)
	:refCanevas{ ref }
{}

void ShapeSolution::processFitness()
{

	if ((*this).outOfCanvas()) {
		setFitness(0);
	}
	else {
		double fitness = (*this).area();
		for (auto & obs : refCanevas->obstacles())
		{
			if ((*this).distance(obs) == -1) {
				fitness /= 100;
			}
		}

		setFitness(fitness);
	}
}

