#include <iostream>
#include <string.h>
using namespace std;

void genSubsetBitWise(char *str) {
	if (str == nullptr)
		return;
	int len = strlen(str);
	int n = 1 << len; // Not 2 << len !!!!!!
	cout << "Null Set" << endl;
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < len; j ++) {
			if (i & (1 << j)) // Not 2 << j !!!!!!
				cout << str[j] << " ";
		}
		cout << endl;
	}
}
/*
void genSubsetRecursively(char *str) {
	if (str == nullptr)
		return;

}*/

int main(int argc, char* argv[]) {
	char str[] = "abc";
	genSubsetBitWise(str);
}