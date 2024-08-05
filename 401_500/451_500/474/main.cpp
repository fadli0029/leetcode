#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    pair<int, int> count_zeros_ones(string s) {
        map<int, int> track = {{0, 0}, {1, 0}};

        for (const auto& c : s) {
            track[c-'0']++;
        }
        return pair<int, int>(track[0], track[1]);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (const auto& s : strs) {
            auto counter = count_zeros_ones(s);
            int zeros = counter.first;
            int ones = counter.second;
            for (int i=m; i>=zeros; i--) {
                for (int j=n; j>=ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    return 0;
}

