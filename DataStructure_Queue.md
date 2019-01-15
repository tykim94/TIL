# Queue
- - -
## 1. 큐의 소개

### 선입 선출(FIFO : First_In First_Out)
큐는 먼저 들어온 데이터가 먼저 나가는 구조를 갖는다. 표를 사려고 줄을 선 모습을 상상하면 편하다. 들어온 순서대로 표를 받아 나간다. 이런 큐의 특성을 <u>선입선출</u>라고 부른다.

## 2. 큐의 구조

스택과 상당히 비슷한 구조를 띤다. 스택과의 차이점은, 스택은 top이라는 포인터 1개를 가지는 반면에, 큐는 맨 앞과 맨 뒤를 가리키는 *front포인터* 와 *rear포인터* 두 가지를 가지게 된다.

스택과 마찬가지로 **배열 방식** 으로도 만들고, **연결 리스트 방식** 으로도 만들것이다. 리스트도 차례차례 연결되어있다는 느낌이 강해서, 배열로 만들어도 충분히 효율적이다. 물론 <u>그때그때 원하는 만큼 동적할당 받는 스타일이 좋으면 **연결 리스트 방식** 을 사용</u>하면 되고, <u>한번에 빡 만들어놓은 뒤 사용하는 스타일이면 **배열 방식** 을 사용</u>하면 된다. ~~개발자의 개발 취향 차이다.~~

### 배열 방식의 문제 : 선형 큐(Linear queue) vs 원형 큐(Circular queue)
 선형 큐는 일반적으로 우리가 생각하는 1차원배열의 단순한 나열이라고 생각하면 된다. 선형 큐에서 데이터가 들어오면 rear를 1 늘려준 후 그 빈 자리에 배치해준다. 또한 출력시엔, front의 값을 출력하고, front의 값을 1 늘려준다. 하지만 ***rear의 값이 계속 증가하게 되면, 배열의 정해져있는 끝에 도달하게 되고 배열의 앞부분은 비어 있더라도 사용하지 못한다.***

 이런 문제점을 해결하기 위해 도입된 개념이 **원형 큐(Circular queue)** 이다. 만일 배열의 끝이 arr[100]이라면 그 다음 입력 값은 다시 arr[0]으로 돌아가는 것이다. 이런 식으로 마치 원형으로 이어져있는 것처럼 만드는 방식을 원형 큐라고 한다.

 *나는 원형 큐의 방식으로 큐를 구현하려 한다.*

## 3. 큐 알고리즘

- ### 알고리즘 전, 사전준비
>front와 rear이라는 변수(혹은 포인터변수)를 이용하여 맨 앞과 맨 뒤를 가리켜서 데이터의 입력과 출력을 돕는다.

  - ___배열 방식___

  ```c
  #define Max_QUEUE_SIZE 100
  typedef int element;
  typedef struct {
	element queue[Max_QUEUE_SIZE];
	int front, rear;
  } QueueType;
  ```

  - ___연결 리스트 방식___

  ```c
  typedef int element;
  typedef struct QueueNode {
  	element item;
  	struct QueueNode * link;
  } QueueNode;
  typedef struct {
  	QueueNode * front, * rear;
  } QueueType;
  ```


- ### 삽입 알고리즘  

  - ___배열 방식___

  ```c
    void enqueue(QueueType *q, element item)
    {
	     if (is_full(q))
		     error("큐가 포화상태입니다.");
         q->rear = (q->rear + 1) % Max_QUEUE_SIZE;
         q->queue[q->rear] = item;
    }
  ```

  - ___연결 리스트 방식___

  ```c
    void enqueue(QueueType *q, element item)
    {
	     QueueNode * temp = (QueueNode * )malloc(sizeof(QueueNode));
	      if (temp == NULL)
		      error("메모리를 할당할 수 없습니다.");
	      else {
		 temp->item = item;
	 	 temp->link = NULL;
	  	if (is_empty(q)) {
	 		 q->front = temp;
			 q->rear = temp;
	 	}
		 else {
			q->rear->link = temp;  //rear포인터를 통해 새로 할당된 노드와 연결
			q->rear = temp;        //rear포인터가 새로 할당된 노드 가리킴
		  }
	     }
   }
  ```


- ### 삭제 알고리즘

 - ___배열 방식___
    ```c
    element dequeue(QueueType *q)
    {
	       if (is_empty(q))
		     error("큐가 공백상태입니다.");
	        q->front = (q->front + 1) % Max_QUEUE_SIZE;
	         return q->queue[q->front];
     }
    ```
 - ___연결 리스트 방식___
  ```c
    element dequeue(QueueType *q) {
    	  QueueNode * temp = q->front;
      	element item;
      	if (is_empty(q))
      		error("큐가 비어 있습니다.");
      	else {
      		item = temp->item;
      		q->front = q->front->link;
      		if (q->front == NULL)       //노드가 하나 있는 큐
      			q->rear = NULL;
      		free(temp);                 //동적할당 해제
      		return item;
      	}
      }
  ```


## 4. 큐의 구현

### ___배열 방식___

```c
#include<stdio.h>

#define Max_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element queue[Max_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return(q->front == q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % Max_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % Max_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % Max_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->queue[(q->front + 1) % Max_QUEUE_SIZE];
}

void main()
{
	QueueType q;
	init(&q);
	printf("front = %d rear = %d\n", q.front, q.rear);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("front = %d rear = %d\n", q.front, q.rear);

}
```

