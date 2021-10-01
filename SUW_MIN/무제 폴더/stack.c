#include <stdio.h>
#include <stdlib.h>//exit
#include <conio.h> //getch

#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)
#pragma warning(disable : 6031)
#pragma warning(disable : 6011)

//---------------------------------------------------------------------------------------------//struct
typedef struct Node
{
	int val;				//정수형 데이터
	struct Node* pNext;		//다음 노드의 위치를 기억하는 포인터
}NODE;
//---------------------------------------------------------------------------------------------//declare function
void insertNodeFront();		//리스트 시작에 노드 추가
void insertNodeRear();		//리스트에 끝에 노드 추가
void printList();			//리스트 출력
void unInitList();			//동적 할당된 연결리스트 해제

//---------------------------------------------------------------------------------------------//main

NODE* head = NULL; //연결리스트의 시작 주소를 기억하는 포인터(전역변수)

int main()
{
	int choice;

	while (1)
	{
		system("cls");
		printf("*** 메뉴선택 ***\n\n");
		printf("1. 입    력\n");
		printf("2. 출    력\n");
		printf("0. 종    료\n");
		printf("메뉴선택 : [ ]\b\b");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertNodeFront(); //리스트 시작에 노드 삽입
			//insertNodeRear(); //리스트 끝에 노드 삽입
			break;
		case 2: printList(); break;
		case 0: unInitList(); exit(0);
		}

		printf("\n\n\t\t계속 하려면 아무키나 누르세요");
		_getch();
	}

	return 0;
}

//-------------------------------------------------------------//연결 리스트 시작에 원소 삽입(시간 복잡도 : O(1))
void insertNodeFront() 
{
	NODE* newNode;

	newNode = (NODE*)malloc(sizeof(NODE));

	printf("\n\n정수 입력 : ");
	scanf("%d", &newNode->val);
	newNode->pNext = NULL;

	newNode->pNext = head;
	head = newNode; //새 노드를 head로 설정
	printf("\n\n\t\t리스트 시작에 노드 삽입.\n");
}

//-------------------------------------------------------------//연결 리스트 끝에 원소 삽입(시간 복잡도 : O(n))
void insertNodeRear()
{
	NODE* newNode, *curNode;

	newNode = (NODE*)malloc(sizeof(NODE));

	printf("\n\n정수 입력 : ");
	scanf("%d", &newNode->val);
	newNode->pNext = NULL;

	if (head == NULL) //연결리스트가 처음 연결될때
	{
		head = newNode;
		printf("\n\n\t\t연결리스트가 처음 연결됐습니다.\n");
	}
	else
	{
		curNode = head;
		while (curNode->pNext != NULL) //노드의 마지막까지 이동
			curNode = curNode->pNext;

		curNode->pNext = newNode; //마지막 노드에 새 노드 연결

		printf("\n\n\t\t리스트 끝에 노드 삽입.\n");
	}
}
 
//-------------------------------------------------------------//리스트 순회하며 저장된 값 출력(시간 복잡도 : O(n))
void printList()
{
	NODE* curNode;

	if (head == NULL)
	{
		printf("\n\n\t\t연결리스트가 비어 있습니다.\n");
		return;
	}

	printf("\n\n********* PRINT ***********\n");
	curNode = head;
	while (curNode->pNext != NULL)
	{
		printf("%d -> ", curNode->val);
		curNode = curNode->pNext;
	}
	printf("%d\n", curNode->val);
}

//-------------------------------------------------------------//리스트 순회하며 동적 할당된 노드 삭제(시간 복잡도 : O(n))
void unInitList()
{
	NODE* delNode;

	if (head == NULL) return;
	
	while (head->pNext != NULL)
	{
		delNode = head; //첫번째 노드를 삭제할 노드로 지정
		head = head->pNext; //삭제할 다음 노드를 head로 잡는다.
		free(delNode);
		printf("동적 메모리가 해제\n");
	}
	free(head); //마지막 노드 삭제
	printf("동적 메모리가 해제\n");
}