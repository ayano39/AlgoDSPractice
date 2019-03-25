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

void reOrderArrayStable(vector<int> &array) {
    int length = array.size();
    int next_odd = 0;
    for (int i = 0; i < length; i ++) {
        if ((array[i] & 1) == 1) {
            int temp = array[i];
            for (int j = i; j > next_odd; j--)
                array[j] = array[j-1]; 
            array[next_odd++] = temp;
        }
    }
}

int main() {
	//int myints[] = {24, 25, 27, 3, 5, 0, 1, 6,7 };
	int myints[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );
	reOrderArrayStable(a);
	for (int i = 0; i < a.size(); i ++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}