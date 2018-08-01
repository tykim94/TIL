# Tree
- - -
## 1. 트리의 소개

리스트, 스택, 큐 등의 공통점은 무엇일까? 바로 '선형 자료 구조(linear data structure)'이라는 점이다. 자료들이 말 그대로 linear하게 직선과 같이 나열되어 있는 구조를 의미한다. 우리는 선형(linear)인 자료를 배워왔기에 1차원 배열의 형식으로도 충분히 구현할 수 있었고, 어찌보면 오히려 link를 이용한 연결 리스트 방식보다 배열형 방식이 오히려 눈에 더 잘 들어왔다.

하지만 만일 자료가 선형(linear)인 형태가 아니라면 어떻게 해야 할까? 자료가 '가족의 계보'라든지  '회사 직급상의 상하 관계', '컴퓨터 디렉터리 구조' 같은 자료라면 어떤 방식으로 저장해야 좋을까? 그 해답이 바로 __트리__ 이다. 이러한 구조를 __'계층적인 구조(hierarchical structure)'__ 이라고 한다.

## 2. 트리의 구조

나무를 거꾸로 엎어놓은 듯한 모양을 하고 있기 때문에 __'트리'__ 라는 이름이 붙게 되었다. 트리의 구성요소인 __'노드'__ 우리가 이때까지 만든 노드와 크게 다르진 않다. 데이터와 링크를 가졌다. 트리는 한 개 이상의 노드로 이루어진 유한 집합이며, 최상단의 노드를 __'루트(root)'__ 라고 부른다. 루트를 제외한 나머지 노드들은 __'서브 트리(subtree)'__ 라고 불린다. 루트와 서브트리는 선으로 연결되는데 이 선을 __'간선(edge)'__ 이라고 한다.

노드들 간에는 부모 관계, 형제 관계, 조상과 자손 관계가 존재한다.
- 부모 노드(parent node), 자식 노드(children node) : 둘이 부모와 자식 관계이다.
- 형제관계(sibling) : 같은 부모에서 나온 모든 자식 노드들을 한꺼번에 부르는 명칭
- 조상 노드(ancestor node) : 루트 노드에서 임의의 노드까지의 경로를 잇는 노드들
- 자손 노드(descendent node) : 임의의 노드 하위에 연결된 모든 노드들


- 단말 노드(terminal node,또는 leaf node) : 자식 노드가 없는 노드
- 비단말 노드(nonterminal node) : 자식 노드가 있는 노드


- 차수(degree) : 임의의 노드가 가진 자식 노드의 개수
  //ex)단말 노드는 차수가 0이다.
- 레벨(level) : 트리의 각 층에 매기는 번호 //ex) 루트(레벨1), 루트의 자식노드(레벨2)


- 트리의 높이(height) : 트리가 가진 최대 레벨
- 포리스트(forest) : 사전에 실린 의미 그대로, 나무(트리, tree)들이 모인 집합

### 트리의 종류
우리는 트리를 공부하기 전에 하나 정해 둘 것이다. 바로 ___이진트리(binary tree)___ 만을 사용한다는 점이다. 이게 무슨 소리일까?

'D대학교'라는 루트 노드가 있다고 하자. 그 아래에는 엄청나게 많은 서브트리가 존재한다. 사회과학대, 공과대, 이과대, 문과대, 사범대, 예술대 등등 나열한 것만 따져도 벌써 엣지를 6개나 이어야한다. 그러면 우린 루트 노드를 이런 식으로 만들 것이다.
```
                  ↓루트노드↓

<데이터(D대학교)/링크1(사회과학대)/링크2(공과대)/링크3(이하 생략)/링크4/링크5/링크6>
```
링크2(공과대)를 타고 내려갔다고 하자.
```
                  ↓공과대 노드↓
<데이터(공과대)/링크1(컴공)/링크2(화공)/링크3...중간생략.../링크9(산업시스템공학과)>
```

각각의 노드들은 링크 필드의 개수가 달라진다. 이 방법의 문제는 _노드의 크기가 고정되지 않는다는 것이다._ 이때까지 우린 <u>연결리스트, 스택, 큐 는 링크 필드의 개수가 1개</u>, <u>이중연결리스트, 덱 은 링크 필드의 개수가 2개</u>로 일정하여서 프로그램 짜는게 수월했지만, 이렇게 모든 노드의 링크 필드의 개수가 다르면 프로그램 만드는게 여간 까다롭지 않을 것이다. __따라서 우린 자식 노드의 개수가 오직 2개인 이진 트리만을 다루기로 한다.__

