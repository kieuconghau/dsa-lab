#include "Support.h"

// Check if an array is in ascending order.
bool IsAscending(int* a, int n) {
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

// Print an array.
void Display(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << " " << a[i];
	}
	cout << endl;
}

void ReportText(string file_name) {
	ofstream fout(file_name);

	if (fout.is_open()) {
		vector<DataOrder> data_order = { {0, "RANDOM DATA"}, {1, "SORTED DATA"}, {2, "NEARLY SORTED DATA"}, {3, "REVERSE DATA"} };

		vector<int> data_size = { 1000, 3000, 10000, 30000, 100000 };

		/*vector<SortingAlgorithm> sorting_algorithm = { {"Selection sort", SelectionSort}, {"Insertion sort", InsertionSort},
			{"Binary insertion sort", BinaryInsertionSort}, {"Bubble sort", BubbleSort}, {"Shaker sort", ShakerSort},
			{"Shell sort", ShellSort}, {"Heap sort", HeapSort}, {"Merge sort", MergeSort}, {"Quick sort", QuickSort},
			{"Counting sort", CountingSort}, {"Radix sort", RadixSort}, {"Flash sort", FlashSort} };*/

		vector<SortingAlgorithm> sorting_algorithm = { {"Quick sort", QuickSort} };

		for (int i = 0; i < data_order.size(); ++i) {
			fout << i + 1 << ". " << data_order[i].Name << endl;

			cout << i + 1 << ". " << data_order[i].Name << endl;

			for (int j = 0; j < data_size.size(); ++j) {
				fout << " " << i + 1 << "." << j + 1 << ". " << data_size[j] << endl;

				cout << " " << i + 1 << "." << j + 1 << ". " << data_size[j] << endl;

				int* original_arr = new int[data_size[j]];
				GenerateData(original_arr, data_size[j], data_order[i].ID);

				for (int k = 0; k < sorting_algorithm.size(); ++k) {
					int* a = new int[data_size[j]];

					for (int i = 0; i < data_size[j]; ++i) {
						a[i] = original_arr[i];
					}

					high_resolution_clock::time_point t1 = high_resolution_clock::now();
					sorting_algorithm[k].Sort(a, data_size[j]);
					high_resolution_clock::time_point t2 = high_resolution_clock::now();

					duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

					fout << "  " << i + 1 << "." << j + 1 << "." << k + 1 << ". " << sorting_algorithm[k].Name << ": ";
					if (IsAscending(a, data_size[j])) {
						fout << time_span.count() * 1000 << endl;	// Miliseconds
					}
					else {
						fout << "WRONG" << endl;
					}

					cout << "  " << i + 1 << "." << j + 1 << "." << k + 1 << ". " << sorting_algorithm[k].Name << ": ";
					if (IsAscending(a, data_size[j])) {
						cout << time_span.count() * 1000 << endl;	// Miliseconds
					}
					else {
						cout << "WRONG" << endl;
					}

					delete[] a;
				}

				delete[] original_arr;
			}

			fout << endl;
		}

		fout.close();
	}
}

void ReportCSV(string file_name) {
	vector<DataOrder> data_order = { {0, "RANDOM DATA"}, {1, "SORTED DATA"}, {2, "NEARLY SORTED DATA"}, {3, "REVERSE DATA"} };

	vector<int> data_size = { 1000, 3000, 10000, 30000, 100000};

	vector<SortingAlgorithm> sorting_algorithm = { {"Selection sort", SelectionSort}, {"Insertion sort", InsertionSort},
		{"Binary insertion sort", BinaryInsertionSort}, {"Bubble sort", BubbleSort}, {"Shaker sort", ShakerSort},
		{"Shell sort", ShellSort}, {"Heap sort", HeapSort}, {"Merge sort", MergeSort}, {"Quick sort", QuickSort},
		{"Counting sort", CountingSort}, {"Radix sort", RadixSort}, {"Flash sort", FlashSort} };
	
	ofstream fout(file_name);

	if (!fout.is_open()) {
		cout << "\aCannot create a csv file." << endl;
		return;
	}

	fout << "Run time in miliseconds,Input size" << endl;

	for (int i = 0; i < data_order.size(); ++i) {
		fout << endl << data_order[i].Name << endl;

		cout << i + 1 << ". " << data_order[i].Name << endl;

		for (int k = 0; k < sorting_algorithm.size(); ++k) {
			fout << "," << sorting_algorithm[k].Name;
		}
		fout << endl;

		for (int j = 0; j < data_size.size(); ++j) {
			fout << data_size[j];

			cout << " " << i + 1 << "." << j + 1 << ". " << data_size[j] << endl;

			int* original_arr = new int[data_size[j]];
			GenerateData(original_arr, data_size[j], data_order[i].ID);
			
			for (int k = 0; k < sorting_algorithm.size(); ++k) {
				int* a = new int[data_size[j]];

				for (int i = 0; i < data_size[j]; ++i) {
					a[i] = original_arr[i];
				}

				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorting_algorithm[k].Sort(a, data_size[j]);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
				
				fout << ",";
				if (IsAscending(a, data_size[j])) {
					 fout << time_span.count() * 1000; // Miliseconds
				}

				cout << "  " << i + 1 << "." << j + 1 << "." << k + 1 << ". " << sorting_algorithm[k].Name << ": ";
				if (IsAscending(a, data_size[j])) {
					cout << time_span.count() * 1000 << endl;	// Miliseconds
				}
				else {
					cout << "WRONG" << endl;
				}

				delete[] a;
			}

			fout << endl;

			delete[] original_arr;
		}
	}

	for (int i = 0; i < data_order.size(); ++i) {
		fout.close();
	}
}
