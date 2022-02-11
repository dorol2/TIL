#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	stack<int> st;

	st.push(10);
	st.push(20);
	st.push(30);

	cout << st.top() << endl;
	st.pop();

	cout << st.top() << endl;
	st.pop();

	cout << st.top() << endl;
	st.pop();

	if (st.empty())
		cout << "stack에 데이터 없음" << endl;

	cout << "----------------------------------------" << endl;

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << v.back() << endl;
	v.pop_back();

	cout << v.back() << endl;
	v.pop_back();

	cout << v.back() << endl;
	v.pop_back();

	if (v.empty())
		cout << "stack에 데이터 없음" << endl;

	cout << "----------------------------------------" << endl;

	vector<int> v2;

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	reverse_iterator<vector<int>::iterator> reverseIterator(v2.end());
	reverse_iterator<vector<int>::iterator> reverseIteratorEnd(v2.begin());

	for (; reverseIterator != reverseIteratorEnd; ++reverseIterator)
		cout << *reverseIterator << " ";
	cout << endl;

	vector<int>::iterator iter = v2.begin() + 3;
	reverse_iterator<vector<int>::iterator> reverseIter(iter);

	cout << 

	return 0;
}