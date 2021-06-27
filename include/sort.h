#ifndef SORT_H
#define SORT_H

// SelectionSort
int slSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// InsertionSort
int isSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#endif
