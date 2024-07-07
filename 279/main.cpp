#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n==1) {
            return 1;
        }

        // let dp[i] be the minimum number
        // of perfect square numbers that sum to i.

        // by default, in the worst case, you need n
        // numbers, so initialize dp values to n (this
        // is like summing all 1^2 until u get n)
        vector<int> dp(n+1, n);
        dp[0] = 0; // no need, but doesn't hurt.
        dp[1] = 1; // base case, you need 1 number for n = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                dp[i] = min(dp[i-(j*j)] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    return 0;
}

