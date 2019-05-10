#ifndef OBSTACLE.H
#define OBSTACLE.H


class Obstacle
{
public:

	Obstacle(size_t const minX,size_t const minY, size_t const  maxX, size_t const  maxY) ;
	~Obstacle() = default;

	void randomizePosition(size_t minX, size_t minY, size_t maxX, size_t maxY);

private:
	size_t mMinX;
	size_t mMinY;
	size_t mMaxX;
	size_t mMaxY;

};

#endif // OBSTACLE.H