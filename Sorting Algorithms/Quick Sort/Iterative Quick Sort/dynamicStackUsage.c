#include "dynamicStack.c"
#include <stdio.h>

void insert(STACK *pStack){
    KEY_TYPE key;
    scanf("%d", &key);
    REGISTER reg;
    reg.key = key;
    if(insertElemStack(reg, pStack)) printf("Element %d inserted.\n", key);
    else printf("Not possible to add %d.\n", key);
}

void showTop(STACK *pStack){
    KEY_TYPE key;
    PTR position = getTopElem(pStack, &key);
    if (pStack != NULL) printf("Element %d found at address %d.\n", key, position);
    else printf("Not possible to find any element (empty stack). \n");
}

void delete(STACK *pStack){
    REGISTER temp;
    if (deleteElemStack(pStack, &temp)) printf("Element %d deleted", temp.key);
    else printf("Not possibel to delete (empty stack).\n");
}

void show(STACK*pStack){
    showStack(pStack);
}

void destroy(STACK *pStack){
    destroyStack(pStack);
    printf("Stack cleaned");
}

void myLog(STACK *pStack){
    printf("Number of elements in the stack: %d.\n", size(pStack));
    printf("Size of the stack in bytes: %d.\n", sizeInBytes(pStack));
}

void help(){
    printf("    i <key1>: inset element with key = key1\n");
    printf("    e : exclude top of the stack\n");
    printf("    p : printf stack\n");
    printf("    d : destroy stack\n");
    printf("    l : log exhibition of the stak\n");
    printf("    h : show help message\n");
    printf("    0 : show the key and the address of the first element\n");
    printf("    q : quit\n");
}

int main(){
    STACK stack;
    initStack(&stack);

    char command = ' ';
    scanf("%c", &command);
    while (command != 'q'){
        switch (command){
            case 'i' : insert(&stack); break;
            case 'e' : delete(&stack); break;
            case 'p' : show(&stack); break;
            case 'd' : destroy(&stack); break;
            case 'l' : myLog(&stack); break;
            case 'h' : help(&stack); break;
            case '0' : showTop(&stack); break;

            default: {
                while (command != '\n')
                    scanf("%c", &command);               
            }
            scanf("%c", &command);
        }
        return 0;
    }
}