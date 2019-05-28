#include "OrthoRectSolution.h"

OrthoRectSolution::OrthoRectSolution(Canevas * ref)
	:ShapeSolution(ref)
{
	std::vector <size_t> vectSize(4);
	vectSize[0] = 10; // x
	vectSize[1] = 10; // y
	vectSize[2] = 10; // witdh
	vectSize[3] = 10; // height

	mChromosome.writeGene(vectSize);
	mChromosome.writeData(encode(vectSize));
}

double OrthoRectSolution::area() const { return width*heigth; }

double OrthoRectSolution::perimeter() const { return 2*width+2*heigth; }

double OrthoRectSolution::distance(Obstacle const & obs) const
{
	size_t pX = static_cast<size_t>(obs.posX());
	size_t pY = static_cast<size_t>(obs.posY());

	if (x < pX && x + width > pX) {
		if (y < pY && y + heigth > pY) {
			return -1; // point a l'intérieur du rectangle
		}
		else if (y < pY) {
			return calculDistance(x, y + heigth, pX, pY);
		}
		else {
			return calculDistance(pX, y, pX, pY);
		}
	}
	else if (x < pX) {
		if (y < pY && y + heigth > pY) {
			return calculDistance(x + width, pY, pX, pY);
		}
		else if (y < pY) {
			return calculDistance(x + width, y + heigth, pX, pY);
		}
		else {
			return calculDistance(x + width, y, pX, pY);
		}
	}
	else {
		if (y < pY && y + heigth > pY) {
			return calculDistance(x, pY, pX, pY);
		}
		else if (y < pY) {
			return calculDistance(x, y + heigth, pX, pY);
		}
		else {
			return calculDistance(x, y, pX, pY);
		}
	}
}

double OrthoRectSolution::calculDistance(size_t x1, size_t y1, size_t x2, size_t y2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

bool OrthoRectSolution::collide(Obstacle const & obs) const
{
	if (distance(obs) == -1) {
		return true;
	}
	else {
		return false;
	}
}

void OrthoRectSolution::draw(ConsoleWriter &curWriter) const
{
	curWriter.image("Forme").drawRect(x, y, (int)width, heigth, ' ', ConsoleColor::bC);
	
}

std::vector<bool> OrthoRectSolution::encode(std::vector<size_t> vectSize)
{
	std::vector<bool> vectRetour;
	size_t copieX{x};
	size_t copieY{y};
	size_t copieWidth{width};
	size_t copieHeigth{heigth};
	size_t compteur{};

	for (auto & chrom : vectSize) {
		compteur += chrom;
	}

	vectRetour.resize(compteur);
	compteur = 0;
	for (size_t i{}; i < vectSize[0]; ++i) {
		vectRetour[compteur] = copieX & 1;
		copieX >>= 1;
		++compteur;
	}

	for (size_t i{ }; i < vectSize[1]; ++i) {
		vectRetour[compteur] = copieY & 1;
		copieY >>= 1;
		++compteur;
	}

	for (size_t i{}; i < vectSize[2]; ++i) {
		vectRetour[compteur] = copieWidth & 1;
		copieWidth >>= 1;
		++compteur;
	}

	for (size_t i{}; i < vectSize[3]; ++i) {
		vectRetour[compteur] = copieHeigth & 1;
		copieHeigth >>= 1;
		++compteur;
	}

	return std::vector<bool>();
}

void OrthoRectSolution::decode(std::vector<bool> vect, std::vector<size_t> vectSize)
{
	x = 0;
	y = 0;
	width = 0;
	heigth = 0;

	for (size_t i{}; i < vectSize[0]; ++i) {
		x += vect[i];
	}

	for (size_t i{ vectSize[0] }; i < vectSize[1]; ++i) {
		y += vect[i];
	}

	for (size_t i{ vectSize[1] }; i < vectSize[2]; ++i) {
		width += vect[i];
	}

	for (size_t i{ vectSize[2] }; i < vectSize[3]; ++i) {
		heigth += vect[i];
	}
}

Solution*  OrthoRectSolution::clone()
{
	return new OrthoRectSolution(*this);
}

void OrthoRectSolution::randomize()
{
	x = RandomUtil::randomInRange(0,refCanevas->width()  - 1);
	y = RandomUtil::randomInRange(0, refCanevas->height() - 1);
	width = RandomUtil::randomInRange(0, refCanevas->width() - x);
	heigth = RandomUtil::randomInRange(0, refCanevas->height() - y);

	mChromosome.writeData(encode(mChromosome.myGene()));
}

