#include "Canevas.h"

Canevas::Canevas(size_t width, size_t height, size_t ObstacleCount)
	:mWidth{ width }, mHeight{ height }, mVectOfObstacle( ObstacleCount )  
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
	if (mVectOfObstacle.size() > count) // increase size and randomize pos of new obstacle
	{
		mVectOfObstacle.resize(count);

		for (size_t i{ count }; i < mVectOfObstacle.size(); ++i)
		{
			mVectOfObstacle[i].randomizePosition(0, 0, mWidth, mHeight);
		}

	}
	else
	{
		mVectOfObstacle.resize(count); // cut size and delete obstacle not in the vector
	}
}

void Canevas::setup(SOParameters const SOParams)
{
	setSize(SOParams.width, SOParams.height);
	setObstacleCount(SOParams.obstacleCount);
}

void Canevas::randomizeObstaclesPosition()
{
	for (size_t i{}; i < mVectOfObstacle.size(); ++i)
	{
		mVectOfObstacle[i].randomizePosition(0, 0, mWidth, mHeight); 
	}
}

