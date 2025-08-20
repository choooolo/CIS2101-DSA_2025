#include <stdio.h>
#define size 10

typedef struct {
    int elem[size];
    int count;
}List;
List initialize (List L);
void display(List L);
List insertPos (List L, int data, int position);
List deletePos(List L, int position);
int locate (List L, int data);
List insertSorted (List L, int data);


int main(){
    List L;
    L = initialize(L);
    
    L.elem[0] = 1;
    L.elem[1] = 2; 
    L.elem[2] = 3; 
    L.count = 3;
    L =insertPos (L,10, 5);
    L =insertPos (L,20, 5);
    L =deletePos(L, 2);
    L = insertSorted (L, 5);
    display(L);
    printf("Count is: %d\n", L.count);
    locate (L, 20);
}
List initialize (List L){
    L.count =0;
    for(int i=0;i<size;i++){
        L.elem[i] = -1;

    }
    return L;
}
List insertPos (List L, int data, int position){
    if(L.elem[position] == -1){
        L.count++;
    }
    L.elem[position] = data;
    
    return L;
}
List deletePos(List L, int position){
    if(L.elem[position] != -1){
        L.count--;
    }
    L.elem[position] = -1;
    return L;
}
int locate (List L, int data){
    int i;
    for(i=0;i<size;i++){
        if(L.elem[i] == data){
            printf ("The data location of %d is in elem[%d]", data, i);
        }
    }
    return i;
}
List insertSorted (List L, int data){
    for (int i = 0; i<size;i++){
        for(int j = i+1;j<size;j++){
            if(L.elem[i] < L.elem[j]){
                int temp;
                L.elem[j] = temp;
                L.elem[i] = L.elem[j];
                temp = L.elem[i];
            }
        }
    }

}


void display(List L){
    for(int i=0;i<size;i++){
        printf("elem [%d] = %d\n", i, L.elem[i]);
    }
}