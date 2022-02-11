#include<iostream>
#include<functional>
using namespace std;

template<typename T>
struct Less
{
	bool operator() (T a, T b)
	{
		return a < b;
	}
};

template<typename T>
class LessClass
{
public:
	bool operator() (T a, T b)
	{
		return a < b;
	}
};

template<typename T>
struct Greater
{
	bool operator() (T a, T b)
	{
		return a > b;
	}
};

template<typename T>
class GreaterClass
{
public:
	bool operator() (T a, T b)
	{
		return a > b;
	}
};

int main()
{
	cout << Less<int>() (10, 20) << endl;
	cout << Less<int>() (20, 10) << endl;
	cout << Greater<int>() (10, 20) << endl;
	cout << Greater<int>() (20, 10) << endl;

	cout << endl;

	cout << less<int>() (10, 20) << endl;
	cout << less<int>() (20, 10) << endl;
	cout << greater<int>() (10, 20) << endl;
	cout << greater<int>() (20, 10) << endl;

	cout << endl;

	cout << LessClass<int>() (10, 20) << endl;
	cout << LessClass<int>()(20, 10) << endl;
	cout << GreaterClass<int>() (10, 20) << endl;
	cout << GreaterClass<int>() (20, 10) << endl;

}