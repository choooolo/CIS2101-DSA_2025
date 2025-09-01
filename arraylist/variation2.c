#include <stdio.h>
#include <stdlib.h>

#define MAX 10   // maximum number of elements in the list

// Define the structure for the list
typedef struct {
    int elem[MAX];   // array to hold elements
    int count;       // number of actual elements
} Etype, *EPtr;

// Function prototypes
void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

// Main program for testing
int main() {
    // Allocate memory for the list
    EPtr L = (EPtr) malloc(sizeof(Etype));
    
    initialize(L); // Start with an empty list

    // Insert elements
    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);

    printf("Initial List: ");
    display(L);

    insertPos(L, 4, 2); // Insert at position 2
    printf("After insertPos(L, 4, 2): ");
    display(L);

    deletePos(L, 1); // Delete element at position 1
    printf("After deletePos(L, 1): ");
    display(L);

    printf("Locate 5: %d\n", locate(L, 5));
    printf("Retrieve position 2: %d\n", retrieve(L, 2));

    insertSorted(L, 8);
    printf("After insertSorted(L, 8): ");
    display(L);

    makeNULL(L); // Free memory
    return 0;
}

// Functions Implementation

// Initialize the list
void initialize(EPtr L) {
    L->count = 0;
}

// Insert element at a specific position
void insertPos(EPtr L, int data, int position) {
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

// Delete element from a specific position
void deletePos(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

// Locate the position of an element
int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i;
        }
    }
    return -1; // not found
}

// Retrieve element at a specific position
int retrieve(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

// Insert element into a sorted list
void insertSorted(EPtr L, int data) {
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }
    int pos = 0;
    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }
    insertPos(L, data, pos);
}

// Display elements of the list
void display(EPtr L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

// Free memory of the list
void makeNULL(EPtr L) {
    free(L);
}
