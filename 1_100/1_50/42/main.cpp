#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // Dynamic programming approach.

        // let left[i] be the current maximum
        // block height on the left of i, including i.
        // let right[i] be the current maximum
        // block height on the right of i, including r.
        // let vol[i] be the current maximum volume
        // of trapped water up to and including index i,
        // and it is given by:
        //    vol[i] = min(left[i], right[i]) - height[i]

        int n = height.size();
        if (n==0) {
            return 0;
        }

        vector<int> left(n), right(n);

        // fill up dp table for left, right
        int ans = 0;
        left[0] = height[0], right[n-1] = height[n-1];
        for (int i=1; i<n; i++) {
            left[i] = max(height[i], left[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            right[i] = max(height[i], right[i+1]);
        }
        for (int i=0; i<n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}

