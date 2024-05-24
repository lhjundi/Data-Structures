#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int KEY_TYPE;

typedef struct tempRegister{
    KEY_TYPE key;
    struct tempRegister * next;
    //other fields
} REGISTER;

typedef REGISTER* PTR;

//the top pointer points to the top of the stack 
//(it will be NULL if the stack is empty)
typedef struct{
    PTR top;
} STACK;

//Connected stack initialization 
//(the stack is already created and is pointed to
// by the address in pStack)
void initStack(STACK *pStack){
    pStack->top = NULL;
}

// Returns the stack size
// (number of elements)
int size(STACK *pStack){
    PTR address = pStack->top;
    int size = 0;
    while (address != NULL){
        size++;
        address = address->next;
    }
    return size;
}

// Deletes the top element from the stack and copying
// this element to the address pointed to by reg
bool deleteElemStack(STACK *pStack, REGISTER* reg){
    if( pStack->top == NULL ) return false;
    *reg = *(pStack->top);
    PTR delete = pStack->top;
    pStack->top = pStack->top->next;
    free(delete);
    return true;
}

//deletes and releases memory of all elements of the stack
bool destroyStack(STACK *pSTack){
    PTR delete;
    PTR position = pSTack->top;
    while (position != NULL){
        delete = position;
        position = position->next;
        free(delete);
    }
    pSTack->top = NULL;
    return true;
}

// stack insertion, always at the top
bool insertElemStack(REGISTER reg, STACK *pStack){
    PTR new = (PTR) malloc(sizeof(REGISTER));
    *new = reg;
    new->next = pStack->top;
    pStack->top = new;
    return true;
}