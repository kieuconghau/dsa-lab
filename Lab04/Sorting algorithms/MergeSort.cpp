#include "MergeSort.h"

void MergeSort(int* a, int n) {
	if (n > 1) {
		MergeSort(a, 0, n - 1);
	}
}

void MergeSort(int* a, int left, int right) {
	if (left < right) {
		// Split
		int mid = left + (right - left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);

		// Merge
		Merge(a, left, mid, right);
	}
}

void Merge(int* a, int left, int mid, int right) {
	int left_arr_size = mid - left + 1;
	int right_arr_size = right - mid;
	
	int* left_arr = new int[left_arr_size];
	int* right_arr = new int[right_arr_size];

	for (int i = 0; i < left_arr_size; ++i) {
		left_arr[i] = a[left + i];
	}

	for (int i = 0; i < right_arr_size; ++i) {
		right_arr[i] = a[mid + 1 + i];
	}

	int i = left;
	int left_i = 0;
	int right_i = 0;

	while (left_i < left_arr_size && right_i < right_arr_size) {
		if (left_arr[left_i] <= right_arr[right_i]) {
			a[i++] = left_arr[left_i++];
		}
		else {
			a[i++] = right_arr[right_i++];
		}
	}

	while (left_i < left_arr_size) {
		a[i++] = left_arr[left_i++];
	}

	while (right_i < right_arr_size) {
		a[i++] = right_arr[right_i++];
	}

	delete[] right_arr;
	delete[] left_arr;
}