### ___연결 리스트 방식___

```c
#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct QueueNode {
	element item;
	struct QueueNode * link;
} QueueNode;
typedef struct {
	QueueNode * front, * rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q)
{
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q)
{
	return(q->front == NULL);
}

void enqueue(QueueType *q, element item)
{
	QueueNode * temp = (QueueNode * )malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리를 할당할 수 없습니다.");
	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType *q) {
	QueueNode * temp = q->front;
	element item;
	if (is_empty(q))
		error("큐가 비어 있습니다.");
	else {
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}

element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 비어 있습니다.");
	else
		return q->front->item;
}

void main()
{
	QueueType q;

	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
}
```


- - -

## 5. 큐의 활용 1 : 덱(deque)
### 덱의 소개
덱은 ___double-ended queue___ 의 줄임말로서 <u>큐의 front와 rear에서 모두 삽입과 삭제가 가능한 큐</u>를 의미한다.

### 덱의 구조
front와 rear가 존재한다는 것은 기존의 큐와 다를게 없지만, __이중 연결 리스트 방식__ 을 사용한다는 점에서 차이점이 생긴다.

### 덱 구현
```c
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode * llink;
	struct DlistNode * rlink;
} DlistNode;

typedef struct DequeType {
	DlistNode * head;
	DlistNode * tail;
} DequeType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(DequeType *dq)
{
	dq->head = dq->tail = NULL;
}

DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink)
{
	DlistNode * node = (DlistNode * )malloc(sizeof(DlistNode));
	if (node == NULL)
		error("메모리 할당 오류");
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node;
}

int is_empty(DequeType *dq)
{
	if (dq->head == NULL)
		return TRUE;
	else return FALSE;
}

void add_rear(DequeType *dq, element item)
{
	DlistNode * new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq))
		dq->head = new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType *dq, element item)
{
	DlistNode * new_node = create_node(NULL, item, dq->head);
	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

element delete_front(DequeType *dq)
{
	element item;
	DlistNode * removed_node;

	if (is_empty(dq))
		error("공백 덱에서의 삭제");
	else {
		removed_node = dq->head;
		item = removed_node->data;
		dq->head = dq->head->rlink;
		free(removed_node);

		if (dq->head == NULL)
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return item;
}

element delete_rear(DequeType *dq)
{
	element item;
	DlistNode * removed_node;

	if (is_empty(dq))
		error("공백 덱에서의 삭제");
	else {
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->llink;;
		free(removed_node);

		if (dq->tail == NULL)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

void display(DequeType *dq)
{
	DlistNode * p;
	printf("(");
	for (p = dq->head; p != NULL; p = p->rlink) {
		printf(" %d", p->data);
	}
	printf(")\n");
}

void main()
{
	DequeType deque;

	init(&deque);
	add_front(&deque, 10);
	add_front(&deque, 20);
	add_rear(&deque, 30);
	display(&deque);

	delete_front(&deque);
	delete_rear(&deque);
	display(&deque);
}
```

## 5. 큐의 활용 2 : 버퍼(buffer)
큐는 <u>서로 다른 속도로 실행되는 두 프로세스 간의 상호 작용을 조화시키는 __버퍼__ 역할</u>을 담당한다.

>예를 들면, 우리가 키보드로 hello world! 를 입력하고 모니터로 보낼 때, 우선 stdin 이라는 버퍼에 hello world!라는 문자열을 집어넣고 컴퓨터가 버퍼에서 끄집어 내 모니터로 출력시킨다.
>
>또다른 예시로는, 인터넷 네트워크 상에서 A에서 B로 데이터를 보낼 때, 데이터를 패킷별로 끊어서 보내고, 나뉜 패킷은 각각의 라우터에 들어갈 때, 버퍼를 거쳐서 들어가게 된다. 각 파트마다 보내고 받는 속도가 다르다 보니, 버퍼가 없다면 대다수의 데이터가 보내지지 못해 통신 내에서 사라지게 된다. 그래서 중요한게 버퍼인데 버퍼는 우리가 배운 큐로 만들어진다. 데이터가 버퍼(큐)에 들어오는 순서대로 차례차례 나가게 된다. 또한 큐에서 데이터를 저장하고 있기 때문에, 데이터가 사라지지 않는다. 물론 버퍼의 크기가 작아 꽉 차게 되면, 버퍼(큐)로 못 들어온 데이터는 사라지게 되는데, 이를 네트워크상에서는 패킷드랍(Packet drop)이라고 한다.

만약 <u>동일한 컴퓨터에서 생산자와 소비자 프로세스가 동시에 수행된다면 공유되는 큐를 동시에 접근하여 문제가 발생</u>할 수 있다. 따라서 그런 경우에는 공유되는 큐를 사용하기 전에 큐를 사용한다고 먼저 __락(lock)__ 을 거는 것이 중요한데, 락을 생산자 입장에서 걸게 되면 다른 프로세스(소비자 프로세스)가 큐를 건드릴 수 없게 된다.

```c
QueueType buffer;

producer()
{
  while(1){
    while( lock(buffer) != SUCCESS ); //락 확인
    if( !is_full(buffer) ){
      enqueue(buffer, 데이터);
    }
    unlock(buffer);                   //락 해제!!
  }
}
```
