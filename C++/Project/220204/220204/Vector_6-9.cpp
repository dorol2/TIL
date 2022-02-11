#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(5);
	
	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;
	
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	//v.clear();
	cout << "size : " << v.size() << " / capacity : " << v.capacity() << endl;

	if (v.empty())
		cout << "v에 원소가 없습니다. " << endl;
	
	cout << "=================" << endl;

	vector<int> v2(8);
	cout << "size : " << v2.size() << " / capacity : " << v2.capacity() << endl;

	//vector<int>().swap(v2);
	cout << "size : " << v2.size() << " / capacity : " << v2.capacity() << endl;

	cout << "&v : " << &v << endl;		//이 주소는 swap해도 같은데, 내부 원소는 주소가 바뀐다. -> 객체의 주소라서?
	cout << "&v2 : " << &v2 << endl;

	cout << "&v[0] : " << &v[0] << endl;	// vector 내부 배열의 객체의 주소
	cout << "&v2[0] : " << &v2[0] << endl;

	cout << "&v.begin() : " << &(*v.begin()) << endl;	// vector 내부 배열의 객체의 주소
	cout << "&v2.begin() : " << &(*v2.begin()) << endl;

	v.swap(v2);
	cout << "size : " << v2.size() << " / capacity : " << v2.capacity() << endl;

	cout << "&v : " << &v << endl;		//이 주소는 swap해도 같은데, 내부 원소는 주소가 바뀐다.
	cout << "&v2 : " << &v2 << endl;

	cout << "&v[0] : " << &v[0] << endl;
	cout << "&v2[0] : " << &v2[0] << endl;

	cout << "&v.begin() : " << &(*v.begin()) << endl;
	cout << "&v2.begin() : " << &(*v2.begin()) << endl;

	cout << "=================" << endl;

	vector<int> v3(5);

	v3[0] = 10;
	v3[1] = 20;
	v3[2] = 30;
	v3[3] = 40;
	v3[4] = 50;

	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
	cout << "size : " << v3.size() << " / capacity : " << v3.capacity() << endl;
	
	cout << endl;

	v3.front() = 100;
	v3.back() = 500;

	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
	cout << "size : " << v3.size() << " / capacity : " << v3.capacity() << endl;

	cout << "=================" << endl;

	return 0;
}


