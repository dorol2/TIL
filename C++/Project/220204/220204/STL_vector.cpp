#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	cout << endl;

	vector<int>::iterator iter;
	for (iter = v.begin(); iter < v.end(); ++iter)
		cout << *iter << endl;

	cout << endl;

	vector<int>::iterator iter2;
	iter2 = find(v.begin(), v.end(), 20);
	cout << *iter2 << endl;

	iter2 = find(v.begin(), v.end(), 100);
	if (iter2 == v.end())
		cout << "100ÀÌ ¾øÀ½" << endl;

	return 0;
}