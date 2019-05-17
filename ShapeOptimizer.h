#ifndef SHAPEOPTIMIZER_H
#define SHAPEOPTIMIZER_H

#include "SOParameters.h"
//#include "GAParameters.h"


class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	//void setup(SOParameters const &SOParams, GAParameters const& GAParams);

	void setupTemp(SOParameters const &SOParams);

	void run();
};

#endif // SHAPEOPTIMIZER_H