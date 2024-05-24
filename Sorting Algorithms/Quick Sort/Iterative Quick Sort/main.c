#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

int main() {
    int numberOfElements = getNumberOfElements();
    int *array = (int*) malloc(sizeof(int)*numberOfElements);
    hasAllocationError(array);
    fillArrayWithUserInput(array, numberOfElements);
    quickSortIterative(array, 0, numberOfElements - 1);
    showSortedArray(array, numberOfElements);
    free(array);
    return 0;
}