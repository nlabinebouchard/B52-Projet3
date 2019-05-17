#ifndef SHAPESOLUTION.H
#define SHAPESOLUTION.H
#include "Solution.h"
#include "Obstacle.h"

class ShapeSolution:public Solution
{
public:
	ShapeSolution();
	~ShapeSolution();
	void processFitness();
	virtual void draw()=0;
	virtual bool collide(Obstacle const & obs)=0;
	virtual double distance(Obstacle const & obs)=0;
	virtual double area()=0;
	virtual double perimeter()=0;

private:

};

#endif // SHAPESOLUTION.H