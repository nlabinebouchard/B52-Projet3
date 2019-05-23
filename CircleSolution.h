#ifndef CIRCLESOLUTION_H
#define CIRCLESOLUTION_H
#include "ShapeSolution.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Console\Console.h"
#include "Canevas.h"
#include "RandomUtil.h"
class CircleSolution: public ShapeSolution
{
public:

	size_t x;
	size_t y;
	size_t r;

	CircleSolution() = default;
	~CircleSolution() = default;
	//A refaire comme rect
	double area();
	double perimeter();
	double distance(Obstacle const & obs);
	bool collide(Obstacle const & obs);
	void draw();

	std::vector <bool> encode(std::vector<size_t> vectSize);
	void decode(std::vector <bool> vect, std::vector<size_t> vectSize);
	Solution* clone();
	void randomize(Canevas & const canvas);
};

#endif // CIRCLESOLUTION_H