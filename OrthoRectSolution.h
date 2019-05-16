#ifndef ORTHORECTSOLUTION.H
#define ORTHORECTSOLUTION.H
#include "ShapeSolution.h"
#include <math.h>
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


};

#endif // ORTHORECTSOLUTION.H