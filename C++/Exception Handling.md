<Exception Handling 예외처리>

# try, catch, throw
- 하나의 try문에 여러 개의 catch문이 연결될 수 있다. <br>
- try 내에서 메서드를 호출하여 해당 메서드 내에서 예외 데이터를 전달할 수 있다. 
- 자료형이 일치하지 않아도 예외데이터는 전달한다. 

Ex)
```cpp
void InputName(char* name)
{
	cout << "이름 입력 : " << endl;
	cin >> name;

	if (strlen(name) <= 2)
		throw name;
}

int InputAge()
{
	int age;
	cout << "나이 입력 : " << endl;
	cin >> age;

	if (age < 1)
		throw age;
	
	return age;
}


int main()
{
	char name[512];
	int age;
	try
	{
		InputName(name);
		age = InputAge();

		cout << name << " / " << age << endl;
	}
	catch (char* e)
	{
		cout << "예외발생 잘못된 이름 입력 " << e << endl;
	}
	catch (int e)
	{
		cout << "예외발생 잘못된 나이 입력 " << e << endl;
	}

	return 0;
}
```

## 예외처리 정보 함수에 넣기 noexcept
- noexcept          : throw 하지 않는다는 의미
- noexcept(false)   : throw 하는 부분이 있음
- 넣지 않으면 기본적으로 noexcept(false)가 들어가는 듯. 아무것도 쓰지 않으면 throw 기능함. 

```cpp
void handler()
{
	cout << "in handler" << endl;
}

void f1(void) noexcept(false)
{
	cout << "About to throw 1" << endl;
	if (1)
		throw 1;
}

void f2(void) noexcept(false)
{
	try
	{
		f1();
	}
	catch(int e)
	{
		handler();
		throw e;
	}
}

int main()
{
	//f1();

	try
	{
		f2();
	}
	catch (int e)
	{
		cout << "Caught exception from f2" << endl;
	}

	return 0;
}
```

# 예외클래스 
## 표준 예외 클래스 











