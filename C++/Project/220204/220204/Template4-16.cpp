#include<iostream>
using namespace std;

void For_each(int* begin, int* end, void (*pf) (int))
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

template <typename T, typename U>
void For_each_template(T begin, T end, U func)
{
	while (begin != end)
	{
		func(*begin++);
	}
}

void PrintInt(int n)
{
	cout << n << " ";
}

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	//For_each(arr, arr + 5, PrintInt);
	For_each_template(arr, arr + 5, PrintInt);
	cout << endl;
	
	return 0;
}













