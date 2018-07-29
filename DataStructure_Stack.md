# Stack
- - -
## 1. 스택의 소개

### 후입선출(LIFO: Last-In First-Out)
스택은 들어오는 순서대로 차례차례 입력되는데 출력은 입력과 반대로 가장 최근에 들어온 순서대로 행한다. 나중에 들어온 것이 먼저 나간다는 의미로 <u>후입선출</u>이라고 부른다.

## 2. 스택의 구조

말 그대로 쌓다(Stack)라는 의미를 가진 만큼, 박스를 쌓는 것과 같다. 들어오는 순서대로 쌓고, 나가는 순서는 반대로 가장 최근에 들어온 박스부터 나간다. 따라서 배열을 사용하는 방법도 꽤 스택의 정의를 따르기 좋기 때문에 **배열로 만든 스택** 도 선보일 예정이다.

**연결 리스트를 이용한 스택의 생성** 도 보이겠다. 구조는 연결 리스트와 크게 다르지 않다. 차이점이라면 연결 리스트는 헤드 포인터를 가지고 만들었다면, 스택은 top포인터를 가지고 만들게된다.

## 3. 스택 알고리즘
- ### 알고리즘 전, 사전준비
>top이라는 변수(혹은 포인터변수)를 이용하여 가장 상단의 데이터를 기반으로 삽입, 삭제가 이루어지도록 돕는다.

  - ___배열 방식___

  ```c
  #define MAX_STACK_SIZE 100

  typedef int element;
  typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
  } StackType;
  ```
  구조체에 배열 전체와 top변수를 같이 넣어서 이용한다.
  - ___연결 리스트 방식___

  ```c
  typedef int element;

  typedef struct StackNode{
    element item;
    struct StackNode * link;
  } StackNode;

  typedef struct {
    StackNode * top;
  } LinkedStackType;
  ```
  **포인터가 link와 top 2개** 가 나오는데, *link포인터* 는 자체참조 구조체로서 연결 리스트와 똑같은 연결을 담당한다. *top포인터* 는 가장 최근에 삽입한 StackNode구조체를 가리키는 역할을 하게되며, 연결 리스트와의 유일한 차이점이다.
 - - -
- ### 삽입 알고리즘
  - ___배열 방식___

  ```c
  void push(StackType *s, element item)
  {
    if (is_full(s) ) {
      fprintf(stderr, "스택 포화 에러\n");
      return;
    }
    else s->stack[++(s->top)] = item;
  }
  ```
  - ___연결 리스트 방식___

  ```c
  void push(LinkedStackType *s, element item)
  {
    StackNode * temp = (StackNode * )malloc(sizeof(StackNode));
    if( temp == NULL ){
      fprintf(stderr, "메모리 할당에러\n");
      return;
    }
    else{
      temp->item = item;
      temp->link = s->top;
      s->top = temp;
    }
  }
  ```
 - - -
- ### 삭제 알고리즘
  - ___배열 방식___

  ```c
  element pop(StackType *s)
  {
    if(is_empty(s) ){
      fprintf(stderr, "스택 공백 에러\n");
      exit(1);
    }
    else return s->stack[(s->top)--];
  }
  ```
  - ___연결 리스트 방식___

  ```c
  element pop(LinkedStackType *s)
  {

    if(is_empty(s) ){
      fprintf(stderr, "스택이 비어있음\n");
      exit(1);
    }
    else{
      StackNode * temp = s->top;
      element item = temp->item;
      s->top = s->top->link;
      free(temp);
      return item;
    }
  }
  ```

## 4. 스택의 구현
### ___배열 방식___
```c
#include<stdio.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}

void main()
{
	StackType s;

	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}
```
### ___연결 리스트 방식___
```c
#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode{
	element item;
	struct StackNode * link;
} StackNode;

typedef struct {
	StackNode * top;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

void push(LinkedStackType *s, element item)
{
	StackNode * temp = (StackNode * )malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType *s)
{

	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode * temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	LinkedStackType s;

	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}
```
- - -
## 5. 스택의 활용 : 미로 탐색 문제

★_'배열을 이용해 구현한 스택'_ 을 사용하여 미로 탐색 문제를 풀자.


<img src="https://user-images.githubusercontent.com/34874451/43363271-3af02366-933c-11e8-8c82-b698130e759b.jpg" width="500" height="700">

스택에 갈 수 있는 모든 길을 좌표로 받아 저장한다. 상하좌우 모두 받은 다음엔 스택에서 하나씩 꺼내서 그 좌표로 이동하고 다시 상하좌우 좌표를 받는다. 이런 식으로 목표 지점까지 이동한다.

### 미로 탐색 구현
```c
#include<stdio.h>
#include<string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r; //r = row 가로, 행
	short c; //c = column 세로, 열
} element;

element here = { 1,0 }, entry = { 1,0 };

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}
/////////////////////////////////////////////////////


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void push_loc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void main()
{
	int r, c;
	StackType s;

	init(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		printf("[%hd,%hd] ", here.r, here.c); //발자취 확인을 위해 대입
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s); //스택에서 top이 가리키는 요소 제거 후 here에 대입
	}
	printf("성공\n");
}
```
__↓컴파일 된 결과↓__

<img src="https://user-images.githubusercontent.com/34874451/43364057-abfd0dec-934d-11e8-82d7-5455f80589a9.PNG" width="400" height="300">
