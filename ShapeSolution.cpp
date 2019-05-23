#include "ShapeSolution.h"


ShapeSolution::ShapeSolution(Canevas  * ref)
	:refCanevas{ ref }
{}

void ShapeSolution::processFitness()
{
	setFitness((*this).area());
}

