#ifndef ORTHORECTSOLUTION.H
#define ORTHORECTSOLUTION.H
#include "ShapeSolution.h"
#include <math.h>
#include <vector>
#include "Console\Console.h"
class OrthoRectSolution:public ShapeSolution
{
public:

	size_t x;
	size_t y;
	size_t width;
	size_t heigth;

	OrthoRectSolution();
	~OrthoRectSolution();

	double area() const;
	double perimeter() const;
	double distance(Obstacle const & obs) const;
	double calculDistance(size_t x1, size_t y1, size_t x2, size_t y2);
	bool collide(Obstacle const & obs) const;
	void draw() const;
	
	std::vector <bool> encode(std::vector<size_t> vectSize);
	void decode(std::vector <bool> vect, std::vector<size_t> vectSize);
	Solution* clone();
	void randomize();
};

#endif // ORTHORECTSOLUTION.H