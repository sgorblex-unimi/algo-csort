#ifndef SORT_H
#define SORT_H

// SelectionSort
int slSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// InsertionSort
int isSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// BubbleSort
int bbSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// MergeSort
int mgSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// QuickSort
int qkSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// HeapSort
int hpSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// BucketSort
// int bkSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// RadixSort
// int rxSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#endif
