#include "DataGenerator.h"


// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int* a, int n) {
	srand((size_t)time(nullptr));
	
	for (int i = 0; i < n; i++) {
		a[i] = rand() % n - rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	
	srand((size_t)time(nullptr));

	for (int i = 0; i < 10; i ++) {
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int* a, int n, int data_type) {
	switch (data_type)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	case 3:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	default:
		cout << "Error: unknown data type!" << endl;
		throw;
	}
}

