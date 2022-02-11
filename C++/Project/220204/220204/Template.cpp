
#include <iostream>
#include <string>
using namespace std;

int const Add(int const& a, int const& b)
{
	return a + b;
}

template <typename T>
T const AddTamplate(T const& a, T const& b)
{
	return a + b;
}

template <class T, class U>
U const AddTamplate(T const& a, U const& b)
{
	return a + b;
}

template <>
char* const AddTamplate<char*>(char* const& a, char* const& b)
{
	cout << "char*" << endl;
	return (char*) strcat_s(a, 5, b);
}

template <>
int* const AddTamplate(char* const& a, int* const& b)
{
	return strlen(a) + b;
}


int main()
{
	double i = 5.6;
	double j = 6.7;
	int k = 5;

	char m[20] = "hello";
	char n[10] = "world";

	cout << AddTamplate(i, j) << endl;
	cout << AddTamplate<int>(4, 4) << endl;
	cout << AddTamplate<int, double>(k, i) << endl;
	cout << AddTamplate<char*>(m, n) << endl;


	return 0;
}


