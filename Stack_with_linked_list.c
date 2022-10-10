#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;

}node;

typedef struct{
    int n;
    node*top;

}stack;

void createStack(stack *s){
    s->n=0;
    s->top=NULL;

}

void push(stack *s, int x){

    node*temp;
    temp=(node*)malloc(sizeof(node));

    temp->data = x;
    if(s->top == NULL){
        temp->next = NULL;
    } else {
        temp->next = s->top;
    }
    s->top = temp;
    s->n++ ;

}

int pop(stack *s){
    int result;
    if(s->top == NULL){
        printf("Stack underflow...\n");
        return 0;
    }
    node*temp;
    result = s->top->data;
    temp = s->top;
    s->top = temp->next;
    free(temp);

    s->n--;

    return result;
}

int print(stack *s){
    if(s->top == NULL){
        printf("Stack underflow..\n");
        return 0;
    }
    printf("The stack is\n");
    node*temp = s->top;
    while(temp->next != NULL){
           printf("%d--->", temp->data);
            temp = temp->next;
    }
    printf("%d--->NULL\n\n", temp->data);
}

void main() {
    int choice, value;
    stack s;
    createStack(&s);
    printf("\nImplementaion of Stack using Linked List\n");
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(&s,value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop(&s));
            break;
        case 3:
            print(&s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}

/*
print()

combine all together with main()*/
