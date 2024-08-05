#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // First, understand what a palindrome means.
        // I assume you know that. Now, what do we require
        // from a string `s` to be a palindrome?
        // Well, we require that s[0] = s[n-1],
        // s[1] = s[n-2], s[2] = s[n-2], .. etc.

        // That's very straigtforward. If I know
        // s[0] = s[n-1], I just need to check
        // if s[1] = s[n-2], if I know if
        // s[2] = s[n-2], etc.

        // The catch here is that it says "subsequence".
        // Meaning, even if s[0] != s[n-1], we might can still find a palindrome.
        // Why? Because by definition of a subsequence, we
        // can remove characters in `s`. For example:
        // s = abccb
        // Clearly, s[0] != s[n-1] bcoz a!=b. But, the longest
        // palindrome here is bccb of length 4, by removal of
        // a. i.e.: we could find a palindrome if we continue looking
        // to the right. Similarly, take the example s = cbcca.
        // Clearly, s[0] != s[n-1] bcoz c!=a. But, the longest
        // palindrom here is cbc. i.e.: we could find a palindrome
        // if we continue looking to the left.

        // So notice what's going on here, we see that
        // if s[0] = s[n-1], we can set the current longest
        // palindrom length to 2, chop s[0] and s[n-1] from s,
        // and move on to solve for s[1] = s[n-2]. See, how
        // this is broken into subproblems? Only thing is, you
        // need to consider the edge cases mentioned earlier.

        // Edge case 1: Endpoints not some, palindrome
        // could potentially be found by continue looking to
        // the left.

        // Edge case 2: Endpoints not some, palindrome
        // could potentially be found by continue looking to
        // the right.

        // Once the two processes of solving for longest palindromic
        // subsequence (lps) on both edge cases complete, we take
        // the max between the two: max(lps(edge case 1), lps(edge case 2))
        // and add it to the current length of our lps.

        // In the regular case, our lps update is obviously:
        // curr_lps = 2 + lps(remaining string to check)
        // using the example s = abccca, since
        // endpoints equal, then we have:
        // curr_lps = 2 + lps(bccc)

        // Notice this screams recursion and often times you
        // can throw a DP to a recursion problem to save memory!
        // When can you throw a DP to a recursion problem?
        // Whenever any subproblem in the recusion stack
        // is repeated (which you can optimize with memoization),
        // you can 100% throw a DP and solve it too.

        // What's the base case? Empty string is length-0 palindrome
        // and one-character string is length-1 palindrome.

        // There are many vids explaining this problem, but this is the best one
        // bcoz it makes u understand in such a way that will help u answer
        // other variants of this type of DP problem:
        // https://youtu.be/LOMoc56Yj4w?si=fIUazjWqiIADiQ56

        // And optionally, to reinforce your understanding, read leetcode
        // editorial for this problem.
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // dp[i][j] ==> dp[start point][end point]
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1; // one-character string ==> length-1 palindrom.
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    return 0;
}
