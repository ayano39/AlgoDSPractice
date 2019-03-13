#include <iostream>
#include <chrono> 
#include <cstdlib>
#define MAX_LENGTH 100000
using namespace std;
using namespace std::chrono; 

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void quickSortVanilla(int numbers[], int lo, int hi) {
	// Sort Area: [lo, hi]
	if (lo >= hi)
		return;
	int last_smaller = lo;
	for (int i = lo + 1; i <= hi; i++) {
		if (numbers[i] < numbers[lo])
			swap(numbers[++last_smaller], numbers[i]);
	}
	swap(numbers[last_smaller], numbers[lo]);
	quickSortVanilla(numbers, lo, last_smaller - 1);
	quickSortVanilla(numbers, last_smaller + 1, hi);
}

void quickSortBiDirection(int numbers[], int lo, int hi) {
	// Sort Area: [lo, hi]
	if (lo >= hi)
		return;
	int target = lo + rand() % (hi - lo + 1);
	swap(numbers[lo], numbers[target]);

	int i = lo, j = hi + 1, pivot = numbers[lo];
	while (true) {
		do i ++; while (i <= hi && numbers[i] < pivot); // because lo < hi, lo + 1 will stay in bound
		do j --; while (numbers[j] > pivot); // because numbers[lo] is not bigger than itself, there's no need to check "j > lo"
		//cout << i << " " << j << endl;
		if (i > j) // if (i == j), it means numbers[i] == numbers[j] == numbers[lo]
			break;
		swap(numbers[i], numbers[j]);
	}
	swap(numbers[lo], numbers[j]);
	quickSortBiDirection(numbers, lo, j - 1);
	quickSortBiDirection(numbers, j + 1, hi);
}

void Test(int numbers[], int length) {
	cout << length << endl;
    auto start = high_resolution_clock::now();
    quickSortBiDirection(numbers, 0, length - 1);
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
    int d[] = {1};

    cout << "Test case A begins: (normal array)" << endl;
    Test(a, sizeof(a) / sizeof(int));
    cout << "Test case B begins: (sorted array)" << endl;
    Test(b, sizeof(b) / sizeof(int));
    cout << "Test case C begins: (array with same elements)" << endl;
    Test(c, sizeof(c) / sizeof(int));
    cout << "Test case D begins: (array with only one element)" << endl;
    Test(d, sizeof(d) / sizeof(int));
    return 0;
}