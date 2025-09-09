#include <stdlib.h>
#include <stdio.h>
#define LENGTH 10   

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void display(List *L);
void resize(List *L);
void insertSorted(List *L, int data);

int main() {
   List L; 
   initialize(&L);
   insertPos(&L, 1, 0);
   insertPos(&L, 2, 0);
   insertPos(&L, 3, 0);
   insertPos(&L, 4, 0);
   insertPos(&L, 5, 0);
   deletePos(&L, 1);
   if(locate(&L, 1) == -1 ){
       printf("data not found\n");
   }
   int ret = retrieve(&L, 3) ;
   if(ret == -1){
       printf("Position invalid");
    }else{
        printf("Element %d, is in position 3\n", ret);
    } 
   insertSorted(&L,6);
    insertSorted(&L, 4);
     display(&L);
    return 0;
}

void initialize(List *L){
    L->elemPtr = malloc(sizeof(int)*LENGTH);
    L->count = 0;
    L->max =LENGTH; 
    
}

void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }
      if (L->count == L->max) {

    }
    for (int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->count--;
}
int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elemPtr[i] == data) {
            printf("Data %d, found at index %d\n", data, i);
            return 1;
        }
    }
   return -1;
}
int retrieve(List *L, int position){
    if(position < 0 || position >= L->count){
        return -1; 
    }
    return L->elemPtr[position];
}

void display(List *L){
    for(int i=0;i<L->count;i++){
        printf("%d ",L->elemPtr[i]);
    }
}
void resize(List *L) {
    int newSize = L->max * 2;
    int *newArr = realloc(L->elemPtr, sizeof(int) * newSize);
    if (newArr == NULL) {
        printf("Reallocation failed!\n");
        exit(1);
    }
    L->elemPtr = newArr;
    L->max = newSize;
}
void insertSorted(List *L, int data) {
    if (L->count == L->max) {
        resize(L);
    }
    int i = L->count - 1;
    while (i >= 0 && L->elemPtr[i] < data) {
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}






