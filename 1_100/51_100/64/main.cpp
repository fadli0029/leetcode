#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 && j == 0) { continue; }
                dp[i][j] = grid[i][j] + min(
                    i==0 ? INT_MAX : dp[i-1][j],
                    j==0 ? INT_MAX : dp[i][j-1]
                );
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    return 0;
}

