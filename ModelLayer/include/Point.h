#if !defined(POINT_H)
#define POINT_H

#define POINTXMAX 8499
#define POINTYMAX 10999
#define POINTXMIN 0
#define POINTYMIN 0

class Point {
private:
	int X;
	int Y;
public:
	Point();
	//Pre: 0 <= X < 8500
	int getX();
	//Pre: 0 <= Y < 11000
	int getY();
	//Post: 0 <= X < 8500
	void setX(int);
	//Post: 0 <= Y < 11000
	void setY(int);
	~Point();

	//get min_x and max_x functions added by group 6
	//int Point::get_min_x();
	//int Point::get_min_y();
	//int Point::get_max_x();
	//int Point::get_max_y();
};
#endif