#include <iostream>
#include <chrono> 
#include <cstdlib>
#define MAX_LENGTH 100000
using namespace std;
using namespace std::chrono; 

void merge(int numbers[], int lo, int mid, int hi) {
	int *cur_numbers = numbers + lo, *right = numbers + mid;
	int left_len = mid - lo, right_len = hi - mid;
	int *left_copy = new int[left_len];
	for (int i = 0; i < left_len; i ++)
		left_copy[i] = cur_numbers[i];
	int left_index = 0, right_index = 0, new_index = 0;
	while (left_index < left_len && right_index < right_len) {
		if (left_copy[left_index] <= right[right_index])
			cur_numbers[new_index++] = left_copy[left_index++];
		else
			cur_numbers[new_index++] = right[right_index++];
	}
	while (left_index < left_len)
		cur_numbers[new_index++] = left_copy[left_index++];
	delete []left_copy;
}

void mergeSort(int numbers[], int lo, int hi) {
	// Sort Area: [lo, hi)
	if (numbers == nullptr || hi - lo <= 1)
		return;
	int mid = (lo + hi ) / 2;
	mergeSort(numbers, lo, mid);
	mergeSort(numbers, mid, hi);
	merge(numbers, lo, mid, hi);
}

void Test(int numbers[], int length) {
	cout << length << endl;
    auto start = high_resolution_clock::now();
    mergeSort(numbers, 0, length);
    auto stop = high_resolution_clock::now();

    for (int i = 0; i < length; i ++) 
    	cout << numbers[i] << " ";
    cout << endl;
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time Duration: "
         << duration.count() << " microseconds" << endl;
}

int main(int argc, char* argv[]) {
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int b[MAX_LENGTH] = {};
    for(int i = 0; i < MAX_LENGTH; i++)
        b[i] = i;
    int c[MAX_LENGTH] = {};
    for(int i = MAX_LENGTH - 1; i >= 0; i--)
        c[i] = i;
    int d[] = {1};
    int e[] = {2, 3, 1, 5, 4, 7, 9, 8, 2, 3};

    cout << "Test case A begins: (normal array)" << endl;
    Test(a, sizeof(a) / sizeof(int));
    cout << "Test case B begins: (sorted array)" << endl;
    Test(b, sizeof(b) / sizeof(int));
    cout << "Test case C begins: (sorted array2)" << endl;
    Test(c, sizeof(c) / sizeof(int));
    cout << "Test case D begins: (array with only one element)" << endl;
    Test(d, sizeof(d) / sizeof(int));
    cout << "Test case E begins: " << endl;
    Test(e, sizeof(e) / sizeof(int));
    return 0;
}