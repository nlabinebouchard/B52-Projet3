#ifndef SHAPEOPTIMIZER.H
#define SHAPEOPTIMIZER.H


class ShapeOptimizer
{
public:
	ShapeOptimizer() = delete;
	~ShapeOptimizer() = delete;

	struct SOParameters
	{

		size_t width;
		size_t height;
		size_t obstacleCount;

	};

	void setup(ShapeOptimizer::SOParameters const &soParams, GAParameters::StructName const& gaParams);

	void run();
};

#endif // SHAPEOPTIMIZER.H