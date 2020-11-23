#include <iostream>
#include <memory>

using cir = const int&;

struct Point
{
	long long x, y; // x, y의 계산값이 long long이 되려면, long long var 으로 받기만 해서는 안되고 x, y 도 long long이어야 한다.
	// 자료형은 값 계산 결과의 한계에도 영향을 미친다.
};

class Problem
{
private:
	int N;
	std::unique_ptr<Point[]> p = nullptr;
public:
	void facade()
	{
		init();
		sol();
	}
	void init()
	{
		auto makePoint = [this](cir N)
		{
			p = std::make_unique<Point[]>(N + 1);
			for (int i = 0, x, y; i < N; i++)
			{
				std::cin >> x >> y;
				p[i] = Point({ x, y });
			}
			p[N] = Point({ p[0].x, p[0].y });
		};

		std::cin >> N;
		makePoint(N);
	}
	void sol()
	{
		long long res = CCW(N);
		std::cout << res / 2 << '.';
		if (res % 2 == 0) std::cout << '0';
		else std::cout << '5';
		std::cout << std::endl;
	}
	long long CCW(cir N)
	{ // 다각형 CCW 구하는 방법을 틀렸었다.
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += p[i].x * p[i + 1].y;
			sum -= p[i].y * p[i + 1].x;
		}
		if (sum < 0) return -sum;
		else return sum;
	}
};

int main()
{
	//Problem().facade();

	int v1 = 100000;
	int v2 = 100000;
	long long a = v1 * v2;
	std::cout << typeid(a).name() << " : " << a << std::endl;

	std::cout << 100000ll * 100000ll << std::endl;

	long long v3 = 100000, v4 = 100000;
	long long a2 = v3 * v4;
	std::cout << typeid(a2).name() << " : " << a2 << std::endl;

	return 0;
}