### 이진 트리(binary tree)의 정의
- 모든 노드는 차수가 2 이하이다. 즉, 자식 노드의 개수에 제한이 있다.
- 공집합도 이진 트리이다. 즉, 노드를 하나도 갖지 않을 수도 있다.
- 서브 트리 간에 순서가 존재한다. 따라서 왼쪽 서브 트리와 오른쪽 서브 트리를 구별한다.

### 이진 트리(binary tree)의 성질
- n개의 노드를 가진 이진 트리는 정확하게 n-1개의 간선을 가진다.
- 높이가 h인 이진 트리의 경우, 최소 h개, 최대 2^h-1개의 노드를 가진다.
- n개의 노드를 가지는 이진 트리의 높이는 최대 n, 최소 ┌log2(n+1)┐이다.
    - cf)┌...┐ = 천장함수(ceiling function)__(__ ex)  ┌3.2┐ = 4 / ┌16┐ = 16 __)__

### 이진 트리(binary tree)의 분류
- 포화 이진 트리(full binary tree) : 각 레벨에 노드가 꽉 차 있는 이진트리
 - 만일 레벨 3인 트리라면? 노드의 개수 : 항상 7개
 - 노드에 번호를 붙이는 방법 : 레벨 단위로 왼쪽에서 오른쪽으로 번호 부여
   - 루트 : 항상 1, 루트의 오른쪽 자식 노드 : 항상 3
- 완전 이진 트리(complete binary tree) : 높이가 k 인 트리라면, 레벨 1부터 k-1까지는 노드가 모두 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진 트리이다.
 - 만일 레벨 4인 트리라면? 노드의 개수 : 항상 8 ~ 14개
- 기타 이진 트리 : 기타 여기저기 뻥뻥 뚫려있는 트리

<img src="https://user-images.githubusercontent.com/34874451/43442800-078373f8-94da-11e8-9829-fbcccb5f2d3b.jpg" width="500" height="160">

### 이진 트리(binary tree) 표현법
우린 스택과 큐를 배울 때처럼 배열을 이용할 수도 있고, 연결 리스트 방식을 이용할 수 있다. 하지만 __거의 대부분은 연결 리스트의 방식을 이용한다.__ 배열 방식을 사용해보면 알 수 있겠지만 메모리 공간 낭비가 너무 심하기 때문에 배열 방식의 표현은 가급적 지양한다.

## 3. 이진 트리 구조체 구현 & 순회 & 연산
- ### 알고리즘 전, 사전준비
>left와 right라는 포인터 변수를 만들어서 양 쪽의 자식 노드를 이을 수 있게 만든다.

```c
typedef struct TreeNode {
  int data;
  struct TreeNode * left, * right;     //자체참조 구조체, 링크필드 오직 2개!!
} TreeNode;
```
- ### 이진 트리의 순회
이때 까지 공부했던 자료형인 연결 리스트, 스택, 큐의 공통점은 선형 자료 구조임을 언급했었다. 선형 자료 구조는 저장된 데이터를 순회하는 방법은 차례차례 앞에서 뒤로 읽는 방법 한 가지였다. 하지만 계층적인 구조를 가지는 트리는 자료를 순회하는 방법이 3가지나 있다.
 - 전위 순회(preorder traversal) : 루트 노드 → 왼쪽 서브 트리 → 오른쪽 서브 트리
 - 중위 순회(inorder traversal) : 왼쪽 서브 트리 → 루트 노드 → 오른쪽 서브 트리
 - 후위 순회(postorder traversal) : 왼쪽 서브 트리 → 오른쪽 서브 트리 → 루트 노드

 __3가지 순회 방법 구현__
 ```c
 //전위 순회(preorder traversal)
 void preorder(TreeNode *root) {
   if(root){
     printf("%d",root->data);
     preorder(root->left);
     preorder(root->right);
   }
 }
 //중위 순회(inorder traversal)
 void inorder(TreeNode *root) {
    if(root){
      inorder(root->left);
      printf("%d", root->data);
      inorder(root->right);
    }
 }
 //후위 순회(postorder traversal)
 void postorder(TreeNode *root) {
    if(root){
      postorder(root->left);
      postorder(root->right);
      printf("%d",root->data);
    }
 }
 ```
  - 레벨 순회(level order traversal) : 우리가 노드에 번호를 붙였던 순서대로 읽는 방식. 각 노드를 레벨순으로 검사하는 순회 방식으로, 레벨 1, 2, 3 순으로 순회하며 동일한 레벨의 경우에는 좌에서 우로 방문한다. 이 순회 방식은 특이하게도 연결리스트로 만들어진 큐도 함께 사용한다.

  ```c
  typedef TreeNode * element; // 큐의 데이터 필드에 들어갈 값은 [treenode *]

  //큐 소스코드

  void level_order(TreeNode *ptr)
  {
    QueueType q;

    init(&q);
    if(ptr != NULL)
      return;
    enqueue(&q, ptr);
    while(!is_empty(&q)) {
      ptr = dequeue(&q);
      printf("%d", ptr->data);
      if(ptr->left)
        enqueue(&q, ptr->left);
      if(ptr->right)
        enqueue(&q, ptr->right);
    }
  }
  ```

