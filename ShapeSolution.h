#ifndef SHAPESOLUTION_H
#define SHAPESOLUTION_H
#include "Solution.h"
#include "Obstacle.h"
#include "Console\ConsoleWriter.h"

class ShapeSolution:public Solution
{
public:

	ShapeSolution() = delete;
	ShapeSolution(Canevas * ref);
	~ShapeSolution() = default;

	void processFitness();

	virtual void draw(ConsoleWriter &curWriter) const=0;
	virtual bool collide(Obstacle const & obs) const=0;
	virtual double distance(Obstacle const & obs) const=0;
	virtual double area() const=0;
	virtual double perimeter() const = 0;

	Canevas * refCanevas;
private:

};

#endif // SHAPESOLUTION_H