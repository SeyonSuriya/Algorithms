#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node* next;
}Node;
//struct Node *front = NULL;
//struct Node *rear = NULL;

typedef struct{
    Node *front;
    Node *rear;
}Queue;


void CreateQueue(Queue *q){
    q->front = q->rear = NULL;
}


int IsQueueEmpty(Queue *q){
    return((q->front==NULL)&&(q->rear==NULL));
}


void enqueue(int d, Queue *q) //Insert elements in Queue
{
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	n->data = d;
	n->next = NULL;
	if(IsQueueEmpty(q))
	{
		q->front = q->rear = n;
		q->rear->next = q->front;
	}
	else
	{
		q->rear->next = n;
		q->rear = n;
		n->next = q->front;
	}
}


void dequeue(Queue *q) // Delete an element from Queue
{
	Node* t;
	t = q->front;
	if(IsQueueEmpty(q))
		printf("\nQueue is Empty");
	else if(q->front == q->rear){
		q->front = q->rear = NULL;
		free(t);
	}
	else{
		q->front = q->front->next;
		q->rear->next = q->front;
		free(t);
	}


}
2d

void print(Queue *q){ // Print the elements of Queue
	Node* t;
	t = q->front;
	if(IsQueueEmpty(q))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != q->front);
	}
}



int main()
{
	int opt,n,i,data;
    Queue q;
    CreateQueue(&q);
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter your data ");
				scanf("%d",&data);
                enqueue(data,&q);
				break;
			case 2:
				print(&q);
				break;
			case 3:
				 dequeue(&q);
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");

		}
	}while(opt!=0);
return 0;
}