#### cf) 트리 순회를 활용한 <u>수식 트리 계산 프로그램</u>

수식 트리의 루트 노드는 연산자이고 따라서 이 연산자의 피연산자인 서브 트리들만 계산되면 전체 수식을 계산할 수 있다. 각각의 서브 트리에서도 마찬가지로 자식 노드만 계산되면 전체 수식을 계산할 수 있다. <u>따라서 여러 가지 순회 방법중에서 가장 적합한 순회 방식은 자식 노드를 먼저 방문하는 __후위 순회__</u>라 할 수 있을 것이다. 후위 순회는 항상 자식 노드들을 먼저 방문한 다음에, 루트 노드를 방문하기 때문이다.

```c
          +
       ↙     ↘
      *        +
    ↙  ↘     ↙   ↘
   1    4   16   25
    //위의 트리를 아래 소스코드에 표현함
 ```

```c
//후위 순회를 이용한 수식 트리 계산 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode * left, * right;
} TreeNode;

TreeNode n1 = { 1, NULL,NULL };
TreeNode n2 = { 4, NULL,NULL };
TreeNode n3 = { '* ', &n1, &n2 };
TreeNode n4 = { 16, NULL,NULL };
TreeNode n5 = { 25, NULL,NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode *exp = &n7;

int evaluate(TreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);   //왼쪽 자식 노드 읽고
		int op2 = evaluate(root->right);  //오른쪽 자식 노드 읽고
		switch (root->data) {             //부모 노드 읽으니 "후위 순회"
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '* ':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

void main()
{
	printf("%d", evaluate(exp));
}
  ```
#### cf) 트리 순회를 활용한 <u>디렉터리 용량 계산</u>
위의 수식 트리 계산 프로그램과 비슷하게 "후위 순회"를 사용한다. 디렉터리 안에 두 개의 디렉터리가 각각 200KB씩 차지하고 있다고 하자. 그러면 후위 순회 방식으로 아래 두 개의 디렉터리를 먼저 계산하고, 루트 디렉터리의 용량을 계산하게 된다.
```c
//디렉터리 용량 계산 프로그램
int calc_direc_size(TreeNode *root)
{
  int left_size, right_size;
  if ( root != NULL) {
    left_size = calc_direc_size( root->left );
    right_size = calc_direc_size( root->right );
    return ( root->data + left_size + right_size);
  }
}
```

- ### 이진 트리의 연산
 - ___노드의 개수___

   모든 노드의 개수를 세어서 표시한다. 트리안의 노드 전부를 순회하는게 중요하다.
   ```c
   int get_node_count(TreeNode * node)
   {
     int count = 0;
     if(node != NULL){
       count = 1 + get_node_count(node->left) + get_node_count(node->right);
     }
     return count;
   }
   ```
 - ___단말 노드 개수 구하기___

   Q. 단말 노드(terminal node, leaf node)? A. 자식 노드가 없는 노드

   즉, left와 right 전부 NULL인 노드만 순회하며 골라내자!
   ```c
   int get_leaf_count(TreeNode * node)
   {
     int count = 0;
     if( node != NULL ){
       if( node->left == NULL && node->right == NULL ) return 1;
       else count = get_leaf_count(node->left)+
                    get_leaf_count(node->right);
     }
     return count;
   }
   ```

 - ___높이 구하기___

   개수 구하기와는 다르게 비교를 통한 최대값을 찾는 알고리즘이다.
   ```c
  int get_height(TreeNode * node)
  {
    int height = 0;
    if(node != NULL){
      height = 1 + max(get_height(node->left), get_height(node->right));
    }
    return height;
  }
   ```

## 4. 스레드 이진 트리 (threaded binary tree)
>스레드(thread) : 실

