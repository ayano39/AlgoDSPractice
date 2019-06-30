#include <iostream>
#include <cstdlib>
using namespace std;

int rand7() {
	return rand() % 7 + 1;
}
		   
int rand10() {
	int result, x, y;
	while (true) {
		x = rand7();
		y = rand7();
		result = (x - 1) * 7 + y;
		if (result <= 40)
			return (result - 1) % 10 + 1;
		x = result - 40;
		y = rand7();
		result = (x - 1) * 7 + y;
		if (result <= 60)
			return (result - 1) % 10 + 1;
		x = result - 60;
		y = rand7();
		result = (x - 1) * 7 + y;
		if (result <= 20)
			return (result - 1) % 10 + 1;
	}
}

int main() {
	for (int i = 0; i < 20; i++)
		cout << rand10() << endl;
}
