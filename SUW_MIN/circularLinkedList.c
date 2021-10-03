#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode{ 	// 노드 타입
	element data;
	struct listNode *link;
} ListNode;

// 저장된 데이터 개수 반환
int get_size(ListNode* head) {
	ListNode* p;
	int count = 0;
	if (head == NULL) return 0;
	p = head->link;
	count++;
	while (p != head) {
		count++;
		p = p->link;
	}
	return count;
}

//특정한 값 탐색
ListNode* search(ListNode* head, element data) {
	ListNode* p;
	if (head == NULL) return NULL;
	p = head->link;
	do {
		if (p->data == data) return p;  
		p = p->link;
	} while (p != head);
	return NULL;
}

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (  p != head );
	printf("%d\n", p->data); // 마지막 노드
}
// 앞부분 삽입
ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head =  node;
		node->link = head;
	}
	else {
		node->link =  head->link;
		head->link =  node;	
	}
	return head;
}
// 뒷부분 삽입
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head =  node ;
		node->link = head;
	}
	else {
		node->link =  head->link;	
		head->link =  node;		
		head =  node;		
	}
	return head;	// 변경된 헤드 포인터 반환
}
// 메인
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}
/* 실행결과
10->20->30->40->
*/