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

void initStack(STACK *pStack);
int size(STACK *pStack);
boolean insertElemStack(REGISTER reg, STACK *pStack);
boolean deleteElemStack(STACK *pStack, REGISTER* reg);
boolean destroyStack(STACK *pStack);

#endif