#include "../include/sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static int swap(void *data, int esize, int i, int j) {
	void *tmp;
	if ((tmp = malloc(esize)) == NULL)
		return -1;
	memcpy(tmp, data + esize * i, esize);
	memcpy(data + esize * i, data + esize * j, esize);
	memcpy(data + esize * j, tmp, esize);
	free(tmp);
	return 0;
}

int slSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
	int sz = size - 1;
	for (int i = 0; i < sz; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (compare(data + esize * j, data + esize * minIndex) < 0)
				minIndex = j;
		if (swap(data, esize, i, minIndex))
			return -1;
	}
	return 0;
}

int isSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
	void *key;
	if ((key = malloc(esize)) == NULL)
		return -1;
	for (int k = 1; k < size; k++) {
		memcpy(key, data + esize * k, esize);
		int j;
		for (j = k - 1; j >= 0 && compare(data + esize * j, key) > 0; j--) {
			memcpy(data + esize * (j + 1), data + esize * j, esize);
		}
		memcpy(data + esize * (j + 1), key, esize);
	}
	free(key);
	return 0;
}

int bbSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
	int i = 1;
	bool haveSwapped;
	do {
		haveSwapped = false;
		for (int j = 1; j <= size - i; j++)
			if (compare(data + esize * j, data + esize * (j - 1)) < 0) {
				if (swap(data, esize, j, j - 1))
					return -1;
				haveSwapped = true;
			}
		i++;
	} while (haveSwapped && i < size);
	return 0;
}

static void merge(void *data, int esize, int i, int m, int f, void *auxArr, int (*compare)(const void *key1, const void *key2)) {
	int i1, i2, k;
	for (i1 = i, i2 = m, k = 0; i1 < m && i2 < f; k++) {
		void *data1 = data + i1 * esize, *data2 = data + i2 * esize;
		if (compare(data1, data2) < 0) {
			memcpy(auxArr + k * esize, data1, esize);
			i1++;
		} else {
			memcpy(auxArr + k * esize, data2, esize);
			i2++;
		}
	}
	if (i1 < m)
		memcpy(auxArr + k * esize, data + i1 * esize, esize * (m - i1));
	else
		memcpy(auxArr + k * esize, data + i2 * esize, esize * (f - i2));
	memcpy(data + i * esize, auxArr, esize * (f - i));
}

static int mergeSort(void *data, int esize, int i, int f, void *auxArr, int (*compare)(const void *key1, const void *key2)) {
	if (f - i > 1) {
		int m = (i + f) / 2;
		if (mergeSort(data, esize, i, m, auxArr, compare))
			return -1;
		if (mergeSort(data, esize, m, f, auxArr, compare))
			return -1;
		merge(data, esize, i, m, f, auxArr, compare);
	}
	return 0;
}

int mgSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
	void *auxArr;
	if ((auxArr = malloc(size * esize)) == NULL)
		return -1;
	int retVal = mergeSort(data, esize, 0, size, auxArr, compare);
	free(auxArr);
	return retVal;
}
