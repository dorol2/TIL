# 상속과 다형성

## 객체 포인터의 참조 관계

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Sleep()
	{
		cout << "Sleep Student" << endl;
	}
	void Study()
	{
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student
{
public:
	void Sleep()
	{
		cout << "Sleep PartTime" << endl;
	}
	void Study()
	{
		cout << "Study PartTime" << endl;
	}
	void Work()
	{
		cout << "Work" << endl;
	}
};

int main()
{
	Person * ptr1 = new Student();
	Person * ptr2 = new PartTimeStudent();
	Student	* ptr3 = new PartTimeStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	cout << typeid(ptr1).name() << endl;
	cout << typeid(ptr2).name() << endl;
	cout << typeid(ptr3).name() << endl;

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}
```
출력결과
```
Sleep
Sleep
Study
class Person *  //ptr1
class Person *  //ptr2
class Student * //ptr3
```

# Virtual Function (가상함수)
- 동적 바인딩 : 런타임에 호출될 함수가 결정되는 것. 해당 객체에 맞는 멤버 함수를 그때 그때의 상황에 따라 호출한다. 
- 가상 함수 : virtual 키워드를 통해 동적 바인딩 하는 함수 

## 추상클래스
- 기초 클래스로서만 의미를 가질 뿐, 객체의 생성을 목적으로 정의된 클래스는 아니다. 
- virtual 메서드가 1개라도 있으면 추상 클래스
- 순수 가상 함수 : 함수의 몸체가 정의되지 않은 함수



# 연산자 오버로딩




