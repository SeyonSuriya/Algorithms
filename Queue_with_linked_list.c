#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 50

typedef enum{FALSE,TRUE} Boolean;

typedef struct node{
    char entry;
    struct node *next;
}Node;

typedef struct{
    int count;
    Boolean full;
    Node *front;
    Node *rear;
}Queue;

void CreateQueue(Queue *q)
{
    q->count=0;
    q->full= FALSE;
    q->front=q->rear=NULL;

}



int IsQueueEmpty(Queue *q)
{
   return (q->front==NULL && q->rear==NULL);

}


int IsQueueFull(Queue *q)
{
    return (q->full);

}


void Remove(char *x,Queue *q)
{
    Node *np;
    if(IsQueueEmpty(q))
       {
          printf("Cannot remove from empty queue...");
          exit(1);
       }

    else
    {
        q->count--;
        *x=q->front->entry;
        np=q->front;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
        free(np);
    }

}


void Insert( char x,Queue *q)
{
   Node *np;
   np=(Node *)malloc(sizeof(Node));
   if(np==NULL)
   {
       printf("Not enough memory...");
       q->full=TRUE;
   }
   else
   {
       np->entry=x;
       
       np->next=NULL;
       if(IsQueueEmpty(q)){
            q->front = np;
            q->rear = np;
       } 
       else{
            q->rear->next = np;
            q->rear = np;
       }
       q->count++;
   }

}


int QueueSize(Queue *q)
{
    return (q->count);
}

void printQueue(Queue *q){
    Node *np = q->front;
    while(np->next != NULL){
        printf("%c--->",np->entry);
        np = np->next;
    }
    printf("%c-->NULL",np->entry);
}



int main()
{   Queue q; char c;

    CreateQueue(&q);
    /*char str[]="This is an example using queue";
    printf("The string is:\n%s",str);

    for(int i=0; str[i]!='\0';i++){
        if(!IsQueueFull(&q)){
            Insert(str[i],&q);
        }
    }
    printf("\n\nThe String from the queue:\n");
    while(!IsQueueEmpty(&q)) {
        Remove(&c,&q);
        putchar(c);
    }

    printf("\n");*/
    
    Insert('s',&q);
    Insert('e',&q);
    Insert('y',&q);
    Insert('o',&q);
    Insert('n',&q);
    //Insert('s',&q);
    //Remove(&c,&q);
    printQueue(&q);

    return 0;

}
