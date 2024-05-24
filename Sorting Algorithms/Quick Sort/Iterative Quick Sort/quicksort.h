#ifndef QUICKSORT_H
#define QUICKSORT_H

// Receives a pointer to an array of integers and the number of elements
// in that array. It prints the elements of the array in the order they are stored"
void showSortedArray(int *arr, int n);

//receives a pointer to an array of integers and the number of elements
//in that array and fills the array with the values provided by the user.
void fillArrayWithUserInput(int *arr, int n);

// verifies if there is an memory allocation error, if there is, exit the application
void hasAllocationError(int *arr);

// get the number of elements provided by the user and returns it
int getNumberOfElements();

// swaps to int variables using pointers
void swap(int* a, int* b);

// rearranges the array all elements less than the pivot come before it, 
// and all elements greater than the pivot come after it.
int partition(int *arr, int low, int high);

// rearranges the array, all elements less than the pivot come before it,
// and all elements greater than the pivot come after it
void quickSortIterative(int *arr, int l, int h);

#endif