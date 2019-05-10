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

	void setup();

	void run();
};

#endif // SHAPEOPTIMIZER.H