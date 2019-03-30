#include <iostream>
#include <vector>
#include <exception>
#include <stdlib.h>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

bool lessThan(int x, int y) {
	return (x < y);
}

bool greaterThan(int x, int y) {
	return (x > y);
}

class Heap {
public:
	Heap(bool(*f)(int, int)) {
		size = 0;
		func = f;
	}

	void insert(int new_item) {
		heap_array.push_back(new_item);
		size++;
		_siftUp();
	}

	int pop() {
		if (heap_array.size() == 0)
			throw "Heap Size == 0!";
		int result = heap_array[0];
		swap(heap_array[0], heap_array[size - 1]);
		heap_array.pop_back();
		size--;
		_siftDown();
		return result;
	}

	int top() {
		if (heap_array.size() == 0)
			throw "Heap Size == 0!";
		return heap_array[0];
	}

	int getSize() {
		return heap_array.size();
	}
private:
	vector<int> heap_array;
	int size;
	bool(*func)(int, int);
	void _siftUp() {
		int parent;
		for (int i = size - 1; i > 0; i = parent) {
			if (func(heap_array[parent = (i + 1) / 2 - 1], heap_array[i]))
				break;
			swap(heap_array[parent], heap_array[i]);
		}
	}

	void _siftDown() {
		int child;
		for (int i = 0; (child = 2 * i + 1) < size; i = child) {
			if (child + 1 < size && func(heap_array[child + 1], heap_array[child]))
				child++;
			if (func(heap_array[i], heap_array[child]))
				break;
			swap(heap_array[i], heap_array[child]);
		}
	}
};

class MedianKeeper {
public:
	MedianKeeper() : min_heap(lessThan), max_heap(greaterThan) {
		is_even = true;
	}
	void insert(int new_item) {
		if (is_even) {
			// Insert into min heap first
			if (max_heap.getSize() != 0 && new_item < max_heap.top()) {
				max_heap.insert(new_item);
				new_item = max_heap.pop();
			}
			min_heap.insert(new_item);
		}
		else {
			// Add to max heap
			if (min_heap.getSize() != 0 && new_item > min_heap.top()) {
				min_heap.insert(new_item);
				new_item = min_heap.pop();
			}
			max_heap.insert(new_item);
		}
		is_even = !is_even;
	}

	double getMedian() {
		if (is_even && min_heap.getSize() != 0)
			return (min_heap.top() + max_heap.top()) / 2.0;
		else
			return min_heap.top();

	}
private:
	Heap min_heap;
	Heap max_heap;
	bool is_even;
};

void quickSort(int *a, int lo, int hi) {
	if (lo >= hi)
		return;
	int target = lo + rand() % (hi - lo + 1);
	swap(a[lo], a[target]);
	int i = lo, j = hi + 1, pivot = a[lo];
	while (true) {
		do i++; while (i <= hi && a[i] < pivot);
		do j--; while (a[j] > pivot);
		if (i > j)
			break;
		swap(a[i], a[j]);
	}
	swap(a[j], a[lo]);
	quickSort(a, lo, j - 1);
	quickSort(a, j + 1, hi);
}

int* copyAndSort(int *a, int length) {
	int *copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = a[i];
	quickSort(copy, 0, length - 1);
	return copy;
}

void Test(int a[], int length) {
	MedianKeeper median_keeper;
	for (int i = 0; i < length; i++) {
		cout << "Current stream: ";
		int *copy = copyAndSort(a, i + 1);
		for (int j = 0; j <= i; j++)
			cout << copy[j] << " ";
		cout << endl;
		median_keeper.insert(a[i]);
		cout << "Current Median: " << median_keeper.getMedian() << endl;
	}

}

int main() {
	int a[] = { 3, 5, 84, 13, 56, 86, 12, 23, 52, 19, 72, 31, 0, 1, 1, 4 };
	Test(a, sizeof(a) / sizeof(int));
	return 0;
}