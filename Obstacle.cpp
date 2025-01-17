#include "Obstacle.h"
#include "RandomUtil.h"

Obstacle::Obstacle(size_t const minX, size_t const minY, size_t const maxX, size_t const  maxY)
	:mX{ RandomUtil::randomInRange(minX, maxX) }, mY{ RandomUtil::randomInRange(minY, maxY) }
{
}

void Obstacle::randomizePosition(size_t minX, size_t minY, size_t maxX, size_t maxY)
{
	mX = RandomUtil::randomInRange(minX, maxX);
	mY = RandomUtil::randomInRange(minY, maxY);
}


int Obstacle::posX() const
{
	return static_cast<int>(mX);
}

int Obstacle::posY() const
{
	return static_cast<int>(mY);
}
