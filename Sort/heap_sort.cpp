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

void siftUp(int heap[], int size) {
	int parent;
	for (int i = size - 1; i > 0 && heap[parent = (i + 1) / 2 - 1] < heap[i]; i = parent)
		swap(heap[parent], heap[i]);
}

void siftDown(int heap[], int size) {
	int child;
	for (int i = 0; i < size && (child = (i + 1) * 2 - 1) < size; i = child) {
		if (child + 1 < size && heap[child] < heap[child + 1])
			child ++;
		if (heap[i] >= heap[child])
			break;
		swap(heap[i], heap[child]);
	}
}

void heapSort(int num[], int length) {
	if (num == nullptr || length <= 0)
		return;
	for (int i = 1; i <= length; i ++) 
		siftUp(num, i);
	for (int i = length - 1; i > 0; i --) {
		swap(num[0], num[i]);
		siftDown(num, i);
	}
}

void Test(int numbers[], int length) {
    auto start = high_resolution_clock::now();
    heapSort(numbers, length);
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