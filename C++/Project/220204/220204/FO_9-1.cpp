#include <iostream>
using namespace std;

struct LessFunctor
{
	bool operator() (int left, int right) const	// 1. 함수 객체 조건자
	{
		return left < right;
	}
};

bool LessFun(int left, int right)			// 2. 함수 조건자
{
	return left < right;
}

int main()
{
	LessFunctor lessFunctor;				// 1. 함수 객체 조건자
	cout << lessFunctor(10, 20) << endl;	

	cout << LessFun(10, 20) << endl;		// 2. 함수 조건자

	bool (*LessPtr) (int, int) = LessFun;	// 3. 함수 포인터 조건자
	cout << LessPtr(10, 20) << endl;
}