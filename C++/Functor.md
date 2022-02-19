# Functor (함수 객체)
함수처럼 동작하는 객체

1. 장점 </br>
- 함수처럼 동작하는 객체이므로 다른 멤버 변수와 멤버 함수를 가질 수  있다. 
- 일반 함수보다 빠르다.


```cpp
#include <iostream>
using namespace std;

class Adder
{
	int total;

public: 
	explicit Adder(int n = 0) : total(n)
	{ }
	int operator() (int n)
	{
		return total += n;
	}
};

int main()
{
	Adder add(0);

	cout << add(10) << endl;    // 10
	cout << add(20) << endl;    // 30  
	cout << add(30) << endl;    // 60

	return 0;
}
```






















