#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 50
#define TRUE 1
#define FALSE 0

typedef struct queue{
    int count;
    int front;
    int rear;
    char items[MAXQUEUE];
}Queue;

void CreateQueue(Queue *q) {
    q->count=0;
    q->front=-1;
    q->rear=-1;

}



int IsQueueEmpty(Queue *q) {
    if(q->count==0)
        return (TRUE);
    else
        return (FALSE);
}


int IsQueueFull(Queue *q)
{
    if(q->rear==MAXQUEUE-1)
        return (TRUE);
    else
        return (FALSE);
}


void Remove(char *x,Queue *q) {
    if(IsQueueEmpty(q))
    {
        printf("Queue is empty...\n");
        exit(1);
    }
    else
    {
        *x=q->items[q->front];
        q->front++;
        q->count--;
    }

}


void Insert( char x,Queue *q)
{
    if(IsQueueFull(q))
    {
        printf("Queue is full... \n");
        exit(1);
    } else {
        if(q->front==-1){
            q->front=0;
        }
        q->rear++;
        q->items[q->rear]=x;
        q->count++;
    }

}


int QueueSize(Queue *q)
{
    return (q->count);
}



int main() {   Queue q; char c;

    CreateQueue(&q);
    char str[]="This is an example using stacks";
    printf("The string is:\n%s",str);

    for(int i=0; str[i]!='\0';i++) {
        if(!IsQueueFull(&q)) {
            Insert(str[i],&q);
        }

    }
    printf("\n\nThe String from the stack:\n");
    while(!IsQueueEmpty(&q)) {
        Remove(&c,&q);
        putchar(c);
    }

    printf("\n");

    return 0;

}
