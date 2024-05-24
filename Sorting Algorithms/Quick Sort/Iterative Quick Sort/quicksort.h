#ifndef QUICKSORT_H
#define QUICKSORT_H


void showSortedArray(int *arr, int n);
void fillArrayWithUserInput(int *arr, int n);
void hasAllocationError(int *arr);
int getNumberOfElements();
void swap(int* a, int* b);
int partition(int *arr, int low, int high);
void quickSortIterative(int *arr, int l, int h);

#endif