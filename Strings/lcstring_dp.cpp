#include <iostream>
#include <string>
using namespace std;

string LongestCommonStringDP(const string s1, const string s2) {
    int m = s1.size(), n = s2.size();
    if (m <= 0 || n <= 0)
    	return string("");
    int longest_suffix_len[2][n];
    // longest_suffix_len[i][j] = length of the longest common suffix of 
    // s1[0,i] and s2[0,j] (s[i] and s[i] are included)
    int max_len = 0, end_index = 0;
    int cur_index = 0, prev_index = 1;

    for (int j = 0; j < n; j ++) {
    	if (s1[0] == s2[j]) {
    		longest_suffix_len[cur_index][j] = 1;
    		max_len = 1;
    		end_index = 0;
    	}
    	else
    		longest_suffix_len[cur_index][j] = 0;
    }
    
    for (int i = 1; i < m; i ++) {
    	cur_index = (cur_index + 1) % 2;
    	prev_index = (prev_index + 1) % 2;
    	for (int j = 0; j < n; j ++) {
    		if (s1[i] == s2[j]) {
    			longest_suffix_len[cur_index][j] = (j == 0)? 1 : longest_suffix_len[prev_index][j-1] + 1;
    			if (max_len < longest_suffix_len[cur_index][j]) {
    				max_len = longest_suffix_len[cur_index][j];
    				end_index = i;
    			}
    		}
    		else
    			longest_suffix_len[cur_index][j] = 0;
    	}
    } 
    return s1.substr(end_index - max_len + 1, max_len);
}

void Test(const string s1, const string s2, const string expected) {
    cout << "Test case: " << s1 << " " << s2 << endl;
    string result = LongestCommonStringDP(s1, s2);
    cout << "Longest Common Substring: " << result << endl;
    if (result == expected)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main(int argc, char* argv[]) {
    Test("google", "cooper", "oo");
    Test("ksabcd", "abcde", "abcd");
    Test("a", "d", "");
    return 0;
}