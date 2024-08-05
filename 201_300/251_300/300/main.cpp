#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {
            return 1;
        }

        int curr_longest = 0;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                curr_longest = max(dp[i], curr_longest);
            }
        }
        return curr_longest;
    }
};

int main() {
    Solution sol;
    return 0;
}

