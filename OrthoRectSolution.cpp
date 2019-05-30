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
	mChromosome.writeData(encode());
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

std::vector<bool> OrthoRectSolution::encode()
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
		vectRetour[compteur] = width & exposant;
		++compteur;
	}

	for (size_t i{ mChromosome.myGene()[3] }; i > 0; --i) {
		size_t exposant{ static_cast<size_t>(pow(2, i)) };
		vectRetour[compteur] = heigth & exposant;
		++compteur;
	}

	return vectRetour;
}

void OrthoRectSolution::decode()
{
	x = 0;
	y = 0;
	width = 0;
	heigth = 0;
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
		width <<= 1;
		width += mChromosome.myData()[compteur];
		++compteur;
	}

	for (size_t i{}; i < mChromosome.myGene()[3]; ++i) {
		heigth <<= 1;
		heigth += mChromosome.myData()[compteur];
		++compteur;
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

	mChromosome.writeData(encode());
}

bool OrthoRectSolution::outOfCanvas() const
{
	return false; // TODO
}

