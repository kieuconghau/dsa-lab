#pragma once
#include <iostream>
#include <ctime>
using namespace std;

void QuickSort(int* a, int n);

void QuickSort(int* a, int left, int right);

int Partition(int* a, int left, int right);