#include "CircleSolution.h"

CircleSolution::CircleSolution(Canevas * ref)
	:ShapeSolution(ref)
{}

double CircleSolution::area() const
{ 
	return M_PI * pow(r,2) ; 
}

double CircleSolution::perimeter() const
{
	return 2*M_PI*r;
}

double CircleSolution::distance(Obstacle const & obs) const
{
	size_t pX = static_cast<size_t>(obs.posX());
	size_t pY = static_cast<size_t>(obs.posY());
	double dist = sqrt(pow(pX - x, 2) + pow(pY - y, 2));

	if (dist - r >= 0) {
		return dist - r;
	}
	else {
		return -1;
	}
}

bool CircleSolution::collide(Obstacle const & obs) const
{
	if (distance(obs) == -1) {
		return true;
	}
	else {
		return false;
	}
}

void CircleSolution::draw(ConsoleWriter &curWriter) const
{
	curWriter.image("Forme").drawCircle(x, y, r,' ', ConsoleColor::bC);
}

std::vector<bool> CircleSolution::encode(std::vector<size_t> vectSize)
{
	std::vector<bool> vectRetour;
	size_t copieX{ x };
	size_t copieY{ y };
	size_t copieR{ r };

	for (size_t i{}; i < vectSize[0]; ++i) {
		vectRetour.push_back(copieX & 1);
		copieX >>= 1;
	}

	for (size_t i{ vectSize[0] }; i < vectSize[1]; ++i) {
		vectRetour.push_back(copieY & 1);
		copieY >>= 1;
	}

	for (size_t i{ vectSize[1] }; i < vectSize[2]; ++i) {
		vectRetour.push_back(copieR & 1);
		copieR >>= 1;
	}

	return std::vector<bool>();
}

void CircleSolution::decode(std::vector<bool> vect, std::vector<size_t> vectSize)
{
	x = 0;
	y = 0;
	r = 0;

	for (size_t i{}; i < vectSize[0]; ++i) {
		x += vect[i];
	}

	for (size_t i{ vectSize[0] }; i < vectSize[1]; ++i) {
		y += vect[i];
	}

	for (size_t i{ vectSize[1] }; i < vectSize[2]; ++i) {
		r += vect[i];
	}


}

Solution * CircleSolution::clone()
{
	return new CircleSolution(*this);
}

void CircleSolution::randomize()
{
	x = RandomUtil::randomInRange(1, refCanevas->width()-1);
	y = RandomUtil::randomInRange(1, refCanevas->height()-1);
	r = RandomUtil::randomInRange(1, refCanevas->width());

	while (r + y > refCanevas->height() || r + x > refCanevas->width() || x - r < 0 || y - r  < 0)
	{
		r /= 2;
	}

	int a{ 0 };
}
