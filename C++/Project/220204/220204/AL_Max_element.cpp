#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
	int x;
	int y;

public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	int GetX() const { return x; }
	int GetY() const { return y; }
	void Print() const { cout << "(" << x << " / " << y << ")" << endl; }
};

bool Compare(const Point& left, const Point& right)
{
	if (left.GetX() < right.GetX())
		return true;
	else if (left.GetX() > right.GetX())
		return false;
	else
		return left.GetY() < right.GetY();
}

int main()
{
	vector<Point> v;
	v.push_back(Point(3, 2));
	v.push_back(Point(2, 5));
	v.push_back(Point(1, 5));
	v.push_back(Point(3, 3));
	v.push_back(Point(3, 2));

	vector<Point>::iterator iter = max_element(v.begin(), v.end(), Compare);

	cout << "Max : ";
	(*iter).Print();	//iter->Print()
	cout << endl;


	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(40);
	v2.push_back(40);
	v2.push_back(40);

	pair<vector<int>::iterator, vector<int>::iterator> mismatchPair;
	mismatchPair = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << (*mismatchPair.first) << " / " << (*mismatchPair.second) << endl;

	return 0;
}