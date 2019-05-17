#include "CircleSolution.h"

CircleSolution::CircleSolution()
{
}

CircleSolution::~CircleSolution()
{
}

double CircleSolution::area() 
{ 
	return M_PI * pow(r,2) ; 
}

double CircleSolution::perimeter()
{
	return 2*M_PI*r;
}

void CircleSolution::draw()
{
	Console::getInstance().writer().createImage("Forme").drawCircle(x, y, r,'w', ConsoleColor::tb);
}
