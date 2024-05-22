#include "staticStack.c"
#include <stdio.h>

void insert(STACK *pStack){
    KEY_TYPE key;
    scanf("%d", &key);
    REGISTER reg;
    reg.key = key;
    if (insertElementStack(reg, pStack))
        printf("Element %d inserted.\n", key);
    else
        printf("Not possible to insert %d.\n", key);
}

void showFirstStack(STACK *pStack){
    KEY_TYPE key;
    int position = getFirstStack(pStack, &key);
    if (position != -1) printf("First element %d found at address %d\n", key, position);
    else printf("Not possible to delete the element - empty stack.\n");
}

void delete (STACK *pStack){
  REGISTER reg;
  if(deleteElementStack(pStack, &reg)) printf("Element %d deleted.\n", reg.key);
  else printf("Not possible to delete - empty stack.\n");
}

void show(STACK *pStack){
  showStack(pStack);
}

void myLog(STACK *pStack){
  printf("Numer of elements of the stack: %d.\n",sizeOfStack(pStack));
  printf("Size of the stack (in bytes): %d.\n",sizeInBytesOfStack(pStack));
}

void help(){
  printf("Valid commands: \n");
  printf("   i <key1>: insert a element with key = key1 at the top of the Stack.\n");
  printf("   e : exclude the top of the stack.\n");
  printf("   p : print the stack.\n");
  printf("   d : destroy the stack.\n");
  printf("   l : log of stack usage.\n");
  printf("   h : show help message.\n");
  printf("   0 : show the key and the address of the top of the stack.\n");
}

void destroy(STACK *pStack){
     destruirPilha(pStack);
     printf("Stack deleted.\n");
}

int main(){
  STACK stack;
  inicializarPilha(&stack);
  help();
  char command = ' ';
  scanf("%c",&command);
  while (command != 'q'){
    switch (command) {
      case 'i' : insert(&stack); break;
      case 'e' : delete(&stack); break;
      case 'p' : show(&stack); break;
      case 'd' : destroy(&stack); break;
      case 'l' : myLog(&stack); break;
      case 'h' : help(); break;
      case '0' : showFirstStack(&stack); break;
      case 'q' : exit(0);
      default: {while (command != '\n') scanf("%c",&command);};
    } 
    scanf("%c",&command);
  }
  return 0;
}