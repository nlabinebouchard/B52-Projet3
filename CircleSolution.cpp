#include "CircleSolution.h"

CircleSolution::CircleSolution(Canevas * ref)
	:ShapeSolution(ref)
{
	std::vector <size_t> vectSize(3);
	vectSize[0] = 10; // x
	vectSize[1] = 10; // y
	vectSize[2] = 10; // r

	mChromosome.writeGene(vectSize);
	mChromosome.writeData(encode());
}

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

std::vector<bool> CircleSolution::encode()
{
	std::vector<bool> vectRetour;
	size_t copieX{ x };
	size_t copieY{ y };
	size_t copieR{ r };
	size_t compteur{};

	for (auto & chrom : mChromosome.myGene()) {
		compteur += chrom;
	}
	vectRetour.resize(compteur);
	compteur = 0;
	for (size_t i{}; i < mChromosome.myGene()[0]; ++i) {
		vectRetour[compteur] = copieX & 1;
		copieX >>= 1;
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[1]; ++i) {
		vectRetour[compteur] = copieY & 1;
		copieY >>= 1;
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[2]; ++i) {
		vectRetour[compteur] = copieR & 1;
		copieR >>= 1;
		++compteur;
	}

	return vectRetour;
}

void CircleSolution::decode()
{
	x = 0;
	y = 0;
	r = 0;
	size_t compteur{};

	for (size_t i{}; i < mChromosome.myGene()[0]; ++i) {
		x += mChromosome.myData()[compteur];
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[1]; ++i) {
		y += mChromosome.myData()[compteur];
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[2]; ++i) {
		r += mChromosome.myData()[compteur];
		++compteur;
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

	mChromosome.writeData(encode());
}

void CircleSolution::assign(const Solution *  solution)
{
	CircleSolution const * c{ dynamic_cast<CircleSolution const *>(solution) };
	if (c) {
		Solution::assign(solution);
		x = c->x;
		y = c->y;
		r = c->r;
	}
}


