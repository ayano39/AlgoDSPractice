#include <vector>
#include <iostream>
using namespace std;

bool IsBit1(int x, int bit_pos);
int FindFirst1Bit(int x);

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.size() < 2)
		return;
	int xor_result = 0;
	for (int i = 0; i < data.size(); i++)
		xor_result ^= data[i];
	int bit_pos = FindFirst1Bit(xor_result);
	if (bit_pos == -1)
		return;
	*num1 = 0, *num2 = 0;
	for (int i = 0; i < data.size(); i++) {
		if (IsBit1(data[i], bit_pos))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

int FindFirst1Bit(int x) {
	int mask = 1, bit_pos = 0;
	while ((mask & x) == 0 && bit_pos < 32) {
		mask = mask << 1;
		bit_pos++;
	}
	if (bit_pos == 32)
		return -1;
	else
		return bit_pos;
}

bool IsBit1(int x, int bit_pos) {
	int mask = 1 << bit_pos;
	if ((x & mask) != 0)
		return true;
	else
		return false;
}

int main() {
	int myints[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	vector<int> input(myints, myints + sizeof(myints) / sizeof(int));
	int num1, num2;
	FindNumsAppearOnce(input, &num1, &num2);
	cout << num1 << " " << num2 << endl;

}