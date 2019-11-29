#include "ShellSort.h"

void ShellSort(int* a, int n) {
	for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int k = gap; k < n; ++k) {
			int temp = a[k];
			int p;

			for (p = k - gap; p >= 0; p -= gap) {
				if (a[p] > temp) {
					a[p + gap] = a[p];
				}
				else {
					break;
				}
			}

			a[p + gap] = temp;
		}
	}
}

//void ShellSort(int* a, int n) {
//	// Create all gaps
//	int gap_size = 1;
//	for (int h = 1; 3 * h + 1 < n; ++gap_size) {
//		h = 3 * h + 1;
//	}
//	
//	int* gap = new int[gap_size];
//	for (int i = 0, h = 0; i < gap_size; ++i) {
//		gap[i] = 3 * h + 1;
//	}
//
//	// Sort
//	for (int i = gap_size - 1; i >= 0; --i) {
//		// h-sorted (with h = gap[i])
//		for (int j = 0; j < gap[i]; ++j) {	// Divide the array a into h = gap[i] sub-arrays
//			// Use Insertion sort to sort the sub-array which has a[gap[i] + j]
//			for (int k = gap[i]; k < n; k += gap[i]) {
//				int temp = a[k];
//				int p;
//
//				for (p = k - gap[i]; p >= 0; p -= gap[i]) {
//					if (a[p] > temp) {
//						a[p + gap[i]] = a[p];
//					}
//					else {
//						break;
//					}
//				}
//
//				a[p + gap[i]] = temp;
//			}
//		}
//	}
//}