#include <stdio.h>
#include <stdlib.h>

#define MAX 10   

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    int count;
} List;

List* initialize ();
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);


int main() {
    List *L = initialize();
    insertFirst(L, 5);
    insertFirst(L, 10);
    insertLast(L, 15);
    insertPos(L,5,3);
    deleteStart(L);
    deleteLast(L);


   return 0;
}

List* initialize() {
    List *L = malloc(sizeof(List));
    if (L == NULL) return NULL;
    L->head = NULL;
    L->count = 0;
    return L;
}

void insertFirst(List *list, int data) {
     Node* newnode = malloc(sizeof(Node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = list->head;
    list->head = newnode;
    list->count++;
}

void insertLast(List *list, int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if(list->head ==NULL){
        list->head = newnode;
    }
    else{
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    int i=0;
    if(index == 0){
        insertFirst(list, data);
    }else if(index == list->count){
        insertLast(list,data);
    }else{
    Node *current = list->head;
    for(int i=0;i<index-1;i++){
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
    list->count++;
    }
        
}
void deleteStart(List *list){
    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {

    if (list->head->next == NULL) {
        deleteStart(list);
        return;
    }else{
    Node *current = list->head;

    for (int i = 0; i < list->count - 2; i++) {
        current = current->next;
    }
    Node *last = current->next;
    free(last);
    current->next = NULL;
    list->count--;
    }
}
void deletePos(List *list, int index){
    int i=0;
    if(index == 0){
        deleteStart(list);
    }else if(index == list->count){
        void deleteLast(list);
    }else{
    Node *current = list->head;
    for(int i=0;i<index-1;i++){
        current = current->next;
    }
    
    }
        
}


   


