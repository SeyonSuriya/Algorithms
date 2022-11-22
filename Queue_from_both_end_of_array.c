#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 20
#define TRUE 1
#define FALSE 0

typedef char QueueElement;

typedef struct DoubleQueue{
    int countA;
    int countB;
    int rearA;
    int rearB;
    QueueElement items[MAXQUEUE];
} DoubleQueue;

void CreateDoubleQueue (DoubleQueue *q){
    q->countA=0;
    q->countB=0;
    q->rearA=-1;
    q->rearB=MAXQUEUE;
}

//Queue A begins from the left end of the array
//Queue B begins from the right end of the array

int IsEmpty (DoubleQueue *q) {
    if(q->countA + q->countB == 0)
        return(TRUE);
    else
        return(FALSE);  
}

int IsFull(DoubleQueue *q){
    if(q->countA + q->countB == MAXQUEUE )
        return(TRUE);
    else
        return(FALSE);
}

void insertA(DoubleQueue *q, QueueElement x){
    if(IsFull(q)){
        printf("Queue is full...\n");
        exit(1);
    }

    q->rearA++;
    q->items[q->rearA]=x;
    q->countA++;
}

void insertB(DoubleQueue *q, QueueElement x){
    if(IsFull(q)){
        printf("Queue is full...\n");
        exit(1);
    }

    q->rearB--;
    q->items[q->rearB]=x;
    q->countB++;
}

void RemoveA(DoubleQueue *q, QueueElement *x){
    if(IsEmpty(q)){
        printf("Queue is empty...\n");
        exit(1);
    }

    *x = q->items[0];
    q->rearA--;
    q->countA--;

    int i=1;
    while(i<= q->rearA){
        q->items[i-1] = q->items[i];
        i++;
    }
}

void RemoveB(DoubleQueue *q, QueueElement *x){
    if(IsEmpty(q)){
        printf("Queue is empty...\n");
        exit(1);
    }

    *x = q->items[MAXQUEUE-1];
    q->rearB++;
    q->countB--;

    int i=MAXQUEUE-1;
    while(i >= q->countB){
        q->items[i] = q->items[i-1];
        i--;
    }
}

