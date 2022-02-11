#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int a, int b)
{
	return b % a == 0;
}

int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(40);
	v1.push_back(50);
	
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)	// 10 20 30 30 40 40 50
		cout << v1[i] << " ";	
	cout << endl;

	vector<int>::iterator iter1 = adjacent_find(v1.begin(), v1.end());
	if (iter1 != v1.end())
		cout << (*iter1) << endl;				// 30

	for (iter1; iter1 != v1.end(); ++iter1)		// 30 30 40 40 50
		cout << (*iter1) << " ";
	cout << endl;

	vector<int>::iterator startIter = v1.begin();
	vector<int>::iterator endIter = v1.begin() + 3;

	//vector<int>::iterator iter2 = adjacent_find(v1.begin(), v1.end(), Pred);
	vector<int>::iterator iter2 = adjacent_find(v1.begin(), v1.end(), [](int a, int b)->bool { return b % a == 0; });
	if (iter2 != endIter)
		cout << (*iter2) << endl;				// 0

	cout << count(v1.begin(), v1.end(), 20) << endl;
	cout << count_if(v1.begin(), v1.end(), [](int a)->bool {return a > 25; }) << endl;
}