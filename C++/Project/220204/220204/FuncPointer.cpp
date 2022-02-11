#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
	void SetPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int main()
{
	Point pt(2, 3);
	Point* p = &pt;
	
	void (Point:: * pf1) () const = &Point::Print;

	void (Point:: * pf2) (int);
	pf2 = &Point::PrintInt;

	pt.SetPoint(3, 4);
	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	pt.SetPoint(4, 5);
	(pt.*pf1) ();
	(pt.*pf2) (10);
	cout << endl;

	pt.SetPoint(5, 6);
	(p->*pf1)();
	(p->*pf2)(10);

	return 0;
}