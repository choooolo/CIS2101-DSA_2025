#include <stdio.h>
#define size 10

typedef struct {
    int elem[size];
    int count;
}EType,*EPtr;

void initialize(EPtr L);


int main(){
    EType K;
    EPtr L;
    L = &K;
    initialize(L);
    printf("What the fuck");
    return 0;
}

void initialize(EPtr L){
    
}