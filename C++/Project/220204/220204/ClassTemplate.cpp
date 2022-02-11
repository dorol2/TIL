#include<iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
		
};

int main()
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(3.5, 4.5);
	pos2.ShowPosition();

	Point<char> pos3('p', 'f');
	pos3.ShowPosition();
}







