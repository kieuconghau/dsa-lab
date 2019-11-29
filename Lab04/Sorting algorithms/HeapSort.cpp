#include "HeapSort.h"

void HeapSort(int* a, int n) {
	// Build a heap ([(n - 2) / 2 + 1 , n - 1] is A NATURAL HEAP)
	for (int i = (n - 2) / 2; i >= 0; --i) {
		SiftMax(a, i, n - 1);
	}

	int right = n - 1;
	while (right > 0) {
		swap(a[0], a[right]);		// Exchange the maximum value at the top of the max heap
									// with the last value of the current heap.
		--right;					// Decrease the size of this heap.
		SiftMax(a, 0, right);	// Build a max heap again till the size of this heap is 1.
	}
}

// Build max heap (The maximum value is at index 0 - at the top of the heap)
void SiftMax(int* a, int left, int right) {
	int i = left;
	int j = 2 * i + 1;

	while (j <= right) {
		if (j < right) {	// Check if a[i] has two comparands (left and right)
			if (a[j + 1] > a[j]) {	// Select the greater comparand (left or right)
				++j;
			}
		}

		// If the selected comparand is greater than a[i], exchange their.
		if (a[i] >= a[j]) {
			break;
		}
		swap(a[i], a[j]);

		// Sift down along the path of the selected comparand till j is out of range (j > right).
		i = j;
		j = 2 * i + 1;
	}
}
