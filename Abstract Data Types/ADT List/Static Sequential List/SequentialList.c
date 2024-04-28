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
KEY_TYPE getElementByIndex(LIST *list, int index){
    return ( index >0 && index <= list->numberOfElements)? list->A[index].key : ERROR;
}

boolean isEmpty(LIST *list){
    return (list->numberOfElements > 0)? TRUE : FALSE;
}

KEY_TYPE getFirstElement(LIST *list){
    return (isEmpty(list))? ERROR : list->A[0].key;
}

KEY_TYPE getLastElement(LIST *list){
    return (isEmpty(list))? ERROR : list->A[length(list)-1].key;
}

void destroyList(LIST *list){
    list->numberOfElements = 0;
}

boolean isFull(LIST *list){
    return (list->numberOfElements >= MAX)? FALSE : TRUE;
}

boolean insertElement(REGISTER reg, int i, LIST *list){
    int j;
    if( isFull(list) || (i < 1) || (i > ( list->numberOfElements + 1 ))){
        return FALSE;
    }
    if( list->numberOfElements > 0 && i < list->numberOfElements+1 )
        for( j = list->numberOfElements; j >= i ; j--)
            list->A[j] = list->A[j-1];
    list->A[i-1] = reg;
    list->numberOfElements++;
    return TRUE;
}

int linearSearch(KEY_TYPE key, LIST *list){
    int i = 0;
    while( i < list->numberOfElements){
        if( key == list->A[i].key )
            return i;
        i++; 
    }
    return ERROR;
}

int SentinelSearch(KEY_TYPE key, LIST *list){
    int i = 0;
    list->A[list->numberOfElements].key = key;
    while( list->A[i].key != key ) i++;
    if( i > list->numberOfElements -1 ) return ERROR;
    return i;
}

int BinarySearch(KEY_TYPE key, LIST *list){
    int left, right, middle;
    left = 0;
    right = list->numberOfElements-1;
    while( left <= right ){
        middle = (left + right) / 2;
        if (list->A[middle].key ==key) return middle;
        else{
            if( list->A[middle].key < key ) left = middle + 1;
            else right = middle -1;
        }
    }
    return ERROR;
}

boolean insertElementSortedList(REGISTER reg, LIST *list){
    int i;
    KEY_TYPE key = reg.key;
    if ( isFull(list)) return FALSE;
    list->A[list->numberOfElements].key = key;
    while( list->A[i].key < key ) i++;
    if(list->A[i].key == key && i < list->numberOfElements)
        return FALSE;
    else
        return insertElement(reg, i+1, list);
}

boolean deleteElement(KEY_TYPE key, LIST *list){
    int pos, j;
    pos = linearSearch(key, list);
    if ( pos == ERROR ) return FALSE;
    for( j = pos; j < list->numberOfElements-1 ; j++)
        list->A[j] = list->A[j+1];
    list->numberOfElements --;
    return TRUE;
}