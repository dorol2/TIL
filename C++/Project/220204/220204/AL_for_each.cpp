#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Add
{
    int a;
public:
    explicit Add(int init = 0) :a(init) { }
    void operator()(int& r)
    {
        r += a;
    }
};
void main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    for_each(v.begin(), v.end(), Add(3));

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}