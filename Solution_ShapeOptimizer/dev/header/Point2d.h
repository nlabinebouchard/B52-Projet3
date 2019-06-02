#ifndef _POINT_H_
#define _POINT_H_

// A simple point class.

class Point2d final
{
public:
	Point2d(double x = 0.0, double y = 0.0);

	double x() const;
	double y() const;
	void setX(double x);
	void setY(double y);
	void set(double x, double y);
	void randomize(double minX, double maxX, double minY, double maxY);
	void randomize(double minVal = 0.0, double maxVal = 1.0);

	bool isAtTheOrigin() const;

	double distance2() const;
	double distance() const;
	double distance2(Point2d const & p) const;
	double distance(Point2d const & p) const;

	Point2d operator-() const;
	Point2d operator+(Point2d const & p) const;
	Point2d operator-(Point2d const & p) const;
	Point2d operator*(double v) const;
	Point2d operator/(double v) const;
	friend Point2d operator*(double v, Point2d const & p);
	friend Point2d operator/(double v, Point2d const & p);

	bool operator==(Point2d const & p);
	bool operator!=(Point2d const & p);

private:
	double mX, mY;
};

#endif // _POINT_H_