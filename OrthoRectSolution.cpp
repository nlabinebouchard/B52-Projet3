#include "OrthoRectSolution.h"

OrthoRectSolution::OrthoRectSolution()
{
}

OrthoRectSolution::~OrthoRectSolution()
{
}

double OrthoRectSolution::area() { return width*heigth; }

double OrthoRectSolution::perimeter() { return 2*width+2*heigth; }

