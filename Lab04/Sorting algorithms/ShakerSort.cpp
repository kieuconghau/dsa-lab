#include "ShakerSort.h"

void ShakerSort(int* a, int n) {
	int left = 0;
	int right = n - 1;
	int flag;

	while (left < right) {
		flag = left;
		for (int i = left; i < right; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = i;
			}
		}
		right = flag;


		flag = right;
		for (int i = right; i > left; --i) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = i;
			}
		}
		left = flag;
	}
}

