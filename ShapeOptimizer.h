#ifndef SHAPEOPTIMIZER.H
#define SHAPEOPTIMIZER.H

#include "SOParameters.h"
#include "GAParameters.h"


class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	void setup(SOParameters const &SOParams, GAParameters const& GAParams);

	void run();
};

#endif // SHAPEOPTIMIZER.H