이진 트리 순회는 순환 호출을 사용하는데 __순환 호출시 우린 함수를 연속적으로 호출하므로 상당히 비효율적__ 일 수가 있다. 그러면, 순회를 순환 호출 없이, 즉 스택의 도움 없이 할 수는 없는 것일까?

이진 트리를 생각해보면 알 수 있듯 꽤 많은 NULL 링크들이 존재한다. 만일 노드의 개수가 n개라면, 각 노드당 2개의 링크를 가지므로 2n개의 링크를 가지고, 그 중 무료 절반 이상인 n+1개의 링크가 NULL 링크를 가지게 된다. 이 NULL 링크를 잘 사용하여 순환 호출 없이도 트리의 노드들을 순회할 수 있도록 하자는 것이다. 이 __NULL 링크에 중위 순회 시에 선행 노드인 중위 선행자(inorder predecessor)나 중위 순회 시에 후속 노드인 중위 후속자(inorder successor)를 저장시켜 놓은 트리가 스레드 이진 트리(threaded binary tree)이다.__ thread의 의미 그대로, <u>실로 노드들을 순회 순서대로 꿰어서 연결시켜 놓은 트리</u>를 말한다.

★우리는 중위 후속자가 NULL 링크에 저장되어있는 개념을 사용하겠다.★
### 스레드 이진 트리 구현
```c
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode * left, * right;
	int is_thread; //만약 오른쪽 링크가 스레드이면 TRUE(1)
} TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1};
TreeNode n2 = { 'B', NULL, NULL, 1};
TreeNode n3 = { 'C', &n1, &n2, 0};
TreeNode n4 = { 'D', NULL, NULL, 1};
TreeNode n5 = { 'E', NULL, NULL, 0};
TreeNode n6 = { 'F', &n4, &n5, 0};
TreeNode n7 = { 'G', &n3, &n6, 0};
TreeNode * exp = &n7;

TreeNode * find_successor(TreeNode * p)
{
	//q는 p의 오른쪽 포인터
	TreeNode * q = p->right;
	//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_thread == TRUE)
		return q;

	//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while (q->left != NULL)
		q = q->left;
	return q;
}

void thread_inorder(TreeNode * t)
{
	TreeNode * q;
	q = t;
	while (q->left != NULL)
		q = q->left; //가장 왼쪽 노드로 간다
	do
	{
		printf("%c", q->data);  //데이터 출력
		q = find_successor(q);  //후속자 함수 호출
	} while (q != NULL);		//NULL이 아니면
}

void main()
{
	//스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	//중위 순회
	thread_inorder(exp);
}
```

우선 우린 right의 값에 스레드를 세 개 넣어준다. n1, n2, n4의 right에 스레드를 넣어준다. 이 사실을 모른 채, 객관적으로 n1~n7 을 본다면, 우린 _right에 들어있는 값이 스레드인지, 진짜 오른쪽 서브트리를 가리키는 것인지 알 수가 없다._ 따라서 우린 __is_thread__ 라는 변수를 넣게 되는데 TRUE라면 중위 후속자(스레드)이며, FALSE라면 오른쪽 자식을 가리키는 포인터가 된다.

중위 순회를 따라 우린 A->C->B->G->D->F->E 순으로 순회하게 된다. 물론 스레드로 인해 순환 호출없이, 함수의 누적된 호출(스택)없이 순회할 수 있어 컴퓨터가 효율적으로 돌아갈 수 있다.
## 4. 이진 탐색 트리(binary search tree)
이진 트리 기반의 탐색(search)을 위한 자료 구조이다. 난 컴퓨터의 발생 의의가 방대한 자료의 빠른 처리에 있다고 생각하는데, 그 방대한 자료를 탐색하여 꺼내는 방식도 굉장히 중요하다고 생각한다.
### 탐색(search) 용어 분석
__Q. 탐색이란?__ A. 레코드의 집합에서 특정한 레코드를 찾아내는 작업
- __레코드__ : <군번, 이름, 주특기> 같은 필드의 집합( ex) 15-73010979, 김태윤, 운전병)
- __필드__ : 위의 군번이나 이름같은 하나의 분류 요소 ( ex) 군번, 이름, 주특기, 계급 등)
- __테이블__ : 레코드들의 집합 ( ex) <김태윤>, <대대장>, <동기1>...등등)
- __주요 키(primary key)__ : 이름이나 주특기는 겹칠 수 있다. 예를 들면, 김태윤이란 군인이 몇 십명이 중복될 수 있고, 운전병은 훨씬 많을 것이다. 하지만, 군번이 겹칠일은 절대 없다. 이런 경우, 주요 키(primary key)는 군번이다. 탐색 작업을 할 때는 이러한 키가 입력이 되어 특정한 키를 가진 레코드를 찾게 된다.

