#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[1][1] = 1;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i==1 && j==1) { continue ;}

                // can you even be at (i, j)?
                if (obstacleGrid[i-1][j-1] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    if (i-2 < 0) {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                    else if (j-2 < 0) {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                    else {
                        dp[i][j] =
                        (obstacleGrid[i-2][j-1] == 0 ? dp[i-1][j] : 0) +
                        (obstacleGrid[i-1][j-2] == 0 ? dp[i][j-1] : 0);
                    }
                }
            }
        }
        // edge case: start point is an obstacle or goal point is an obstacle.
        return obstacleGrid[m-1][n-1] || obstacleGrid[0][0] == 1 ? 0 : dp[m][n];
    }
};

int main() {
    Solution sol;
    return 0;
}

