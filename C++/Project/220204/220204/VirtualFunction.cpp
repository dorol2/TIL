#include<iostream>
using namespace std;

class First
{
public: 
	virtual void MyFunc()
	{
		cout << "Frist Func" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()
	{
		cout << "Second Func" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "Third Func" << endl;
	}
};

int main()
{

	auto t1 = make_unique<Second>();


	Third* third = new Third();
	Second* second = third;//new Second();
	First* first = second; //new First();

	first->MyFunc();
	second->MyFunc();
	third->MyFunc();

	delete third;
	return 0;
}