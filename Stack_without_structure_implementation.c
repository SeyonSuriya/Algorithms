#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef enum{TRUE,FALSE} Boolean;
int stack_arr[MAX];
int top = -1;

Boolean isStackfull(){
    return (top == MAX-1);
}

Boolean isStackempty(){
    return (top == -1);
}

void push(int data){
    if(isStackfull()){
        printf("Stack overflow...Unable to add element %d\n",data);
        return;
    }
    top = top+1;
    stack_arr[top] = data;
    printf("Element %d added to the stack..\n",data);
}

void pop(){
    int value;
    if(isStackempty()){
        printf("Stack underflow...");
        return;
    }
    value = stack_arr[top];
    top = top-1;
    printf("Element %d reomoved from stack\n",value);
}

void print(){
    int i;
    if(isStackempty()){
        printf("Stack underflow...No elements in the stack.\n");
        return;
    }
    printf("\nElements in the stack: ");
    for(i=top; i>=0; i--)
        printf("%d ",stack_arr[i]);
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    print();
    return 0;
}