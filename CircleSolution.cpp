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
	int calc1 = obs.posX() - x;
	int calc2 = obs.posY() - y;

	double dist = sqrt(pow(calc1, 2) + pow(calc2, 2));

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
	size_t compteur{};

	for (auto & chrom : mChromosome.myGene()) {
		compteur += chrom;
	}
	vectRetour.resize(compteur);
	compteur = 0;
	for (size_t i{ mChromosome.myGene()[0] }; i > 0; --i) {
		size_t exposant{ static_cast<size_t>(pow(2, i)) };
		vectRetour[compteur] = x & exposant;
		++compteur;
	}

	for (size_t i{ mChromosome.myGene()[1] }; i > 0; --i) {
		size_t exposant{ static_cast<size_t>(pow(2, i)) };
		vectRetour[compteur] = y & exposant;
		++compteur;
	}

	for (size_t i{ mChromosome.myGene()[2] }; i > 0; --i) {
		size_t exposant{ static_cast<size_t>(pow(2, i)) };
		vectRetour[compteur] = r & exposant;
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
		x <<= 1;
		x += mChromosome.myData()[compteur];
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[1]; ++i) {
		y <<= 1;
		y += mChromosome.myData()[compteur];
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[2]; ++i) {
		r <<= 1;
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
	/*r = RandomUtil::randomInRange(1, refCanevas->width());*/

	size_t droite = refCanevas->width() - x;
	size_t bas = refCanevas->height() - y;

	mListDist.clear();
	mListDist.push_front(x);
	mListDist.push_front(y);
	mListDist.push_front(droite);
	mListDist.push_front(bas);
	mListDist.sort();

	r = RandomUtil::randomInRange(1, mListDist.front()); 


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

bool CircleSolution::outOfCanvas() const
{
	int mX{ static_cast<int>(x) };
	int mY{ static_cast<int>(y) };
	int mR{ static_cast<int>(r) };

	return (mX - mR) < 0 || (mX + mR) >= static_cast<int>(refCanevas->width()) || (mY - mR) < 0 || (mY + mR) >= static_cast<int>(refCanevas->height());

}


