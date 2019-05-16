#ifndef SHAPESOLUTION.H
#define SHAPESOLUTION.H
#include "Solution.h"
#include "Obstacle.h"

class ShapeSolution:Solution
{
public:
	ShapeSolution();
	~ShapeSolution();
	virtual void draw();

private:
	virtual bool collide(Obstacle const & obs);
	virtual double distance(Obstacle const & obs);
	virtual double area();
	virtual double perimeter();
};

#endif // SHAPESOLUTION.H