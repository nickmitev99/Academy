#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void menu();
void setArray(int *arr, int size);
void printArray(int *arr, int size);
void sort_array(void* A, int n, int dir, void (*fp)(int*, int, int));
void sort(int* A, int n, int dir);
void swapElements(int* min, int* max);
#endif //FUNCTIONS_H