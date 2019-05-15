#include "Obstacle.h"

Obstacle::Obstacle(size_t const minX, size_t const minY, size_t const maxX, size_t const  maxY)
	:mMinX{ minX }, mMinY{ minY }, mMaxX{ maxX }, mMaxY{ maxY }
{

}

Obstacle::~Obstacle()
{
	mMinX = mMinY = mMaxX = mMaxY = 0;
}

void Obstacle::randomizePosition(size_t minX, size_t minY, size_t maxX, size_t maxY)
{
	mMinX = minX;
	mMinY = minY;
	mMaxX = maxX;
	mMaxY = maxY;

}
