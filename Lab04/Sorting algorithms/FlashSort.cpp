#include "FlashSort.h"
#include "InsertionSort.h"

void FlashSort(int* a, int n) {
	ClassifyByCountingSort(a, n);	// Sort this array to be nearly sorted.
	InsertionSort(a, n);			// This algorithm is very powerful if an array is NEARLY SORTED.
}

void ClassifyByCountingSort(int* a, int n) {
	int const class_number = 0.1 * n;
	
	if (class_number == 0) {
		return;
	}
	
	int const min = *min_element(a, a + n);
	int const max = *max_element(a, a + n);

	if (min == max) {
		return;
	}

	int* fre = new int[class_number]();
	for (int i = 0; i < n; ++i) {
		++fre[Class(a[i], class_number, min, max)];
	}

	for (int i = 1; i < class_number; ++i) {
		fre[i] += fre[i - 1];
	}

	int* b = new int[n];
	for (int i = n - 1; i >= 0; --i) {
		b[--fre[Class(a[i], class_number, min, max)]] = a[i];
	}

	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}

	delete[] b;
	delete[] fre;
}

// Class ID is counted from 0 to class_number - 1
int Class(int number, int class_number, int min, int max) {
	return ((double)number - min) / ((double)max - min) * ((double)class_number - 1);
}

