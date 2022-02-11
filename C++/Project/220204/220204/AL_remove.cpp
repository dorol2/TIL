#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;

    vector<int>::iterator iter_end;
    iter_end = remove(v.begin(), v.end(), 30);

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;

    cout << "remove �� [v.begin(), iter_end) ������: " << endl;
    cout << "v : ";
    for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
        cout << "(" << *iter << ", " << &(*iter) << ") ";
    cout << endl;

    v.erase(iter_end, v.end());

    cout << "erase �� : " << endl;

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;
}