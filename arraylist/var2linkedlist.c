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
void display(List *list);
int retrieve(List *list, int index);
int locate(List *list, int data);


int main() {
    List *L = initialize();
    insertFirst(L, 1);
    insertFirst(L, 2);
    insertFirst(L, 3);
    insertFirst(L, 4);
    insertLast(L, 5);
    insertPos(L,6,3);
    deleteStart(L);
    deleteLast(L);
    locate(L,1);
    retrieve(L,2);
  

    display(L);




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
        deleteLast(list);
    }else{
    Node *current = list->head;
    for(int i=0;i<index-1;i++){
        current = current->next;
    }
    Node*trav = current->next;
    current->next = trav->next;
    free(trav);
    }
    list->count--;
        
}

void display(List *list){
    int i=0;
    Node* disp = list->head;
    while(i<list->count){
        printf("%d -> ", disp->data);
        disp = disp->next;
        i++;
    }
    printf("NULL");
}

int retrieve(List *list, int index){
    Node* temp = list->head;
    if(index > list->count-1){
        printf("Index is invalid");
    }else{
        for(int i=0;i != index ;i++){
            temp = temp->next;
        }
        printf("Index %d retrieved data is %d\n", index, temp->data);
    }    
}

int locate(List *list, int data) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }
    Node* current = list->head;
    for (int i = 0; current != NULL; i++) {
        if (current->data == data) {
            printf("Data %d found at index %d\n", data, i);
            return i;
        }
        current = current->next;
    }
    printf("Data %d is not in the list.\n", data);
    return -1;
}