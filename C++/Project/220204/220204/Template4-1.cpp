#include<iostream>
using namespace std;

template<typename T, int size>
void PrintArray(T* arr)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "[" << i << "] : " << arr[i] << endl;
	}
	cout << endl;
}

void Print(int a, int b)
{
	cout << a << ", " << b <<endl;
}

int main()
{
	Print(10, 20);
	auto print = [](int a, int b) { cout << a << ", " << b << endl; return a+1; };

	cout << endl;
	cout << print(10, 20) << endl;

	cout << endl;


	int arr1[5] = { 10, 20, 30, 40, 50 };
	PrintArray<int, 5>(arr1);				//명시적 호출

	double arr2[3] = { 1.1, 2.2, 3.3 };
	PrintArray<double, 3>(arr2);			//명시적 호출

	return 0;
}