#include<iostream>
#include<vector>
#include<list>
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

    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    sort(v.begin(), v.end());
    //sort(lt.front(), lt.back());

    cout << endl;

    sort(v.begin(), v.end(), less<int>());
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << " ";
    }

    return 0;
}

