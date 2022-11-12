포인터가 전달한 데이터의 자료형을 void로 설정할 수 있다.

이것이 의미하는 것은 어떤 자료형을 받을지 모른다는 것인데, 이때 형변환을 하지 않으면 포인터가 데이터를 받지 못하는 오류가 발생한다.

```arduino
void *p ;
*p = 5 ;// 오류 출력 :대상 메모리의 크기가 지정되지 않음.
```

따라서 형변환 (int *) 등을 적용해줘야하는데 다음과 같은 형태이다.