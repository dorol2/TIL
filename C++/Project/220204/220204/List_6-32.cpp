#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int> li;
	vector<int> v;

	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.push_back(40);
	li.push_back(50);

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator viter = v.begin();
	++viter;
	list<int>::iterator liter = li.begin();
	++liter;

	viter = v.insert(viter, 600);
	liter = li.insert(liter, 600);

	cout << "vector : " << *viter << endl;
	cout << "list : " << *liter << endl;

	cout << "vector : ";
	for (viter = v.begin(); viter != v.end(); ++viter)
		cout << *viter << " / " << &(*viter) << "    ";
	cout << endl << endl;

	cout << "list : ";
	for (liter = li.begin(); liter != li.end(); ++liter)
		cout << *liter << " / " << &(*liter) << "   ";
	cout << endl;

	/*list<int>::iterator iter;
	for (iter = li.begin(); iter != li.end(); ++iter)
		cout << *iter << " / " << &(*iter) << "   ";
	cout << endl;

	li.push_front(100);
	li.push_front(200);

	for (iter = li.begin(); iter != li.end(); ++iter)
		cout << *iter << " / " << &(*iter) << "   ";
	cout << endl;*/

	return 0;
}