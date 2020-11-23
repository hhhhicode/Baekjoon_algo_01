#include <iostream>

struct Point
{
	int x, y;
};

class Problem
{
private:
	Point p[3];
public:
	void facade()
	{
		init();
		sol();
	}
	void init()
	{
		for (int i = 0, x, y; i < 3; i++)
		{
			std::cin >> x >> y;
			p[i] = Point({ x, y });
		}
	}
	void sol()
	{
		std::cout << CCW(p[0], p[1], p[2]);
	}
	int CCW(Point p1, Point p2, Point p3)
	{
		int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y
			- p2.x * p1.y - p3.x * p2.y - p1.x * p3.y;
		if (res < 0) return -1;
		if (res == 0) return 0;
		if (res > 0) return 1;
	}
};

int main()
{
	Problem().facade();

	return 0;
}