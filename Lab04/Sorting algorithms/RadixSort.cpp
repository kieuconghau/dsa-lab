#include "RadixSort.h"

/*
# PREREQUISITE:
	- Counting sort.

# GENERAL IDEA:
	- This algorithm is an improved version of "Counting sort" - a STABLE algorithm.
	- This algorithm works well with integers in all bases.
	For simplicity, we assume that all numbers to be sorted are in decimal base.
		a = { -17, 256, 12, -9, 351 }

	- STEP 1: Abstract all numbers with the minimum value in array a.
		min = -17
		a = { 0, 273, 29, 8, 368 }
		a = { 000, 273, 029, 008, 368 }

	- STEP 2: Use the "Counting sort" technique to sort the array a in k times,
	with k is the number of digits of max value in array a.
		max = 368 so k = 3
		
		~ At 1st time, we sort the array on the LEAST SIGNIFICANT DIGIT.
			a = { 000, 273, 029, 008, 368 }
			        .    .    .    .    .
					0    3    9    8    8
			a = { 000, 273, 008, 368, 029 }			
		~ At 2nd time, we sort the array on the SECOND-LEAST SIGNIFICANT DIGIT.
			a = { 000, 273, 008, 368, 029 }
			       .    .    .    .    .
				   0    7    0    6    2
			a = { 000, 008, 029, 368, 273 }
		~ At 2nd time, we sort the array on the THIRD-LEAST SIGNIFICANT DIGIT.
			a = { 000, 008, 029, 368, 273 }
				  .    .    .    .    .
				  0    0    0    3    2
			a = { 000, 008, 029, 273, 368 }

	- STEP 3: Add all numbers with the original minimum value in array a.
		min = -17
		a = { 000, 008, 029, 273, 368 }
		a = { 0, 8, 29, 273, 368 }
		a = { -17, -9, 12, 256, 351 }

*/

void RadixSort(int* a, int n) {
	// Find the minimum value and the maximum value in array a.
	int min = *min_element(a, a + n);
	int max = *max_element(a, a + n);

	// Use the "Counting sort" technique to sort the array a in k times,
	// with k is the number of digits of max value in array a.
	for (int exp = 0; (max - min) / int(pow(10, exp)) != 0; ++exp) {
		// Caculate FREQUENCY of { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
		int* fr = new int[10]();
		for (int i = 0; i < n; ++i) {
			++fr[((a[i] - min) / int(pow(10, exp))) % 10];
		}

		// Caculate the position of the LAST element with digit i in the final sorted array.
		for (int i = 1; i < 10; ++i) {
			fr[i] += fr[i - 1];
		}

		// Put all elements of the array a to the array b in ascendingly-sorted-digit order.
		int* b = new int[n];
		for (int i = n - 1; i >= 0; --i) {	// A reversed for-loop for stability.
			b[--fr[((a[i] - min) / int(pow(10, exp))) % 10]] = a[i];
		}

		for (int i = 0; i < n; ++i) {
			a[i] = b[i];
		}

		delete[] b;
		delete[] fr;
	}
}


