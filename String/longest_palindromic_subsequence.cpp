#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int findMax(char *str, int length) {
    int** dp = new int*[length];
    for (int i = 0; i < length; i++) {
        dp[i] = new int[length];
    }

    for (int i = length - 1; i >= 0; i--) {
        for (int j = i; j < length; j++) {
            if (i == j)
                dp[i][j] = 1;
            else if (abs(i - j) == 1) {
                if (str[i] == str[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            }
            else {
                int temp1 = 0;
                if (str[i] == str[j])
                    temp1 = dp[i + 1][j - 1] + 2;
                dp[i][j] = max(max(temp1, dp[i][j - 1]), dp[i + 1][j]);
            }
        }
    }
    int max_len = dp[0][length - 1];
    for (int i = 0; i < length; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return max_len;
}

int main() {
    char str[1000];
    cin >> str;
    cout << findMax(str, strlen(str)) << endl;
    return 0;
}