### 이진 탐색 트리 정의
- 모든 노드의 키는 유일하다.
- 왼쪽 서브 트리의 키들은 루트의 키보다 작다.
- 오른쪽 서브 트리의 키들은 루트의 키보다 크다.
- 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다.

 ___<u>★나를 기준으로 작으면 왼쪽, 크면 오른쪽으로 이동하여 탐색을 진행하면 된다!★</u>___

### 탐색 알고리즘
<u>반복적인 탐색 알고리즘</u>과 <u>순환적인 탐색 알고리즘</u> 두 개가 존재한다. 물론 개발자가 편한 알고리즘을 사용하여 탐색하면 되지만, 스레드 이진 트리에서 말했듯이 함수의 순환 호출은 곧 스택이 쌓이는 것이고, 컴퓨터가 비효율적으로 돌아가는 원인이 된다. 따라서 함수 하나에서 처리하는 것이 효율적이기 때문에 __반복적인 탐색 알고리즘을 사용하겠다.__

```c
//반복적인 탐색 알고리즘
TreeNode *Search(TreeNode *node, int key)  //key 는 primary key를 나타냄!
{
  while(node != NULL) {   //찾을 때까지 계속 반복, 끝까지 찾아도 없다면 종료!
    if(key == node->key) return node; //딱 맞는 값이 나오면 node반환 후 종료!
    else if(key < node->key) //key가 나보다 작네? 왼쪽으로 가라
      node = node->left;
    else                     //key가 나보다 크네? 오른쪽으로 가라
      node = node->right;
  }
  return NULL;
}
```
- 원하는 값을 발견하면 node반환 후 종료한다.
- 현재 탐색 중인 노드보다 key가 크면 right, 작으면 left로 이동한다.
### 이진 탐색 트리 - 삽입 연산
탐색을 진행하며 크면 right, 작으면 left로 이동하는 것은 다를 것이 없다. 다만, 마지막까지
```c
void insert_node(TreeNode **root, int key)
{
	TreeNode * p, * t; //p는 부모 노드, t는 현재 노드
	TreeNode * n;	 //n은 새로운 노드

	t = * root;  //처음엔 루트를 t에 저장
	p = NULL;	//루트는 부모가 없으므로 p에 NULL 저장

	//탐색을 먼저 수행(위에서 적은 반복 탐색 알고리즘 코드와 같음)
	while (t != NULL) {
		if (key == t->key)			//이미 존재하는 값이라면?
			return;					//insert_node함수 종료!
		p = t;						//t를 아래 레벨로 내리는 연산(↓)을 위해 작성됨
		if (key < p->key)			//나보다 작으면 left, 크면 right 이동
			t = p->left;
		else
			t = p->right;
	}//insert_node함수가 끝날 땐, 새로 들어갈 위치를 알고, 그 위치를 t에 저장하게 됨

	n = (TreeNode * )malloc(sizeof(TreeNode));  //동적할당으로 n에 메모리 할당받음
	if (n == NULL)	//동적할당 실패여부 물어봄
		return;		//동적할당 실패시, 함수 종료
	n->key = key;	//데이터 복사
	n->left = n->right = NULL;	//left, right 값을 NULL로 초기화
	if (p != NULL)	//부모노드 존재 물어봄
		if (key < p->key) //부모 있으면(들어갈 자리 찾았으면) n 노드 이어줌
			p->left = n;
		else
			p->right = n;
	else * root = n; //만일 노드가 한 개도 없는 트리일때
                     //root를 n(새로만든 노드)으로 변경
                     //즉, 새로만든 노드는 루트노드가 됨
}
```
>Q : 왜 우린 root를 매개변수로 받을 때, 더블 포인터로 받나요?
>
>A : 우리가 함수에서 매개변수를 포인터로 받는 이유는, 그 값을 함수 내에서 수정하고 싶어서이다. 함수 내에서 swap하고 싶으면 포인터로 매개변수를 받는 call by reference를 활용했던 것을 기억하자.
>
>함수 마지막에 ```* root = n;``` 을 짚고 넘어가자.
>
>root는 애초에 만들어질 때, main함수 내에서든, 전역변수로서든 ```TreeNode * root;``` 로 만들어지기 때문에, 애초부터 구조체 포인터형이다. 따라서 자연스럽게 함수에서 받을 땐, 형을 맞추기 위해 ```TreeNode * node;``` 의 형식으로 받는게 일반적이고, 여기서는 root값을 수정할 여지(그 여지가 바로 ```* root = n;```)가 있기 때문에 애스터리스트( * )을 하나 더 붙인 더블 포인터로 매개변수를 설정했다.

