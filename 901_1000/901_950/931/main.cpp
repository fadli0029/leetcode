#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==1) {
            return matrix[0][0];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==0) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                if (j==0) {
                    dp[i][j] = matrix[i][j] + min({
                            dp[i-1][j+1],
                            dp[i-1][j],
                        });
                }
                else if (j==n-1) {
                    dp[i][j] = matrix[i][j] + min({
                            dp[i-1][j-1],
                            dp[i-1][j],
                        });
                }
                else {
                    dp[i][j] = matrix[i][j] + min({
                            dp[i-1][j-1],
                            dp[i-1][j+1],
                            dp[i-1][j],
                        });
                }
                cout << endl;
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    Solution sol;
    return 0;
}

