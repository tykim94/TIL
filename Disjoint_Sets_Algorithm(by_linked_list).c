#include <stdio.h>
#include <stdlib.h>

typedef struct DATA {
	char ch;
	struct DATA *head;
	struct DATA *next;
}DATA;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(DATA **ptail, DATA *newDATA)
{
	if (*ptail == NULL)
	{
		*ptail = newDATA;
		newDATA->head = newDATA;
	}
	else
	{
		(*ptail)->next = newDATA;
		newDATA->head = (*ptail)->head;  //origin -> tailhead로 수정함
		*ptail = newDATA;
	}
}

void display(DATA *tail)
{
	DATA *p = tail->head;
	while (p != NULL) {
		printf("%c->", p->ch);
		p = p->next;
	}
	printf("\n");
}

void display_addr(DATA *tail)
{
	DATA *p = tail->head;
	while (p != NULL) {
		printf("%x\n", p->head);
		p = p->next;
	}
	printf("\n");
}

//concat_node(벽, 액자)
DATA *concat_node(DATA *tail1, DATA *tail2)
{	
	DATA *p;
	if (tail1 == NULL)
		return tail2;
	else if (tail2 == NULL)
		return tail1;
	else {
		p = (*tail1).head;
		while (p->next != NULL)
			p = p->next;
		p->next = tail2->head;

		p = (*tail2).head;
		p->head = (*tail1).head;

		while (p->next != NULL)
		{
			p = p->next;
			p->head = (*tail1).head;
		}
	
		return tail1;
	}
}


DATA *create_node(char newchar)
{
	DATA *new_node;
	new_node = (DATA*)malloc(sizeof(DATA));

	if (new_node == NULL)
		error("메모리 할당 에러");
	new_node->ch = newchar;
	new_node->head = NULL;
	new_node->next = NULL;

	return(new_node);
}


void main()
{
	DATA *list1 = NULL, *list2 = NULL;

	insert_node(&list1, create_node('a'));
	insert_node(&list1, create_node('b'));
	insert_node(&list1, create_node('c'));
	display(list1);
	display_addr(list1);

	insert_node(&list2, create_node('d'));
	insert_node(&list2, create_node('e'));
	insert_node(&list2, create_node('f'));
	insert_node(&list2, create_node('g'));
	insert_node(&list2, create_node('h'));
	display(list2);
	display_addr(list2);

	list2 = concat_node(list2, list1);
	display(list2);

	display_addr(list2);

}

















//typedef int element;
//typedef struct ListNode {
//	element data;
//	struct ListNode *link;
//}ListNode;
//
////오류 처리 함수
//void error(char *message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//
//void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
//{
//	if (*phead == NULL) {
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else if (p == NULL) {
//		new_node->link = *phead;
//		*phead = new_node;
//	}
//	else {
//		new_node->link = p->link;
//		p->link = new_node;
//	}
//}
//
//void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
//{
//	if (p == NULL)
//		*phead = (*phead)->link;
//	else
//		p->link = removed->link;
//	free(removed);
//}
//
//void display(ListNode *head)
//{
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//ListNode *search(ListNode *head, int x)
//{
//	ListNode *p;
//	p = head;
//	while (p != NULL) {
//		if (p->data == x)
//			return p;
//		p = p->link;
//	}
//	return p;
//}
//
//ListNode *concat(ListNode *head1, ListNode *head2)
//{
//	ListNode *p;
//	if (head1 == NULL)
//		return head2;
//	else if (head2 == NULL)
//		return head1;
//	else {
//		p = head1;
//		while (p->link != NULL)
//			p = p->link;
//		p->link = head2;
//		return head1;
//	}
//}
//
//ListNode *reverse(ListNode *head)
//{
//	ListNode *p, *q, *r;
//	p = head;
//	q = NULL;
//	while (p != NULL) {
//		r = q;
//		q = p;
//		p = p->link;
//		q->link = r;
//	}
//	return q;
//}
//
//ListNode *create_node(element data, ListNode *link)
//{
//	ListNode *new_node;
//	new_node = (ListNode *)malloc(sizeof(ListNode));
//	if (new_node == NULL)
//		error("메모리 할당 에러");
//	new_node->data = data;
//	new_node->link = link;
//	return(new_node);
//}
//
//void main()
//{
//	ListNode *list1 = NULL, *list2 = NULL;
//	ListNode *p;
//
//	//list1 삽입
//	insert_node(&list1, NULL, create_node(10, NULL));
//	insert_node(&list1, NULL, create_node(20, NULL));
//	insert_node(&list1, NULL, create_node(30, NULL));
//	display(list1);
//
//	//list1 맨 앞 노드 삭제
//	remove_node(&list1, NULL, list1);
//	display(list1);
//
//	//list2 삽입
//	insert_node(&list2, NULL, create_node(60, NULL));
//	insert_node(&list2, NULL, create_node(70, NULL));
//	insert_node(&list2, NULL, create_node(80, NULL));
//	display(list2);
//
//	//list1 + list2
//	list1 = concat(list1, list2);
//	display(list1);
//
//	//list1 뒤집기
//	list1 = reverse(list1);
//	display(list1);
//
//	//list1 탐색
//	p = search(list1, 20);
//	printf("탐색 성공: %d\n", p->data);
//}