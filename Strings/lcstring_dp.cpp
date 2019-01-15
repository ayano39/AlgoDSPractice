#include <iostream>
#include <string>
using namespace std;

string LongestCommonStringDP(const string s1, const string s2) {
    int max_len = 0, end_index = 0;
    int m = s1.size();
    int n = s2.size();
    int longest_suffix_len[m+1][n+1];
    
    // longest_suffix_len[i][j] = length of the longest common suffix of s1[0:i] and s2[0:j]
    for (int i = 0; i < m + 1; i ++)
        longest_suffix_len[i][0] = 0;
    for (int j = 0; j < n + 1; j ++)
        longest_suffix_len[0][j] = 0;
    for (int i = 1; i < m + 1; i ++) {
        for (int j = 1; j < n + 1; j ++) {
            if (s1[i-1] == s2[j-1]) {
                longest_suffix_len[i][j] = longest_suffix_len[i-1][j-1] + 1;
                if (longest_suffix_len[i][j] > max_len) {
                    max_len = longest_suffix_len[i][j];
                    end_index = i;
                }
            }
            else
                longest_suffix_len[i][j] = 0;
            cout << longest_suffix_len[i][j] << " ";
        }
        cout << endl;
    }
    return s1.substr(end_index-max_len, max_len);
}

void Test(const string s1, const string s2, const string expected) {
    cout << "Test case: " << s1 << " " << s2 << endl;
    if (LongestCommonStringDP(s1, s2) == expected)
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