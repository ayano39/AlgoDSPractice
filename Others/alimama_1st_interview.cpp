#include <iostream>
#include <string.h>
using namespace std;

void transform(char *str) {
	if (str == nullptr)
		return;
	int length = strlen(str), count = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == 'a')
			count ++;
	}
	cout << count << endl;
	int new_length = length + count;
	int i = length, j = new_length;
	while (i >= 0 && !(i > j)) {
		if (str[i] == 'a')
			str[j--] = 'a';
		str[j--] = str[i--];
	}
}

int main() {
	char str[50];
	char a[] = "abcdaaab";
	for (int i = 0; i < strlen(a); i ++)
		str[i] = a[i];
	str[strlen(a)] = '\0';
	transform(str);
	cout << str << endl; 
}