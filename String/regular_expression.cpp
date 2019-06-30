#include <iostream>
#include <string.h>
using namespace std;

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	int m = strlen(str), n = strlen(pattern);
	if (n == 0)
		return (m == 0);
	bool *dp = new bool[n + 1];
	dp[0] = true;
	for (int j = 1; j <= n; j++)
		dp[j] = (pattern[j - 1] == '*' && j >= 2) ? dp[j - 2] : false;
	for (int i = 1; i <= m; i++) {
		bool left_up = dp[0];
		dp[0] = false;
		for (int j = 1; j <= n; j++) {
			int temp = dp[j];
			if (pattern[j - 1] == '*')
				dp[j] = (j >= 2 && dp[j - 2]) || ((str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[j]);
			else
				dp[j] = (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') ? left_up : false;
			left_up = temp;
		}
	}
	bool result = dp[n];
	delete[] dp;
	return result;
}

int main() {
	char text[] = "a";
	char pattern[] = "a.";
	cout << match(text, pattern) << endl;
	return 0;
}