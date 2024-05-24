#include <stdio.h>
#include <stdlib.h>
#include "t_stack.h"
#include "quicksort.h"

void showSortedArray(int *array, int numberOfElements){
    printf("Sorted array: ");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void fillArrayWithUserInput(int *array, int n){
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void hasAllocationError(int *array){
    if (array == NULL){
        printf("Unable to allocate memory, exiting...");
        exit(1);
    }
}

int getNumberOfElements(){
    int numberOfElements;
    printf("Enter the number of elements: ");
    scanf("%d%*c", &numberOfElements);
    return numberOfElements;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int less(int firstElement, int secondElement){
    return firstElement < secondElement;
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortIterative(int *array, int l, int h) {
    STACK stack;
    initStack(&stack);

    REGISTER low, high;
    low.key = l;
    high.key = h;
    insertElemStack(high, &stack);
    insertElemStack(low, &stack);

    while (size(&stack) > 0) {
        deleteElemStack(&stack, &low);
        l = low.key;
        deleteElemStack(&stack, &high);
        h = high.key;

        int p = partition(array, l, h);

        if (p - 1 > l) {
            low.key = l;
            high.key = p - 1;
            insertElemStack(high, &stack);
            insertElemStack(low, &stack);
        }

        if (p + 1 < h) {
            low.key = p + 1;
            high.key = h;
            insertElemStack(high, &stack);
            insertElemStack(low, &stack);
        }
    }
    destroyStack(&stack);
}