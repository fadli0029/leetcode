#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Make sure you solved problem unique path from leetcode #62

        // For this problem, understand that if you find a matching
        // character in `text1` and `text2`, you can "chop" off
        // this character and solve the problem again, but now
        // with that matching character chopped off. See how
        // this problem is broken down into subproblems again?
        // Example:
        //  text1: abcd
        //  text2: acbd
        // Iterating backwards, we see that d and d is in both:
        //  abcd
        //     ^
        //  acbd
        //     ^
        // We can chop it and our current longest common subsequence (lcs) value
        // is now 1. Now, we're solving this:
        //  abc
        //    ^
        //  acb
        //    ^
        // This is where it gets interesting. We see that they're not the same.
        // What do we do? Well, if we chop c from text1 and keep searching in text1
        // for letter similar to what we're currently pointing at text2,
        // we may or may not increase our lcs (in this case we will because there's
        // a b after c is chopped in text1). It's the same the other way around:
        // if we chop b instead from text2, and keep searching in text2 for a letter
        // that matches what we're currently pointing at text1, we may or may not
        // increase our lcs (in this case we will because there's
        // a c after b is chopped in text2).
        //
        // Notice what happens here: if there's no match at the current letter
        // we're looking at, we need to chop the letter from one of the strings,
        // say text1 and solve the same problem again. Then, we also need to chop
        // from text2 and solve the same problem again, bcoz it could be either of them
        // that has higher lcs.

        // To sum up:
        // 1. same?
        //    result = lcs + 1, chop both and move on.
        // 2. not same? Create two problems:
        //    a) Chop one of them, move on.
        //    b) Chop the other one, move on.
        //    result = max(result a, result b)

        // What is the base case? The base case is we know if you compare the common
        // subsequence between a character and an empty string, the lcs is 0.
        // Again we can use the padding trick: pad our dp grid with 0's.

        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp_vals(n+1, vector<int>(m+1, 0));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (text2[j-1] == text1[i-1]) {
                    dp_vals[i][j] = dp_vals[i-1][j-1] + 1;
                }
                else {
                    // dp_vals[i][j] = max(dp_vals[i][j], dp_vals[i][j-1]);
                    // dp_vals[i][j] = max(dp_vals[i][j], dp_vals[i-1][j]);
                    dp_vals[i][j] = max(dp_vals[i-1][j], dp_vals[i][j-1]);
                }
            }
        }
        return dp_vals[n][m];
    }
};

int main() {
    Solution sol;
    return 0;
}

