#include <iostream>
#include <list>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> children;
	for (int i = 0; i < n; i++)
		children.push_back(i);
	list<int>::iterator current = children.begin();
	while (children.size() > 1) {
		for (int i = 0; i < m - 1; i++) {
			current++;
			if (current == children.end())
				current = children.begin();
		}
		list<int>::iterator next = ++current;
		if (next == children.end())
			next = children.begin();
		current--;
		children.erase(current);
		current = next;
	}
	return *current;
}


int main() {
	cout << LastRemaining_Solution(5, 3) << endl;
	return 0;
}