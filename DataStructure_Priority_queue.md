# Priority queue
- - -
## 1. 우선순위 큐의 소개
용어만 봤을 때, 우선순위 큐는 큐에서 파생된 용어라는 점은 유추할 수 있다. 맞다. 먼저 들어온 데이터가 먼저 나가는 FIFO(선입선출)형식이 기본이다.

>도로에서의 차량을 생각해보자. 보통은 먼저 진입하는 차가 먼저 가게 되어있지만 만약 구급차나 소방차가 나타나면 우린 이러한 긴급 차량을 위하여 도로를 양보하여야 한다. 우선순위 큐가 바로 이런 성격을 갖는다.

이처럼 컴퓨터에서도 우선순위의 개념이 필요한 때가 종종 있다. 예를 들면, 네트워크 관리와 관련된 패킷은 다른 일반 패킷보다 우선 순위를 가진다. 또한 운영 시스템에서도 시스템 프로세스는 응용 프로세스보다 우선순위를 가지게 된다. 따라서 자료구조 내에서 우선순위 큐는 꽤 중요한 개념이다.

__우선순위 큐는 사실 가장 일반적인 큐__ 라 할 수 있다. 왜냐하면 스택이나 큐도 우선순위 큐를 사용하여 얼마든지 구현이 가능하기 때문이다. _적절한 우선순위만 부여하면 큐가 될 수도 있고, 스택이 될 수도 있다._ 들어오는 순서대로 우선순위를 부여하면 큐가 되고, 최근에 들어온 데이터 순서대로 우선순위를 부여하면 스택이 된다.

우선순위 큐는 컴퓨터 여러 분야에서 이용된다. 대표적으로 시뮬레이션 시스템(여기서의 우선순위는 대개 사건의 시각(time)), 네트워크 트래픽 제어, 운영 체제에서의 작업 스케쥴링, 수치 해석적인 계산 등에 사용된다.

우선순위 큐는 기존에 써오던 방식처럼 배열로도 생성 가능하고, 연결 리스트로도 생성 가능하지만, 여기서는 ***히프(heap)*** 라는 새로운 개념을 도입해 생성하겠다. 가장 효율적인 구조이기 때문이다.
- - -
## 2. 히프(heap)

> heap : (아무렇게나 쌓아 놓은)더미, 많음

히프는 __완전 이진 트리__ 의 일종으로 우선순위 큐를 위하여 만들어진 자료구조이다. 히프의 삽입과 삭제는 O(logn)이 걸리므로, 배열로 만들거나 연결 리스트로 만든 우선순위 큐보다 더욱 효율적이다.
```
cf) 배열이나 연결 리스트로 만든 우선순위 큐는 삽입은 O(1)이며, 삭제는 O(n)이다.
```
![heap_classify](https://user-images.githubusercontent.com/34874451/43559960-4b09297a-964b-11e8-9aff-65f0c56957a2.jpg)

히프는 위의 그림처럼 두가지 종류로 나뉜다. __최대 히프(max heap)__ 와 __최소 히프(min heap)__ 두 가지로 나뉜다. 부모 노드의 키 값이 자식 노드보다 큰 히프가 최대 히프, 부모 노드의 키 값이 자식 노드보다 작은 히프가 최소 히프가 된다. <u>참고로 히프 트리에서는 중복된 값을 허용함에 유의하자.</u>

### ★우리는 최대 히프를 사용하여 우선순위 큐를 구현할 것이다.★
- - -
### 3. 히프의 구현

#### *히프 구조체*
```c
#define MAX_ELEMENT 200

typedef struct {
	int key;     //입력시킬 key
}element;
typedef struct {
	element heap[MAX_ELEMENT];   //배열로 구현
	int heap_size;   //index번호, 현재 히프 안에 저장된 요소의 개수
}HeapType;
```
<u>히프는 완전 이진 트리로 만든다</u>고 말했다. __완전 이진 트리는 index가 끊김이 없는 이진 트리라는게 특징이다. 이런 특징을 이용하여 1차원 배열을 도입하게된다.__ 1차원 배열도 'arr[0] ~ arr[99]' 까지 만든다고 치면 0, 1, 2, 3... 이렇게 끊김 없는 100개의 배열이 완성되므로 같은 효과를 낼 수 있다.
```
cf) heap[1] 이 루트 노드를 가리킨다. heap[0]은 존재하지 않는다고 생각한다.
    구현을 쉽게 하기 위해 heap[1] 부터 시작한다.
```

#### *히프의 삽입 절차 & 코드*
1. 새로운 노드를 히프의 마지막 노드에 이어서 삽입한다. (마지막 index + 1 부여)
2. 새로운 노드를 부모 노드와 비교하여 새로운 노드가 더 크다면 둘이 바꾼다.
3. 2번 문장을 가능할 때까지 반복한다.

><참고>인덱스 판별법
>1. 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2
>2. 오른쪽 자식의 인덱스 = (부모의 인덱스 ) * 2 + 1
>3. 부모의 인덱스 = (자식의 인덱스) / 2

```c
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);    //index

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
    //( 텅 빈 히프가 아니냐 && 자식 노드가 부모 노드보다 크냐)
		h->heap[i] = h->heap[i / 2]; //부모 노드값을 자식 노드(새 노드)에 삽입
		i /= 2;
	}
	h->heap[i] = item;   //부모 노드 자리에 자식 노드 값(새 노드) 삽입
}
```


#### *히프의 삭제 절차 & 코드*
우리는 최대 히프를 이용한 완전 이진 트리를 사용한다는 점을 기억하자. 최대 히프에서의 삭제 연산이란 우선순위가 가장 key값이 큰 루트 노드의 삭제를 의미한다.

1. 루트 노드를 삭제한다.
2. 루트 삭제 후 그 빈자리에 히프의 마지막 노드를 가져온다. (마지막 인덱스)
3. 루트와 그 자식들과 비교하여 루트가 더 작으면 둘의 값을 바꾼다. (삽입과 유사)
4. 3번 문장을 가능할 때까지 반복한다.

```c
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--]; //삭제할 것이므로 인덱스 1 감소

	parent = 1;        //루트
	child = 2;         //루트의 왼쪽 자식 노드
	while (child <= h->heap_size) {
		if ( (child < h->heap_size) &&
               ( h->heap[child].key < h->heap[child + 1].key ) )
      //( 마지막 인덱스까지 확인했냐 && 오른쪽 노드가 왼쪽 노드보다 크냐 )
			child++;   //오른쪽 노드가 크면 오른쪽 노드를 비교할 대상으로 선정
		if (temp.key >= h->heap[child].key) //비교했는데 새 노드가 더 큼(제 자리 찾음)
			break;
		h->heap[parent] = h->heap[child]; // 자식 노드 값을 부모 노드에 넣음(교환)
		parent = child; //자식을 부모 노드로 선정
		child * = 2; //새로운 자식 노드는 왼쪽 노드로 선정
                     //cf) 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2
	}
	h->heap[parent] = temp;
	return item; //기존 루트의 값(가장 큰 값) 배출
}
```
- - -
### 4. 우선순위 큐 구현
```c
#include <stdio.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child * = 2;
	}
	h->heap[parent] = temp;
	return item;
}

void main()
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType heap;
	init(&heap);

	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);

	e4 = delete_max_heap(&heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d > ", e6.key);
}
```
