#include <stdio.h>
#define ERROR -1
#define true 1
#define false 0
#define MAX 50

typedef int bool;
typedef int KEY_TYPE;

typedef struct {
    KEY_TYPE key;
} REGISTER;

typedef struct {
    int top;
    REGISTER A[MAX];
} STACK;

//Stack initialization
void initStack(STACK *pStack){
    pStack -> top = -1;
}

// Returns the number of elements in the stack  
int sizeOfStack(STACK *pStack){
    return pStack->top + 1;
}

// Shows the current state of the stack 
// (of ints, adjust in printf others types)
void showStack(STACK *pStack){
    printf("Stack: \" ");
    for (int i = pStack->top; i >= 0; i--)
        printf("%d ", pStack -> A[i].key);
    printf("\"\n");
}

// Returns the size in bytes of the stack
int sizeInBytesOfStack(STACK * pStack){
    return sizeof(STACK);
}

// Returns the position of the first element of the stack
int searchStack(STACK * pStack){
    initStack(pStack);
    return pStack ->top;
}

// Stack destruction
void destroyStack(STACK *pStack){
    initStack(pStack);
}

// Inserts an element at the end of the stack
bool insertElementStack(REGISTER reg, STACK* pStack){
    if (pStack -> top +1 >= MAX) return false;
    pStack -> top = pStack -> top + 1;
    pStack -> A[pStack -> top] = reg;
    return true;
}

// Returns and delete the first element of the stack
// Returns false if there is no element to remove
bool deleteElementStack(STACK* pStack, REGISTER* reg){
    if(pStack -> top == -1) return false;
    *reg = pStack->A[pStack->top];
    pStack -> top = pStack->top -1;
    return true;
}

// returns the position of the first (top) element of the stack
// and the value of its key in the content of the key address. 
// Returns -1 if the list is empty */
int getFirstStack(STACK *pStack, KEY_TYPE* key){
    if (pStack->top == -1) return -1;
    *key = pStack->A[pStack -> top].key;
    return pStack -> top;
}
