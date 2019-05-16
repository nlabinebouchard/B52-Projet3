#include "Canevas.h"

Canevas::Canevas(size_t width, size_t height, size_t ObstacleCount)
	:mWidth{ width }, mHeight{ height }, mVectOfObstacle( ObstacleCount )  
{
}

Canevas::~Canevas()
{
}

size_t Canevas::width() const
{
	return mWidth;
}

size_t Canevas::height() const
{
	return mHeight;
}

std::vector<Obstacle> const& Canevas::obstacles() const
{
	return mVectOfObstacle;
}

void Canevas::setSize(size_t const& width, size_t const& height)
{
	mWidth = width;
	mHeight = height;
}

void Canevas::setObstacleCount(size_t const& count)
{
	mVectOfObstacle.resize(count);
}

void Canevas::setup(SOParameters const SOParams)
{
	setSize(SOParams.width, SOParams.height);
}

void Canevas::randomizeObstaclesPosition()
{
	for (size_t i{}; i < mVectOfObstacle.size(); ++i)
	{
		mVectOfObstacle[i].randomizePosition(1, 1, 1, 1); // need to randomise values
	}
}

