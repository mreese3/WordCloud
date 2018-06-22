#if !defined(SIZE_H)
#define SIZE_H

class Size {
private:
	int Height;
	int Width;
public:
	Size();
	//Pre: 0 <= Height < 11000
	int getHeight();
	//Pre: 0 <= Width < 8500
	int getWidth();
	//Post: 0 <= Hight < 11000
	void setHeight(int);
	//Post: 0 <= Width < 8500
	void setWidth(int);
	~Size();
};

#endif