### 이진 탐색 트리 - 삭제 연산
트리에서 삭제하려는 노드가 있다고 하자. 그 노드는 크게 세 분류로 나눌 수 있다.
1. 삭제하려는 노드가 0개의 서브 트리를 가진다.
2. 삭제하려는 노드가 1개의 서브 트리를 가진다.
3. 삭제하려는 노드가 2개의 서브 트리를 가진다.
- - -

1. 삭제하려는 노드가 0개의 서브 트리를 가진다.즉, 단말 노드이다.

 즉 삭제하려는 노드가 단말 노드이다. 이 경우는 세 가지 경우 중 가장 간단한 경우인데, 부모와의 연결을 끊고 없애고 싶은 노드를 삭제만 하면 끝난다.


 2. 삭제하려는 노드가 1개의 서브 트리를 가진다.

 이 경우는 삭제하려는 노드의 부모도 1개이며, 삭제하려는 노드의 자식도 1개이기 때문에 부모와 자식, 즉 할아버지와 손자를 이어준다.

 3. 삭제하려는 노드가 2개의 서브 트리를 가진다.

 가장 어려운 경우로서, 삭제하려는 노드의 양 쪽에 서브 트리가 달려있는 것을 확인할 수 있다. 이때 우리는 후계자라는 개념을 도입하게된다. 왕이 죽기 전 후계자를 남길 때, 자신의 아래 자식 중에 어떤 사람을 자신의 자리에 앉히고 싶어할까? 자신과 가장 비슷한 사람을 앉혀놔야 자신의 아래에서 일하던 사람들과의 마찰이 가장 적을 것이다. 이처럼 자신과 가장 비슷한 key를 가진 노드와 자리를 바꾸고 사라지면 좋을 것이다. 자신의 서브 트리 내에서 자신과 가장 비슷한 key는 왼쪽 서브 트리에서 가장 큰 값, 혹은 오른쪽 서브 트리에서 가장 작은 값이다. 우리는 오른쪽 서브 트리에서 가장 작은 값과 바꾼다는 개념으로 코드 작성을 진행할 것이다.

 ```c
void delete_node(TreeNode **root, int key)
{
	TreeNode * p, * child, * succ, * succ_p, * t;

	p = NULL;
	t = * root;

	//t를 탐색
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < p->key) ? p->left : p->right;
	}
	//탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
	if (t == NULL) {
		printf("key is not in the tree");
		return;
	}
////////////////////////////////////////////////////////////
	//서브 트리가 0개인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)  //부모와 자식의 링크를 끊는 조건문
				p->left = NULL;
			else p->right = NULL;
		}
		else
			* root = NULL;     //트리에 노드가 단 1개인 경우
	}
////////////////////////////////////////////////////////////
	//서브 트리가 1개인 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)   //조부모와 손자를 잇는 조건문
				p->left = child;
			else
				p->right = child;
		}
		else
			* root = child;    //루트 노드를 지우는데, 루트에 서브 트리 하나일 때
	}
////////////////////////////////////////////////////////////
	//서브 트리가 2개인 경우
	else {
		succ_p = t;           //지우고 싶은 노드를 succ_p(후계자 부모)에 대입
		succ = t->right;      //succ(후계자)에 지우고 싶은 노드의 오른쪽 노드 대입

		while (succ->left == NULL) {     //계속 왼쪽으로 보낸다(가장 작은 값 탐색)
			succ_p = succ;
			succ = succ->left;
		}

		if (succ_p->left == succ)         //왼쪽으로 한 번이라도 보냈다면,
			succ_p->left = succ->right;     //후계자가 될 값의 자식을 succ_p에 붙임
		else    //else의 의미 : 지우고 싶은 노드의 바로 오른쪽 노드가 후계자가 됨
			succ_p->right = succ->right;    

		t->key = succ->key; //후계자 값을 지울 노드의 값과 바꾼다.

		t = succ; //후계자를 t에 넣는 이유 -> 아래에서 해제해서 없앨려고
	}
	free(t); 해제
}
```
