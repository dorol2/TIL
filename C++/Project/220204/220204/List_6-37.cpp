#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(100);
	lt2.push_back(200);
	lt2.push_back(300);
	lt2.push_back(400);
	lt2.push_back(500);

	list<int>::iterator iter;
	cout << "lt1 : ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2 : ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "============" << endl;

	iter = lt1.begin();
	advance(iter, 2);
	//++iter;
	//++iter;

	list<int>::iterator test = lt2.begin();
	advance(test, 3);

	lt1.splice(iter, lt2, test, lt2.end());

	cout << "lt1 : ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2 : ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	
	return 0;
}