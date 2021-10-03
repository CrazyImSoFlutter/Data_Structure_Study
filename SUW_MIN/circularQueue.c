#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct queueType{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void init_queue(QueueType *q){
    q->front = q->rear = -1;
}

int is_Empty(QueueType *q){
    return (q->front ==  q->rear);
}

int is_Full(QueueType *q){
    return (q->rear)-(q->front)>=MAX_QUEUE_SIZE;
}
void print_queue(QueueType *q){
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_Empty(q)){
        int i = q->front;
        do{
            i=(i%MAX_QUEUE_SIZE)+1;
            printf("%d | ", q->data[i]);
        }while(i != (q->rear % MAX_QUEUE_SIZE));
        //printf("%d", q->data[(q->rear % MAX_QUEUE_SIZE)]);
    }
    printf("\n");
}

void enqueue (QueueType *q, element item){
    if(is_Full(q)){
        printf("overflow!\n");
        return;
    }
    q->rear++;
    q->data[(q->rear)%MAX_QUEUE_SIZE]=item;
}

void dequeue(QueueType *q, element * item){
    if(is_Empty(q)){
        printf("underflow!\n");
        return;
    }
    q->front++;
    *item=q->data[(q->front)%MAX_QUEUE_SIZE];
}

int main(void){
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
	while (!is_Full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf("%d",  &element);
		enqueue(&queue, element);
		print_queue(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_Empty(&queue))
	{
		dequeue(&queue, &element);
		printf("꺼내진 정수: %d \n", element);
		print_queue(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}