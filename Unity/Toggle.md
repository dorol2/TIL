# Unity toggle

## 2021-04-23

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
