#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(rand() % 1000);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end());

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(35);
	push_heap(v.begin(), v.end());

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}








