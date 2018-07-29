# Linked list
- - -
## 1. 연결리스트의 소개
**배열을 이용한 리스트** 의 **단점**
- 애초에 배열의 갯수를 정해놓고 시작하는 것이라 유연성이 굉장히 떨어진다.
- 배열 중간의 추가, 삭제 시 모든 데이터를 다시 건드려야 하는 불편함이 존재한다.

**연결리스트(Linked list)** 의 **장점**
- 애초에 흩어져 있는 자료들을 서로 연결하여 하나로 묶기에 물리적 메모리가 자유롭다.
- 데이터의 추가, 삭제가 배열을 이용한 리스트에 비해 간단하다.

## 2. 연결리스트의 구조

노드라고 부르는 집합엔 내가 저장하길 원하는 **데이터(data field)** 와 자체참조 를 활용한 **링크 필드(Link field)** 로 구성된다. 또한 이런 <u>노드가 여러 개 연결되어 연결리스트를 만든다.</u>

또한 우린 첫 번째 노드를 알아야 전체 노드에 접근이 가능한데, 따라서 우린 추가로 첫 번째 노드를 가리키는 **헤드 포인터(head pointer)** 도 만든다.
>헤드포인터 → 노드(data/link) → 노드(data/link) → ...... → 노드(data/link) → NULL

```c
typedef int element;
typedef struct ListNode {
  element data;
  struct ListNode * link;
} ListNode;
```
**연결리스트(Linked list)** 의 **단점**
- **Link field** 라는 파트가 생기면서 메모리를 조금 더 잡아먹게 된다.
- *배열을 이용한 리스트* 에 비해 프로그래밍 난이도가 높아진다.

## 3. 연결리스트의 알고리즘

### 알고리즘 전, 사전준비

  헤드 포인터만 알고있으면 모든 노드에 접근이 가능하므로, 헤드 포인터를 생성한다.
  ```c
  ListNode *head;    //헤드 포인터
  ```
  반드시 head가 아니라 헤드 포인터는 곧 하나의 리스트 자체이므로, 아래처럼
  ```c
  ListNode *list1, *list2;
  ```
  라고 적을 수 있다.
### 삽입 알고리즘

  ```c
  void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
   - phead : 헤드 포인터 head에 대한 포인터 (2중포인터)
  - p : 삽입될 위치의 선행노드를 가리키는 포인터, 이 노드 다음에 삽입됨
  - new_node : 새로운 노드를 가리키는 포인터
  }
  ```
  ★Q. phead를 헤드 포인터의 포인터(2중포인터)로 받은 이유?

  ★A. 함수 안에서 헤드 포인터를 변경해야 하기 때문

  >  1) head가 NULL인 경우
>  
>    new_node가 첫 번째 노드라는 의미(선행노드가 없음)이다. 따라서 head의 값만 변경한다.
>
>  2) p가 NULL인 경우
>
>  선행 노드가 존재하지 않는 노드의 삽입이다. 그 의미는 리스트의 맨 앞에 삽입된다는 의미. 따라서, new_node의 link가 head와 같은 값을 갖도록 하고, head가 new_node를 가리키도록 한다.
>
>  3) head와 p가 NULL이 아닌 경우
>
>  일반적인 경우. new_node의 link에 선행노드의 링크(p->link)값을 복사한 후, 선행노드의 링크(p->link)가 new_node를 가리키도록 한다.

### 삭제 알고리즘
모든 노드가 동적할당 받은 노드이므로 삭제 이후에 시스템에 반환함을 잊으면 안된다.
>1) p가 NULL인 경우
연결리스트의 첫 번째 노드를 삭제한다. 헤드 포인터를 변경하고 removed 노드가 차지하고 있는 공간을 시스템에 반환한다.
>
>2) p가 NULL이 아닌 경우
removed 앞 선행노드인 p의 링크가 removed 다음 노드를 가리키도록 변경하고 removed 노드가 차지하고 있는 공간을 시스템에 반환한다.

### 방문(display), 탐색(search), 통합(concat) 알고리즘
코드를 통해 이해가 가능하므로 생략한다.

