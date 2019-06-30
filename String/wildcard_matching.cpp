#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	if (n == 0)
		return (m == 0);
	bool *dp = new bool[n + 1];
	dp[0] = true;
	for (int j = 1; j <= n; j++)
		dp[j] = (p[j - 1] == '*') ? dp[j - 1] : false;
	for (int i = 1; i <= m; i++) {
		bool left_up = dp[0];
		dp[0] = false;
		for (int j = 1; j <= n; j++) {
			bool temp = dp[j];
			if (p[j - 1] == '*')
				dp[j] = dp[j - 1] || dp[j];
			else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				dp[j] = left_up;
			else
				dp[j] = false;
			left_up = temp;
		}
	}
	bool result = dp[n];
	delete[] dp;
	return result;
}

int main() {
	string s("adceb"), p("*a*b");
	cout << isMatch(s, p) << endl;
	return 0;
}		

