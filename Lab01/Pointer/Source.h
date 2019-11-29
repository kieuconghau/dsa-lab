#pragma once

void InputArray(int*& a, int& n);

void DellocateArray(int*& a);

void PrintArray(int* a, int n);

int FindMin(int* a, int n);

int FindMaxModulus(int* a, int n);

bool IsAscending(int* a, int n);

int SumOfArray(int* a, int n);

bool isPrime(int n);

int CountPrime(int* a, int n);

int ReverseArray(int*& a, int*& b, int n);

int LinearSearch(int* a, int n, int key);

int SentinelLinearSearch(int* a, int n, int key);

int BinarySearch(int* a, int n, int key);

int RecursiveBinarySearch(int* a, int left, int right, int key);
