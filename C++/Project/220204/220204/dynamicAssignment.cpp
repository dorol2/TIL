#include <iostream>
#include <memory>
using namespace std;

class Chulsoo
{
private:
	int age;

public:
	Chulsoo()
	{
		cout << "Chulsoo() ������ �Ϸ�" << endl;
	}
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo(int age) ������ �Ϸ�" << endl;
	}
	Chulsoo(const Chulsoo& ref)
	{
		this->age = ref.age;
	}
	Chulsoo& operator=(Chulsoo &ref)
	{
		this->age = ref.age;
		return *this;
	}


	~Chulsoo()
	{
		cout << "~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}

	void SetAge(int age)
	{
		this->age = age;
	}
	int* GetAge()
	{
		return &(this->age);
	}

	void Introduce()
	{
		cout << "ö�� ���� : " << age << endl;
		cout << "ö�� ���� �ּ� : " << &age << endl;
	}

};

int main()
{
	//Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo));
	Chulsoo* chulsooPtr1 = new Chulsoo(32);
	
	chulsooPtr1->SetAge(32);
	chulsooPtr1->Introduce();

	//free(chulsooPtr1);
	delete chulsooPtr1;

	auto_ptr<Chulsoo> chulsooSmartPtr(new Chulsoo(23));
	
	//chulsooSmartPtr->SetAge(2);
	chulsooSmartPtr->Introduce();

	//delete chulsooSmartPtr;
	chulsooSmartPtr.reset();

	cout << "---" << endl;
	cout << "---" << endl;





	unique_ptr<Chulsoo> chulsooSmartPtr1(new Chulsoo(32));
	chulsooSmartPtr1->Introduce();
	cout << "unique_ptr<Chulsoo> Ÿ�԰� ���� ������ ȣ�� �� " << endl;

	//unique_ptr<Chulsoo> chulsooSmartPtr2 = chulsooSmartPtr1;
	unique_ptr<Chulsoo> chulsooSmartPtr2 = move(chulsooSmartPtr1);

	chulsooSmartPtr2->Introduce();
	//chulsooSmartPtr1->Introduce();
	cout << "---" << endl;
	chulsooSmartPtr2.reset();
	chulsooSmartPtr1.reset();












	cout << endl << endl;
	cout << "---" << endl;
	cout << "---" << endl;

	shared_ptr<Chulsoo> chulsooSmartPtr3(new Chulsoo(33));
	cout << chulsooSmartPtr3.use_count() << endl;
	chulsooSmartPtr3->Introduce();
	cout << "shared_ptr<Chulsoo> Ÿ�԰� ���� ������ ȣ�� ��" << endl;
	shared_ptr<Chulsoo> chulsooSmartPtr4 = chulsooSmartPtr3;
	cout << chulsooSmartPtr3.use_count() << endl;
	chulsooSmartPtr4->SetAge(44);
	chulsooSmartPtr3->Introduce();
	chulsooSmartPtr4->Introduce();
	cout << &chulsooSmartPtr3 << endl;
	cout << &chulsooSmartPtr4 << endl;

	chulsooSmartPtr4.reset();
	chulsooSmartPtr3.reset();

	cout << endl << endl;



	return 0;
}
