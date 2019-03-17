#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void reOrderArray(vector<int> &array) {
    int length = array.size();
    if (length == 0)
        return;
    int i = 0, j = length - 1;
    while (true) {
        while (i < length && (array[i] & 1) == 1) i ++;
        while (j >= 0 && (array[j] & 1) == 0) j--;
        if (i >= j)
            break;
        swap(array[i], array[j]);
    }
}

int main() {
	int myints[] = {24, 25, 27, 3, 5, 0, 1, 6,7 };
	vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );
	reOrderArray(a);
	for (int i = 0; i < a.size(); i ++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}