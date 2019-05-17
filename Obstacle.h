#ifndef OBSTACLE_H
#define OBSTACLE_H


class Obstacle
{
public:

	Obstacle() = default;
	Obstacle(size_t const minX,size_t const minY, size_t const  maxX, size_t const  maxY) ;
	~Obstacle() = default;

	void randomizePosition(size_t minX, size_t minY, size_t maxX, size_t maxY);

	int posX() const;

	int posY() const;


private:
	size_t mX;
	size_t mY;

};

#endif // OBSTACLE_H