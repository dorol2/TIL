#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main()
{
	deque<int> dq;

	for (deque<int>::size_type i = 0; i < 10; ++i)
		dq.push_back((i + 1) * 10);

	for (deque<int>::size_type i = 0; i < 10; ++i)
		cout << dq[i] << " ";

	cout << endl;

	cout << "=================" << endl << endl;

	vector<int> v(4, 100);
	deque<int> dq2(4, 100);

	v.push_back(200);
	dq2.push_back(200);
	
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	for (deque<int>::size_type i = 0; i < dq2.size(); ++i)
		cout << dq2[i] << " ";
	cout << endl;

	cout << "=================" << endl << endl;

	deque<int> dq3;
	dq3.push_back(10);
	dq3.push_back(20);
	dq3.push_back(30);
	dq3.push_back(40);
	dq3.push_back(50);

	for (deque<int>::size_type i = 0; i < dq3.size(); ++i)
		cout << dq3[i] << " / " << &dq3[i] << "    ";
	cout << endl;

	dq3.push_front(200);
	dq3.push_front(300);

	for (deque<int>::size_type i = 0; i < dq3.size(); ++i)
		cout << dq3[i] << " / " << &dq3[i] << "    ";
	cout << endl;

	cout << "=================" << endl << endl;

	// 벡터는 배열의 사이즈가 커지면 이전의 원소를 복사하여 메모리를 재할당한다. (이전의 메모리는 삭제)
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " / " << &v[i] << "    ";
	cout << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " / " << &v[i] << "    ";
	cout << endl << endl;

	int j = 0;
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << v[j] << " / " << &v[j] << " / (" << &(* i) << ")    ";
		++j;
	}
	cout << endl;


	return 0;
}