#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int top;
}Stack;
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);    
void push(Stack* s, int value);
int peek(Stack* s);
int pop(Stack* s);
int top(Stack *s);
void display(Stack* s);
void sortStack(Stack* s);

int main(){
    Stack* s = initialize();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    pop(s);
    display(s);
    sortStack(s);
    printf("\n");
    display(s);
    

    return 0;
}
Stack* initialize(){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s){
    return s->top == MAX - 1;

}
bool isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s, int value){
    if(!isFull(s)){
        s->top++;
        s->elem[s->top] = value;
    }
}
int pop(Stack* s){
     if (!isEmpty(s)) {
        return s->elem[s->top--];  
    }
}

int peek(Stack* s){
    if(!isEmpty(s)){
        int top = s->elem[s->top];
        return top;
    }
}
int top(Stack *s){
    int topp =  s->elem[s->top];
    return topp;
}

void display(Stack* s){
    Stack* temp = malloc(sizeof(Stack));
    temp->top = -1;
    for(int i=s->top;i>=0;i--){
        printf("%d -> ", s->elem[s->top]);
        push(temp, s->elem[s->top]);
        pop(s);
    }
    for(int i=temp->top;i>=0;i--){
       push(s,temp->elem[temp->top]);
       pop(temp);
    }
    free(temp);
}
void sortStack(Stack* s) {
    Stack aux;
    aux.top = -1;   // ✅ fixed (properly initialize local stack)

    while (!isEmpty(s)) {
        int temp = pop(s);

        // Move elements from aux back to s if they are greater than temp
        while (!isEmpty(&aux) && peek(&aux) > temp) {
            push(s, pop(&aux));
        }

        // Insert temp into correct position in aux
        push(&aux, temp);
    }

    // Copy sorted elements back into original stack
    while (!isEmpty(&aux)) {
        push(s, pop(&aux));
    }
}
