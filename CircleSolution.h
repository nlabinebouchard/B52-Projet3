#ifndef CIRCLESOLUTION_H
#define CIRCLESOLUTION_H
#include "ShapeSolution.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Console\ConsoleWriter.h"
#include "RandomUtil.h"
class CircleSolution: public ShapeSolution
{
public:

	size_t x;
	size_t y;
	size_t r;

	CircleSolution(Canevas * ref);
	CircleSolution() = delete;
	~CircleSolution() override = default;

	double area() const override;
	double perimeter() const override;
	double distance(Obstacle const & obs) const override;
	bool collide(Obstacle const & obs) const override;
	void draw(ConsoleWriter &curWriter) const override;

	std::vector <bool> encode(std::vector<size_t> vectSize) override;
	void decode(std::vector <bool> vect, std::vector<size_t> vectSize) override;
	Solution* clone() override;
	void randomize() override;
};

#endif // CIRCLESOLUTION_H