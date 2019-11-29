#pragma once

#include <iostream>
using namespace std;

void MergeSort(int* a, int n);

void MergeSort(int* a, int left, int right);

void Merge(int* a, int left, int mid, int right);