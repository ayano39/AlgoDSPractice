#include <iostream>
#include <string.h>
using namespace std;

void swap (char &x, char &y) {
	char temp = x;
	x = y;
	y = temp;
}

bool haveRepeat(char *str, int start, int end) {
	for (int i = start; i < end; i ++) { // Don't worry about swap(start, start), it will skip the iteration
		if (str[i] == str[end])
			return true;
	}
	return false;
}

void permutationCore(char *str, int length, int start) {
	if (start == length)
		cout << str << endl;
	for (int i = start; i < length; i ++) {
		if (haveRepeat(str, start, i))
			continue;
		swap(str[start], str[i]);
		permutationCore(str, length, start + 1);
		swap(str[start], str[i]);
	}
}

void permutation(char *str) {
	if (str == nullptr)
		return;
	permutationCore(str, strlen(str), 0);
}

int main(int argc, char* argv[]) {
	char s1[] = "aabb";
	permutation(s1);
	return 0;
}