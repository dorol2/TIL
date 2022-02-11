#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)	// 10 30 40 50 70 80 90
		cout << *iter << " ";
	cout << endl;

	/*pair*/
	pair<set<int>::iterator, bool> setPair;
	setPair = s.insert(50);

	cout << *setPair.first << " / " << setPair.second << endl; // 50 / 0

	/*find*/
	set<int>::iterator findIterator = s.find(30);
	if (findIterator != s.end())
		cout << *findIterator << endl;	// 30
	else
		cout << "없음" << endl;

	/*count*/
	cout << s.count(40) << endl; // 1  => set은 원소의 중복을 허용하지 않으므로 있으면 1 없으면 0

	/*lower_bound, upper_bound*/
	set<int>::iterator lowerIterator = s.lower_bound(30);		// 인자가 시작하는 구간의 iterator
	set<int>::iterator upperIterator = s.upper_bound(30);		// 인자가 끝나는 구간의 iterator

	cout << *lowerIterator << " / " << *upperIterator << endl;	// 30 / 40

	/*equal_range*/
	pair<set<int>::iterator, set<int>::iterator> equalPair = s.equal_range(30);

	cout << *equalPair.first << " / " << *equalPair.second << endl;	// 30 / 40 => first = lower_bound, second = upper_bound

	return 0;
}