#include "OrthoRectSolution.h"

OrthoRectSolution::OrthoRectSolution()
{
}

OrthoRectSolution::~OrthoRectSolution()
{
}

double OrthoRectSolution::area() { return width*heigth; }

double OrthoRectSolution::perimeter() { return 2*width+2*heigth; }

std::vector<bool> OrthoRectSolution::encode(std::vector<size_t> vectSize)
{
	std::vector<bool> vectRetour;
	size_t copieX{x};
	size_t copieY{y};
	size_t copieWidth{width};
	size_t copieHeigth{heigth};

	for (size_t i{}; i < vectSize[0]; ++i) {
		vectRetour.push_back(copieX & 1);
		copieX >>= 1;
	}

	for (size_t i{ vectSize[0] }; i < vectSize[1]; ++i) {
		vectRetour.push_back(copieY & 1);
		copieY >>= 1;
	}

	for (size_t i{ vectSize[1] }; i < vectSize[2]; ++i) {
		vectRetour.push_back(copieWidth & 1);
		copieWidth >>= 1;
	}

	for (size_t i{ vectSize[2] }; i < vectSize[3]; ++i) {
		vectRetour.push_back(copieHeigth & 1);
		copieHeigth >>= 1;
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

