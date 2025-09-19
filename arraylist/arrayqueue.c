#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int count;
}List;
typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
bool isEmpty(Queue* q);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
int main(){
    Queue* Q = initialize();
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);
    enqueue(Q, 60);
    enqueue(Q, 70);
    
    printf("%d", dequeue(Q));
    int fronter = front(Q);
    printf("\n%d", fronter);
    printf("\n");display(Q);
   
    return 0;
}
Queue* initialize(){
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear= -1;
    q->list.count = 0;
    return q;
    
}

bool isFull(Queue* q){
    return q->list.count == MAX;
}
 
bool isEmpty(Queue* q){
    return q->list.count == 0;
}  

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
        }else{
            q->rear =(q->rear + 1) % MAX;
        }
        q->list.items[q->rear] = value;
        q->list.count++;
    }
}
int dequeue(Queue* q){
    if(!isEmpty(q)){
        int front = q->list.items[q->front];
        q->front = (q->front + 1) % MAX;
        q->list.count--;
        return front;
    }
}

int front(Queue* q){
    if(!isEmpty(q)){
        return q->list.items[q->front];
    }
}
void display(Queue* q){
    if(!isEmpty(q)){
        while(q->front != q->rear + 1){
            printf("%d -> ", q->list.items[q->front]);
            q->front++;
        }
    }
}


