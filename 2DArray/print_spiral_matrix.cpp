#include <iostream>
using namespace std;

void printSpirallyCore(int *matrix, int rows, int cols, int start, int &count) {
	int end_row = rows - start - 1;
	int end_col = cols - start - 1;
	for (int i = start; i <= end_col; i ++) {
		cout << matrix[start * cols + i] << " ";
		count ++;
	}
	if (start < end_row) {
		for (int i = start + 1; i <= end_row; i ++) {
			cout << matrix[i * cols + end_col] << " ";
			count ++;
		}
	}
	if (start < end_col && start < end_row) {
		for (int i = end_col - 1; i >= start; i --) {
			cout << matrix[end_row * cols + i] << " ";
			count ++;
		}
	}
	if (start < end_row - 1 && start < end_col) {
		for (int i = end_row - 1; i >= start + 1; i --) {
			cout << matrix[i * cols + start] << " ";
			count ++;
		}
	}
}

void printSpirally(int *matrix, int rows, int cols) {
	if (matrix == nullptr || rows <= 0 || cols <= 0)
		return;
	int count = 0, start = 0;
	while (count < rows * cols)
		printSpirallyCore(matrix, rows, cols, start++, count);
	cout << endl;
}

int main() {
	int a[] = {1,2,3,4,5,14,15,16,17,6,13,20,19,18,7,12,11,10,9,8};
	int b[] = {1};
	int c[] = {1,2,3,4};
	int d[] = {1,2,4,3};
	printSpirally(a, 4, 5);
	printSpirally(b, 1, 1);
	printSpirally(c, 1, 4);
	printSpirally(c, 4, 1);
	printSpirally(d, 2, 2);
	return 0;
}