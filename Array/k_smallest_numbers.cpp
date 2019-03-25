#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int partition(vector<int> &input, int lo, int hi) { //[lo, hi]
	int target = lo + rand() % (hi - lo + 1);
	swap(input[lo], input[target]);
	int i = lo, j = hi + 1, pivot = input[lo];
	while (true) {
		do i++; while (i <= hi && input[i] < pivot);
		do j--; while (input[j] > pivot);
		if (i > j)
			break;
		swap(input[i], input[j]);
	}
	swap(input[j], input[lo]);
	return j;
}

vector<int> getLeastNumbersByPartition(vector<int> input, int k) {
	vector<int> result;
	if (input.size() == 0 || input.size() < k)
		return result;
	int lo = 0, hi = input.size() - 1;
	while (true) {
		int pivot = partition(input, lo, hi);
		if (pivot == k - 1)
			break;
		else if (pivot < k - 1)
			lo = pivot + 1;
		else
			hi = pivot - 1;
	}
	for (int i = 0; i < k; i++) {
		result.push_back(input[i]);
	}
	return result;
}

void siftUp(vector<int> &heap, int size) {
	int parent;
	for (int i = size - 1; i > 0; i = parent) { 
		if (heap[parent = (i + 1) / 2 - 1] >= heap[i])
			break;
		swap(heap[i], heap[parent]);
	}
}

void siftDown(vector<int> &heap, int size) {
	int child;
	for (int i = 0; (child = 2 * i + 1) < size; i = child) {
		if (child + 1 < size && heap[child + 1] > heap[child])
			child ++;
		if (heap[child] <= heap[i])
			break;
		swap(heap[i], heap[child]);
	} 
}

vector<int> getLeastNumbersByHeap(vector<int> input, int k) {
	vector<int> heap;
	int length = input.size();
	if (length == 0 || length < k)
		return heap;
	for (int i = 0; i < k; i ++) {
		heap.push_back(input[i]);
		siftUp(heap, i + 1);
	}
	for (int i = k; i < length; i ++) {
		if (input[i] < heap[0]) {
			heap[0] = input[i];
			siftDown(heap, k);
		}
	}
	return heap;
}

int main() {
	int a[] = {4, 5, 1, 6, 2, 7, 3, 8};//{ 4, 8, 44, 1, 5, 67, 4, 12 };
	int k = 4;
	vector<int> input(a, a + sizeof(a) / sizeof(int));
	vector<int> result_heap = getLeastNumbersByHeap(input, k);
	vector<int> result_partition = getLeastNumbersByPartition(input, k);
	cout << "Result by partition:" << endl;
	for (int i = 0; i < result_partition.size(); i++)
		cout << result_partition[i] << " ";
	cout << endl;
	cout << "Result by heap:" << endl;
	for (int i = 0; i < result_heap.size(); i++)
		cout << result_heap[i] << " ";
	cout << endl;
	return 0;
}