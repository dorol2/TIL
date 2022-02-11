#include<iostream>
using namespace std;

struct FuncObject
{
public:
	void operator() (int arg) const
	{
		cout << "정수 : " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "정수 : " << arg << endl;
}

int main()
{
	void (*Print2) (int) = Print1;
	FuncObject Print3;

	Print1(10);
	Print2(10);
	Print3(10);

	return 0;
}