### 연결 리스트 역순 알고리즘
세 개의 포인터 p, q, r을 이용하여 연결리스트를 순회하며 연결을 역순으로 바꾼다.
p,q,r은 셋이 연속된 노드를 가리키며, head부터 시작해서 한 칸 한 칸 올라가서 노드의 끝까지 이동한다. p가 마지막 노드의 링크까지 이동하여 NULL이 되어 while을 빠져나가며 역순으로의 배열을 마친다.
```c
ListNode *reverse(ListNode *head)
{
    ListNode * p, * q, * r;
    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}
```
## 4. 연결 리스트의 구현
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode * link;
}ListNode;

//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) {
		new_node->link = NULL;
		* phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = * phead;
		* phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		* phead = (* phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void display(ListNode *head)
{
	ListNode * p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

ListNode *search(ListNode *head, int x)
{
	ListNode * p;
	p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return p;
}

ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode * p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode *reverse(ListNode *head)
{
	ListNode * p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

ListNode *create_node(element data, ListNode *link)
{
	ListNode * new_node;
	new_node = (ListNode * )malloc(sizeof(ListNode));
	if (new_node == NULL)
		error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

void main()
{
	ListNode * list1 = NULL, * list2 = NULL;
	ListNode * p;

	//list1 삽입
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	//list1 맨 앞 노드 삭제
	remove_node(&list1, NULL, list1);
	display(list1);

	//list2 삽입
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	//list1 + list2
	list1 = concat(list1, list2);
	display(list1);

	//list1 뒤집기
	list1 = reverse(list1);
	display(list1);

	//list1 탐색
	p = search(list1, 20);
	printf("탐색 성공: %d\n", p->data);
}
```
- - -
## 원형 연결리스트
기존 연결리스트와 다른 점이 딱 하나 존재하는데, **기존의 연결리스트** 는 마지막 노드의 링크가 NULL을 가리키며 끝나는데, **원형 연결리스트** 는 마지막 노드의 link가 가장 첫 번째 노드를 가리키게 된다.

따라서 <u>첫 번째 노드를 가리키는 것</u>은 *헤드 포인터* 와 *마지막 노드의 링크* 두 가지이다.

**원형 연결리스트** 의 **장점**
- 리스트의 끝에 노드를 삽입하는 연산이 단순 연결리스트에 비해 효율적이다. 만일 헤드 포인터가 마지막 노드를 가리키도록 구성한다면 상수 시간 안에 리스트의 처음이나 끝에 노드 삽입이 가능하다.

### 원형 연결리스트의 맨 앞 삽입 알고리즘
```c
void insert_first(ListNode **Phead, ListNode *node){
  if(*phead == NULL){
    * phead = node;
    node->link = node;
  }
  else {
    node->link = (* phead)->link;
    (* phead)->link = node;
  }
}
```
### 원형 연결리스트의 맨 뒤 삽입 알고리즘
```c
void insert_first(ListNode **Phead, ListNode *node){
  if(*phead == NULL){
    * phead = node;
    node->link = node;
  }
  else {
    node->link = (* phead)->link;
    (* phead)->link = node;
    * phaed = node;  //달라진 건 오직 이 문장 하나뿐이다.
  }
}
```
- - -
## 이중 연결리스트
연결리스트에서 후속 노드를 찾는건 아주 쉽다. node->link를 하면 그만이다. 하지만, 선행 노드를 찾고 싶다면? 여간 어려운 게 아니다. 따라서 우린 **기존 노드에 링크를 하나 더 추가** 하여 *left link* 와 *right link* 를 추가해서 <u>양 옆으로의 이동이 원할하게 만들었다.</u>

또한 위의 두 가지 연결리스트와는 다르게 헤드 포인터가 아닌 그 자리를 대체할 **헤드 노드(head node)** 를 가지게 되는데 헤드 노드는 데이터를 가지지 않는다는 특징을 지닌다.
```c
typedef int element;
typedef struct DlistNode {
  element data;
  struct DlistNode * llink;
  struct DlistNode * rlink;
} DlistNode;
```

### 이중 연결리스트의 삽입 알고리즘
```c
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
  new_node->llink = before;
  new_node->rlink = before->rlink;
  before->rlink->llink = new_node;
  before->rlink = new_node;
}
```
### 이중 연결리스트의 삭제 알고리즘
```c
void dremove_node(DlistNode *phead_node, DlistNode *removed)
{
  if( removed == phead_node)
    return;
  removed->llink->rlink = removed->rlink;
  removed->rlink->llink = removed ->llink;
  free(removed);
}
```
