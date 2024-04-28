#include <stdio.h>

#define MAX 50
#define ERROR -1
#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef int KEY_TYPE;

typedef struct {
    KEY_TYPE key;
    //other necessary attributes...
} REGISTER;

typedef struct{
    REGISTER A[MAX+1];
    int numberOfElements;
} LIST;

//Initializes the sequential list
void initList(LIST *list){
    list->numberOfElements = 0;
}

//Shows the current sequential list
void showList(LIST *list){
    int i;
    printf("List: \" ");
    for( i = 0 ; i < list->numberOfElements; i++)
        printf("%d ", list->A[i].key);
    printf("\"\n");    
}

//Returns the valid number of valid elements
int length(LIST *list){
    return list->numberOfElements;
}

//Returns the key of a valid index from the list
//Otherwise return ERROR (-1)
int returnElementByIndex(LIST *list, int index){
    return ( index >0 && index <= list->numberOfElements)? list->A[index].key : ERROR;
}

