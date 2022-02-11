#include<iostream>
using namespace std;
//
//void InputName(char* name)
//{
//	cout << "�̸� �Է� : " << endl;
//	cin >> name;
//
//	if (strlen(name) <= 2)
//		throw name;
//}
//
//int InputAge()
//{
//	int age;
//	cout << "���� �Է� : " << endl;
//	cin >> age;
//
//	if (age < 1)
//		throw age;
//	
//	return age;
//}
//
//
//int main()
//{
//	char name[512];
//	int age;
//	try
//	{
//		InputName(name);
//		age = InputAge();
//
//		cout << name << " / " << age << endl;
//	}
//	catch (char* e)
//	{
//		cout << "���ܹ߻� �߸��� �̸� �Է� " << e << endl;
//	}
//	catch (int e)
//	{
//		cout << "���ܹ߻� �߸��� ���� �Է� " << e << endl;
//	}
//
//	return 0;
//}



void handler() noexcept
{
	cout << "in handler" << endl;
}

void handler2() noexcept
{
	cout << "in handler" << endl;
	exit(-1);
}

void f1(void) noexcept(false)
{
	cout << "About to throw 1" << endl;
	if (1)
		throw 1;
}

void f2(void) noexcept(false)
{
	try
	{
		f1();
	}
	catch(int e)
	{
		handler();
		throw "asdf";
	}
}

int main()
{
	//f1();
	set_terminate(handler2);
	try
	{
		f2();
	}
	catch (int e)
	{
		cout << "Caught exception from f2" << endl;
	}

	return 0;
}