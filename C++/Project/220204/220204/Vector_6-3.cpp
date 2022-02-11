#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;
	v.push_back(20);
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;
	v.push_back(30);
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;
	v.push_back(40);
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;
	v.push_back(50);
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;
	//cout << v.capacity() << endl;
	cout << v.max_size() << endl;

	return 0;
}