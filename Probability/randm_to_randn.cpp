#include <iostream>
#include <cstdlib>
using namespace std;

int randN(int n) {
	return rand() % n + 1;
}
		   
int randM(int m, int n) {
	int base = n;
	int proposal = n - 1, bit_count = 1;
	while (proposal + 1 < m) {
		proposal = proposal * n + proposal - 1;
		bit_count ++;
	}
	int reject_bount = ((proposal + 1)/ m) * m, result;
	do {
		result = 0;
		for (int i = 0; i < bit_count; i ++)
			result = result * n + randN(n) - 1;
	} while (result + 1 > reject_bount);
	return result % m + 1;
}

int main() {
	for (int i = 0; i < 1000; i++)
		cout << randM(100, 7) << endl;
}
