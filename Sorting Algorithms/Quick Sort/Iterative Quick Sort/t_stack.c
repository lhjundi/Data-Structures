#include<stdio.h>
#include<stdlib.h>
#include "t_stack.h"

void initStack(STACK *pStack){
    pStack->top = NULL;
}

int size(STACK *pStack){
    PTR address = pStack->top;
    int size = 0;
    while (address != NULL){
        size++;
        address = address->next;
    }
    return size;
}

boolean deleteElemStack(STACK *pStack, REGISTER* reg){
    if( pStack->top == NULL ) return false;
    *reg = *(pStack->top);
    PTR delete = pStack->top;
    pStack->top = pStack->top->next;
    free(delete);
    return true;
}

boolean destroyStack(STACK *pSTack){
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

boolean insertElemStack(REGISTER reg, STACK *pStack){
    PTR new = (PTR) malloc(sizeof(REGISTER));
    *new = reg;
    new->next = pStack->top;
    pStack->top = new;
    return true;
}