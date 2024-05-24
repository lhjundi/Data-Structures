#ifndef T_STACK_H
#define T_STACK_H
#define true 1
#define false 0

typedef int KEY_TYPE;
typedef int boolean;

typedef struct tempRegister {
    KEY_TYPE key;
    struct tempRegister *next;
} REGISTER;

typedef REGISTER* PTR;

//the top pointer points to the top of the stack 
//(it will be NULL if the stack is empty)
typedef struct {
    PTR top;
} STACK;

//Connected stack initialization 
//(the stack is already created and is pointed to
// by the address in pStack)
void initStack(STACK *pStack);

// Returns the stack size
// (number of elements)
int size(STACK *pStack);

// stack insertion, always at the top
boolean insertElemStack(REGISTER reg, STACK *pStack);

// Deletes the top element from the stack and copying
// this element to the address pointed to by reg
boolean deleteElemStack(STACK *pStack, REGISTER* reg);

//deletes and releases memory of all elements of the stack
boolean destroyStack(STACK *pStack);

#endif