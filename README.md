# TIL

그날그날 알게 된 것들 정리할 예정

# TIL - 1 (2021-04-23)

## unity toggle

```csharp
1.  toggle.onValueChanged.Invoke(true);
2.  toggle.isOn = true;
```

1번은 onValueChanged에 연결된 이벤트만 호출하고 토글 자체는 on이 안된다.

2번은 토글도 on시키고 onValueChanged도 invoke 한다.


# TIL - 2 (2021-04-26)

## unity toggle
```csharp
toggle.SetIsOnWithoutNotify(true);
```

토글의 이벤트를 invoke시키지 않고도 토글의 값을 변경할 수 있다. 

## 참조 형식 매개변수 전달

[참조 형식 매개 변수 전달 참고](https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/classes-and-structs/passing-reference-type-parameters)

참조형식의 변수에는 해당 데이터가 직접 포함되지 않고, 데이터에 대한 참조가 포함된다. 
- 참조 형식 매개 변수를 값으로 전달하는 경우, 클래스 멤버 값 등 참조된 개체에 속하는 데이터를 변경할 수 있다.
- 참조 자체의 값은 변경할 수 없다. -> 동일한 참조를 사용하여 새 개체에 대한 메모리를 할당하고 메서드 외부에 유지되도록 할 수 없다. 

```csharp
class PassingRefByVal
{
    static void Change(int[] pArray)
    {
        pArray[0] = 888;  // This change affects the original element.
        pArray = new int[5] {-3, -1, -2, -3, -4};   // This change is local.
        System.Console.WriteLine("Inside the method, the first element is: {0}", pArray[0]); 
          -> -3
    }

    static void Main()
    {
        int[] arr = {1, 4, 5};
        System.Console.WriteLine("Inside Main, before calling the method, the first element is: {0}", arr [0]); 
          -> 1

        Change(arr);
        System.Console.WriteLine("Inside Main, after calling the method, the first element is: {0}", arr [0]); 
          -> 888
    }
}
```
참조 형식인 arr배열은 ref변수 없이 메서드에 전달된다. new 연산자를 사용하여 새 메모리를 할당하면 pArray변수가 새 배열을 참조한다. 

