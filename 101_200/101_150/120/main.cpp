#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n==1) {
            return triangle[0][0];
        }

        vector<vector<int>> dp(n, vector<int>(n, 10000));
        dp[0][0] = triangle[0][0];
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                if (i==0 && j==0) { continue; }
                // to get to cell (i,j), you either came from
                // 1. (i-1, j)
                // 2. (i-1, j-1)
                int valid_j1 = j; // for case 1.
                int valid_j2 = j; // for case 2.
                if (j == 0) {
                    // if you're at any cell (i, 0), then j-1
                    // will be -1, out of bounds! Realize that
                    // the only where to get to any (i, 0) \forall i
                    // is that you must have came from (i-1, 0).
                    // So, we set j such that j - 1 = 0, i.e.: j = 1.
                    valid_j2 = 1;
                }
                if (j == i) {
                    // if you're at any cell (i, j), where j = i, then due
                    // the definition of a triangle shape, there's no way
                    // you came from (i-1, j). Draw if you don't get this.
                    // So, we set j = i - 1 for the possibility coming from (i-1, j)
                    // and we set j such that j-1 = i-1 for the possibility coming
                    // from (i-1, j-1)
                    valid_j1 = i-1;
                    valid_j2 = i;
                }
                dp[i][j] = triangle[i][j] + min(dp[i-1][valid_j1], dp[i-1][valid_j2-1]);
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    Solution sol;
    return 0;
}

