#include "ShapeSolution.h"


ShapeSolution::ShapeSolution(Canevas  * ref)
	:refCanevas{ ref }
{}


ShapeSolution::~ShapeSolution()
{
}

void ShapeSolution::processFitness()
{
	setFitness((*this).area());
}

