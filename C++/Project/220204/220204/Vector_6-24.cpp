#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;
	vector<int>::iterator iter2;

	for (vector<int>::iterator kIter = v.begin(); kIter != v.end(); ++kIter)
		cout << "( " << *kIter << " / " << &(*kIter) << " ) ";
	cout << endl;

	cout << "=================" << endl;

	iter2 = v.erase(iter);
	for (vector<int>::iterator kIter = v.begin(); kIter != v.end(); ++kIter)
		cout << "( " << *kIter << " / " << &(*kIter) << " ) ";
	cout << endl;

	cout << "=================" << endl;
	
	iter2 = v.erase(v.begin() + 1, v.end());
	for (vector<int>::iterator kIter = v.begin(); kIter != v.end(); ++kIter)
		cout << "( " << *kIter << " / " << &(*kIter) << " ) ";
	cout << endl;

	cout << "=================" << endl;

	return 0;
}