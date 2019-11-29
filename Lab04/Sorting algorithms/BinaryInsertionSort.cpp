#include "BinaryInsertionSort.h"

void BinaryInsertionSort(int* a, int n) {
	int temp;
	int j;
	int k;

	for (int i = 1; i < n; ++i) {
		temp = a[i];
		k = BinarySearch(a, temp, 0, i - 1);
		
		for (j = i - 1; j >= k; --j) {
			a[j + 1] = a[j];
		}

		a[k] = temp;
	}
}

int BinarySearch(int* a, int key, int left, int right) {
	while (left < right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == key) {
			return mid;
		}

		if (a[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	if (a[left] > key) {
		return left;
	}
	else {
		return left + 1;
	}
	
	/*if (left >= right) {
		return (a[left] > key) ? left : left + 1;
	}
	
	int mid = (left + right) / 2;

	if (a[mid] == key) {
		return mid;
	}
	else if (a[mid] > key) {
		return BinarySearch(a, key, left, mid - 1);
	}
	else {
		return BinarySearch(a, key, mid + 1, right);
	}*/
}