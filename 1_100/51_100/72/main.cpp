#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // I think Algorithms by Dasgupta et. al., chapter
        // 6.3 has the best explanation on this. I pad
        // the dp matrix so that it's the same figure 6.4(b)
        // in the textbook.
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // fill all columns in row 0 with the index
        // of the column
        iota(dp[0].begin() + 1, dp[0].end(), 1);

        // fill all rows in column 0 with the index
        // of the row
        int i = 1;
        for_each(
            dp.begin() + 1,
            dp.end(),
            [&i](vector<int>& row) { row[0] = i; i++; }
        );

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = min({
                    dp[i-1][j] + 1,
                    dp[i][j-1] + 1,
                    dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1)
                });
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    sol.minDistance(word1, word2);
    return 0;
}

