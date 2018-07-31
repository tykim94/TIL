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

## 3. 트리 알고리즘 (이진트리 방식)
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
 //중위 순회(inorder traversal)
 void inorder(TreeNode *root) {
    if(root){
      inorder(root->left);
      printf("%d", root->data);
      inorder(root->right);
    }
 }
 //전위 순회(preorder traversal)
 void preorder(TreeNode *root) {
   if(root){
     printf("%d",root->data);
     preorder(root->left);
     preorder(root->right);
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
