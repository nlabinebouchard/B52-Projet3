#include "ShapeSolution.h"


ShapeSolution::ShapeSolution()
{
}


ShapeSolution::~ShapeSolution()
{
}

void ShapeSolution::processFitness()
{
	setFitness((*this).perimeter());
}
