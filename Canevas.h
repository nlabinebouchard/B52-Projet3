#ifndef CANEVAS.H
#define CANEVAS.H

#include "ShapeOptimizer.h"
#include "Obstacle.h"
#include <vector>

class Canevas
{
public:
	Canevas() = delete;
	Canevas(size_t width, size_t height, size_t ObstacleCount);
	~Canevas() = default;

	size_t width() const; 
	size_t height() const; 

	std::vector<Obstacle> const& obstacles() const; // return list d'obstacles

	void setSize(size_t const  &width, size_t const &height);

	void setObstacleCount(size_t const& count);

	void setup(SOParameters const SOParams);

	void randomizeObstaclesPosition();



private:
	size_t mWidth;
	size_t mHeight;
	std::vector<Obstacle> mVectOfObstacle;
	};

#endif // CANEVAS.H