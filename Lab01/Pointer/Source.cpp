#include <iostream>
#include "Source.h"
using namespace std;

void InputArray(int*& a, int& n) {
	a = new int[n];

	for (int i = 0; i < n; ++i) {
		cout << "Enter a[" << i << "]: ";
		cin >> a[i];
	}
}

void DellocateArray(int*& a) {
	delete a;
	a = nullptr;
}

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << " " << a[i];
	}
}

int FindMin(int* a, int n) {
	int min = a[0];
	
	for (int i = 1; i < n; ++i) {
		if (a[i] < min) {
			min = a[i];
		}
	}

	return min;
}

int FindMaxModulus(int* a, int n) {
	int max = abs(a[0]);

	for (int i = 1; i < n; ++i) {
		if (abs(a[i]) > max) {
			max = abs(a[i]);
		}
	}

	return max;
}

bool IsAscending(int* a, int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] < a[i]) {
			return false;
		}
	}
	return true;
}

int SumOfArray(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}

	return sum;
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}

	if (n < 4) {
		return true;
	}

	if (n % 2 == 0 && n % 3 == 0) {
		return false;
	}

	for (int i = 5; i < sqrt(n); i += 6) {
		if (n % i == 0 && n % (i + 2) == 0) {
			return false;
		}
	}

	return true;
}

int CountPrime(int* a, int n) {
	int count = 0;

	for (int i = 0; i < n; ++i) {
		if (isPrime(a[i])) {
			++count;
		}
	}

	return count;
}

int ReverseArray(int*& a, int*& b, int n) {
	a = new int[n];
	if (a == nullptr) {
		return -1;
	}

	for (int i = 0; i < n; ++i) {
		a[i] = b[n - 1 - i];
	}
	return 1;
}

int LinearSearch(int* a, int n, int key) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

int SentinelLinearSearch(int* a, int n, int key) {
	if (a[n - 1] == key) {
		return n - 1;
	}
	else {
		a[n - 1] = key;
	}

	int i = 0;
	while (a[i++] != key);

	return i < n ? i : -1;
}

int BinarySearch(int* a, int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key) {
	if (left > right) {
		return - 1;
	}
	
	int mid = (left + right) / 2;
	if (a[mid] == key) {
		return mid;
	}
	else if (a[mid] > key) {
		return RecursiveBinarySearch(a, left, mid - 1, key);
	}
	else {
		return RecursiveBinarySearch(a, mid - 1, right, key);
	}
}

int main() {

	return 0;
}