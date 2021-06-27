#include "../include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int swap(void *data, int esize, int i, int j) {
	void *tmp;
	if ((tmp = malloc(esize)) == NULL)
		return -1;
	memcpy(tmp, data + esize * i, esize);
	memcpy(data + esize * i, data + esize * j, esize);
	memcpy(data + esize * j, tmp, esize);
	return 0;
}

int slSort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
	int sz = size - 1;
	for (int i = 0; i < sz; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (compare(data + esize * j, data + esize * minIndex) < 0)
				minIndex = j;
		swap(data, esize, i, minIndex);
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
	return 0;
}
