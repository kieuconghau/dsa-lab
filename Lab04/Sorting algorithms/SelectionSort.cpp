#include "SelectionSort.h"

void SelectionSort(int* a, int n) {
	int min;
	int min_index;

	for (int i = 0; i < n - 1; ++i) {
		min = a[i];
		min_index = i;

		for (int j = i + 1; j < n; ++j) {
			if (a[j] < min) {
				min = a[j];
				min_index = j;
			}
		}

		swap(a[min_index], a[i]);
	}
}
