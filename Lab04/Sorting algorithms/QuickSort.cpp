#include "QuickSort.h"

void QuickSort(int* a, int n) {
	if (n > 1) {
		QuickSort(a, 0, n - 1);
	}
}

void QuickSort(int* a, int left, int right) {
	if (left < right) {
		int p = Partition(a, left, right);
		QuickSort(a, left, p - 1);
		QuickSort(a, p + 1, right);
	}
}

int Partition(int* a, int left, int right) {
	/*srand((size_t)time(nullptr));
	int random_index = rand() % (right - left + 1) + left;
	swap(a[left], a[random_index]);*/

	swap(a[left + (right - left) / 2], a[left]);

	int pivot = a[left];
	int i = left + 1;
	int j = right;

	do {
		while (i <= right && a[i] < pivot) {	// a[i] < pivot && i <= right -> out of range subscript
			++i;
		}

		while (j > left && a[j] >= pivot) {
			--j;
		}

		if (i < j) {
			swap(a[i], a[j]);
		}
		
	} while (i < j);	// Fun fact: i will never equal j

	swap(a[j], a[left]);
	
	return j;
}
