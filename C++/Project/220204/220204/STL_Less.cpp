#include<iostream>
#include<functional>
using namespace std;

typedef less<int> Less;

int main()
{
	Less l;

	cout << l(10, 20) << endl;				// l ��ü�� �Ͻ��� �Լ� ȣ��
	cout << l(20, 10) << endl;				// l ��ü�� �Ͻ��� �Լ� ȣ��
	cout << l.operator() (10, 20) << endl;	// l ��ü�� ����� �Լ� ȣ��

	cout << endl;

	cout << Less() (10, 20) << endl;			// �ӽð�ü�� �Ͻ��� �Լ� ȣ��
	cout << Less() (20, 10) << endl;			// �ӽð�ü�� �Ͻ��� �Լ� ȣ��
	cout << Less().operator() (10, 20) << endl;	// �ӽð�ü�� ����� �Լ� ȣ��

	
	auto print = [](int a, int b) { cout << a << ',' << b << endl; };

	print(10, 20);
}
