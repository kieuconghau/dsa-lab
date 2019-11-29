#include "InsertionSort.h"

void InsertionSort(int* a, int n) {
	int temp;
	int j;

	for (int i = 1; i < n; ++i) {
		temp = a[i];

		for (j = i - 1; j >= 0; --j) {
			if (a[j] > temp) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}

		a[j + 1] = temp;
	}
}