#ifndef ORTHORECTSOLUTION_H
#define ORTHORECTSOLUTION_H
#include "ShapeSolution.h"
#include <math.h>
#include <vector>
#include "Console\ConsoleWriter.h"
#include "RandomUtil.h"
class OrthoRectSolution:public ShapeSolution
{
public:

	size_t x;
	size_t y;
	size_t width;
	size_t heigth;

	OrthoRectSolution(Canevas * ref);
	OrthoRectSolution() = delete;
	~OrthoRectSolution() override  = default;

	double area() const override;
	double perimeter() const override;
	double distance(Obstacle const & obs) const override;
	static double calculDistance(size_t x1, size_t y1, size_t x2, size_t y2);
	bool collide(Obstacle const & obs) const override;
	void draw(ConsoleWriter &curWriter) const override;

	std::vector <bool> encode(std::vector<size_t> vectSize) override;
	void decode(std::vector <bool> vect, std::vector<size_t> vectSize) override;
	Solution* clone() override;
	void randomize() override;
};

#endif // ORTHORECTSOLUTION_H