#ifndef ORTHORECTSOLUTION.H
#define ORTHORECTSOLUTION.H
#include "ShapeSolution.h"
#include <math.h>
#include <vector>
class OrthoRectSolution

{
public:

	size_t x;
	size_t y;
	size_t width;
	size_t heigth;

	OrthoRectSolution();
	~OrthoRectSolution();

	double area();
	double perimeter();
	double distance(Obstacle const & obs);
	bool collide(Obstacle const & obs);
	void draw();
	
	std::vector <bool> encode(std::vector<size_t> vectSize);
	void decode(std::vector <bool> vect, std::vector<size_t> vectSize);

};

#endif // ORTHORECTSOLUTION.H