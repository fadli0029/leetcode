#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // ===================================================
        // ===================================================
        // NOTE: Look at how I did the for loop!
        // In string problems it's common to iterate like this
        // so it's good to memorize this method!
        // ===================================================
        // ===================================================

        // the key thing to notice here is
        // to get a longer palindrome, the shorter
        // one has to be a palindrome too. What i mean
        // by this is take the example racecar,
        // for the substring aceca to be a palindrome,
        // the substring cec has to be a palindrome.

        // i.e.: let dp[i][j] denotes whether the subtring
        // of s from index i to j is a palindrome, then:
        // dp[i][j] = s[i] == s[j] && dp[i+1][j-1] == 1.

        // This is derived from a basic idea from two pointers method
        // of checking whether a string is a palindrome.

        // even length case
        int n = s.size();
        if (n==1) {
            return s;
        }

        // Prefil dp with 1's on the diagonal.
        // The non-diagonal will be overwritten.
        vector<vector<int>> dp(n, vector<int>(n, 1));
        string curr_longest = string(1, s.at(0));
        for (int idx = 1; idx < n; ++idx) {
            for (int i=0, j=idx; i<n && j<n; i++, j++) {
                if (i==j) { continue; }
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1] == 1;
                if (dp[i][j] == 1 && j-i+1 > curr_longest.size()) {
                    curr_longest = s.substr(i, j-i+1);
                }
            }
        }
        return curr_longest;
    }
};

int main() {
    Solution sol;
    return 0;
}
