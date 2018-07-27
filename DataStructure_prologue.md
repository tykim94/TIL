# 자체참조 구조체
```c
typedef struct ListNode{
  char data[10];
  struct ListNode * link;   //자기 자신을 가리키는 포인터
} ListNode;
```
일반적으로 **항목의 개수를 미리 예측할 수 없는 경우** 에 자체 참조 구조체를 정의해 놓고 동적으로 기억장소를 할당받아서 이들을 포인터로 연결하여 자료구조를 완성한다. 주로 *연결리스트* 나 *트리* 를 만들때 사용된다.


# 함수 포인터
```c
#include <stdio.h>
void foo( int a)
{
  printf("foo : %d\n", a);
}

void main()
{
  void(* f)(int);   //f는 함수의 주소를 담는 포인터 타입이다.
  f = foo;
  f(10);
  (* f)(10);
}
```
f(10) 이나 (* f)(10)은 동일한 표현이다.


# 동적 메모리 할당
memory allocation 에서 따온 **malloc** 이라는 함수를 사용한다.

메모리를 개발자가 원하는 만큼만 꺼내 쓸 수 있기 때문에 효율적이다.
```c
void main()
{
  int *pi;
  pi = (int* )malloc(sizeof(int));  //생성
  //생략
  free(pi);   //해제
}
```
