#include <iostream>
#include <vector>
#include "Source.h"
using namespace std;

int SumOfSquares(int n) {
	if (n <= 0) {
		return 0;
	}
	return n * n + SumOfSquares(n - 1);
}

int GCD(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}

	if (a >= b) {
		return GCD(a % b, b);
	}
	else {
		return GCD(a, b % a);
	}
}

int FIB(int n) {
	if (n <= 1) {
		return n;
	}
	return FIB(n - 1) + FIB(n - 2);
}

int main() {

	return 0;
}