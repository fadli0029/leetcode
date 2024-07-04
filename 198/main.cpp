#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // Given any house i, we can choose to rob house
        // i or not. BUTTTTT, note that if there's
        // only 1 house, i.e: nums.size() = 1,
        // you don't have a choice but to rob it. WHY?
        // Bcoz this is a maximization problem, meaning
        // for any state you land yourself on, you need
        // to make a decision no matter what. If nums.size() == 2,
        // then you can make a choice. This idea of
        // "you need to make a choice no matter what" in
        // max or min problem is really important to remember to
        // be good at solving DP problem.

        // 1. If we choose to rob house i, then next we
        //    can only rob house i+2.
        //    So, the money we get is nums[i] + money from robbing i + 2
        // 1. If we choose NOT to rob house i, then we
        //    can rob house i+1.
        //    So, money from robbing i + 1

        // Therefore, let dp[i] be the max of either:
        // 1. amount of money you robbed at house i plus however much money
        //    accumulated at when you were at i-2
        // 2. amount of money you accumulated if you don't rob house i
        //    plus however much money you accumulated when you were at i-1.

        int n = nums.size();
        if (n==1) {
            return nums[0];

        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i=2; i<n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    return 0;
}

