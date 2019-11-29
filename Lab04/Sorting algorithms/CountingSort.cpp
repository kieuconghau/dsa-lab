#include "CountingSort.h"

/*
* GENERAL IDEA:
	- This is a STABLE algorithm.
	- For simplicity, suppose that all elements in the array are integers
	and the position of elements are counted from 1 (instead of 0).
		a =		  { 5, 1, -2, 5, -4, 5, -2 }
		position    1  2  3  4  5  6  7

	- STEP 1: Abstract all numbers with the minimum value in array a.
		min = -4
		a = { 9, 5, 2, 9, 0, 9, 2 }

	- STEP 2: We need to know the FREQUENCY f(x) of each value in that array.
	(How many times does the value x appear in that array?)
		x -> f(x)
		f(0) = 1 time
		f(2) = 2 times
		f(5) = 1 time
		f(9) = 3 time

	- STEP 3: Obviously, one value can appears in that array more than 1 time.
	So, after calculating the FREQUENCY, we can easily determine the position p(x)
	of the LAST element with value x in the final sorted array.
		x -> p(x)
		p(0) = f(0) = 1						-> the position of the last element with value 1 in the final sorted array
		p(2) = p(1) + f(2) = 1 + 2 = 3		-> the position of the last element with value 2 in the final sorted array
		p(5) = p(2) + f(5) = 3 + 1 = 4		-> the position of the last element with value 5 in the final sorted array
		p(9) = p(5) + f(9) = 4 + 3 = 7		-> the position of the last element with value 9 in the final sorted array

	- STEP 4: Sort this array base on the value of p(x) with x is 0,2,5,9.
		position    1  2  3  4  5  6  7
		p(x)		.     .  .        .
		a =		  { 0, 2, 2, 5, 9, 9, 9 }

	- STEP 5: Add all numbers with the original minimum value in array a.
		min = -4
		a = { -4, -2, -2, 1, 5, 5, 5 }
*/

void CountingSort(int* a, int n) {
	// Find the minimum value and the maximum value of the array.
	int min = *min_element(a, a + n);
	int max = *max_element(a, a + n);

	// Caculate FREQUENCY f(x) with x is each of all distinct values in that array.
	int fr_size = max - min + 1;
	int* fr = new int[fr_size]();	// Allocate with 0s
	for (int i = 0; i < n; ++i) {
		++fr[a[i] - min];		// a[i] - min: the value is started from 0 to max - min.
	}

	// Caculate the position p(x) of the LAST element with x is each of all distinct values in that array.
	for (int i = 1; i < fr_size; ++i) {
		fr[i] += fr[i - 1];
	}

	// Put all elements of the array a to the array b in ascendingly sorted order.
	int* b = new int[n];	// A temporary array
	for (int i = n - 1; i >= 0; --i) {	// A reversed for-loop for stability.
		b[fr[a[i] - min] - 1] = a[i];	// Now, fr[a[i] - min] is the position p(x) of the LAST element with value i.
										// fr[a[i] - min] - 1: index of the array is started from 0 (position is started from 1).
		--fr[a[i] - min];		// Decrease the position of this value by 1.
	}

	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}

	delete[] b;
	delete[] fr;
}

