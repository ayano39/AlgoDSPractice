#include "Stack.hpp"

void Test(char actual, char expected) {
	if (actual == expected)
		cout << "Test passed." << endl;
	else
		cout << "Test failed." << endl;
}

int main(int argc, char* argv[]) {
	CStack<char> my_stack;
	my_stack.push('a');
	my_stack.push('b');
	my_stack.push('c');

	char pop_item = my_stack.pop();
	Test(pop_item, 'c');
	my_stack.push('d');
	my_stack.push('e');

	pop_item = my_stack.pop();
	Test(pop_item, 'e');
	pop_item = my_stack.pop();
	Test(pop_item, 'd');
	pop_item = my_stack.pop();
	Test(pop_item, 'b');
	pop_item = my_stack.pop();
	Test(pop_item, 'a');
	return 0;
}