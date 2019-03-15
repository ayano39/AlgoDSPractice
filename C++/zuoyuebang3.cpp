#include <cstdio>
using namespace std;

int e = 0;
void fun(int *a, int &b, int c) {
	static int d = 0;
	*a = e++;
	b = ++d;
	c = *a++;
}

int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	fun(&a, b, c);
	fun(&a, b, c);
	int *d = &a;
	printf("%d %d %d", a, b, c);
	return 0;
}