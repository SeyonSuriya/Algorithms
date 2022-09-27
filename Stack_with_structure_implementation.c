#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef enum{TRUE,FALSE } Boolean;

typedef struct {
    int top;
    char stack_array[MAX];
}stack;

void createStack(stack *s){
    s->top = -1;
}


Boolean isStackEmpty(stack *s){
    return (s->top == -1);
}


Boolean isStackFull(stack *s){
    return (s->top == MAX-1);
}


void push(char item,stack *s){
    if(isStackFull(s)){
        printf("Stack overflow...Unable to add element %c\n",item);
        return;
    }
    s->top = s->top +1;
    s->stack_array[s->top] = item;
    printf("Element %c added to the stack..\n",item);
}

void pop(stack *s){
    if(isStackEmpty(s)){
        printf("Stack underflow...\n");
        return;
    }
    char value = s->stack_array[s->top];
    s->top = s->top - 1;
    printf("Element %c removed..\n",value);
}


void print(stack *s){
    printf("\nElements in the stack: ");
    for(int i=s->top; i >= 0; i--){
        printf("%c ",s->stack_array[i]);
    }
}


void main(){
    stack s;
    stack p;
    createStack(&s);
    push('m',&s);
    push('e',&s);
    push('y',&s);
    push('o',&s);
    push('n',&s);
    pop(&s);
    print(&s);
    printf("\n\n");

    createStack(&p);
    push('s',&p);
    push('e',&p);
    push('y',&p);
    push('o',&p);
    push('n',&p);
    pop(&p);
    print(&p);
}