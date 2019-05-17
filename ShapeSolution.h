#ifndef SHAPESOLUTION_H
#define SHAPESOLUTION_H
#include "Solution.h"
#include "Obstacle.h"

class ShapeSolution:public Solution
{
public:
	ShapeSolution();
	~ShapeSolution();
	virtual void draw();
	virtual bool collide(Obstacle const & obs);
	virtual double distance(Obstacle const & obs);
	virtual double area();
	virtual double perimeter();

private:

};

#endif // SHAPESOLUTION_H