#include <iostream>
using namespace std;

struct LessFunctor
{
	bool operator() (int left, int right) const	// 1. �Լ� ��ü ������
	{
		return left < right;
	}
};

bool LessFun(int left, int right)			// 2. �Լ� ������
{
	return left < right;
}

int main()
{
	LessFunctor lessFunctor;				// 1. �Լ� ��ü ������
	cout << lessFunctor(10, 20) << endl;	

	cout << LessFun(10, 20) << endl;		// 2. �Լ� ������

	bool (*LessPtr) (int, int) = LessFun;	// 3. �Լ� ������ ������
	cout << LessPtr(10, 20) << endl;
}