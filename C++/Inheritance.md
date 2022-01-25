# 상속

기존에 정의해 놓은 클래스의 재활용을 목적으로 만들어진 문법적 요소



### 유도 클래스의 객체 생성 과정

유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면, 기초 클래스의 void 생성자 호출


```cpp
#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout<<"SoBase()"<<endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout<<"SoBase(int n)"<<endl;
	}
	void ShowBaseData()
	{
		cout<<baseNum<<endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30) // 부모 클래스의 기본 생성자 자동 호출
	{
		cout<<"SoDerived()"<<endl;
	}
	SoDerived(int n) : derivNum(n) // 부모 클래스의 기본 생성자 자동 호출
	{
		cout<<"SoDerived(int n)"<<endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) // 부모 클래스의 특정 생성자 호출
	{
		cout<<"SoDerived(int n1, int n2)"<<endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout<<derivNum<<endl;
	}
};

int main(void)
{
	cout<<"case1..... "<<endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout<<"-------------------"<<endl;
	cout<<"case2..... "<<endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout<<"-------------------"<<endl;
	cout<<"case3..... "<<endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	return 0;
};
```
출력 결과
```
case1.....
SoBase()
SoDerived()
20
30
-------------------
case2.....
SoBase()
SoDerived(int n)
20
12
-------------------
case3.....
SoBase(int n)
SoDerived(int n1, int n2)
23
24
```

### 유도 클래스의 객체 소멸 과정

유도 클래스의 소멸자가 실행 되고 난 다음에 기초 클래스의 소멸자가 실행된다.

## 접근 제어 지시자
















-----
