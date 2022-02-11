#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	v[0] = 100;
	v[4] = 500;

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	v.at(0) = 1000;
	v.at(4) = 5000;

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	try 
	{
		v.at(8) = 100;	// 잡음 -> error throw
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}

	//try
	//{
	//	v[8] = 100;	//못잡-> 터짐
	//}
	//catch (out_of_range& e)
	//{
	//	cout << e.what() << endl;
	//}

	cout << "=================" << endl;

	vector<int> v2(5, 8);
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	v2.assign(3, 2);
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	try
	{
		v2.at(3) = 100;	// 잡음 -> error throw
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}