#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;

        int curr_best = min(height[lp], height[rp])*(abs(lp-rp));
        while (lp != rp) {
            if (height[lp] <= height[rp]) {
                lp++;
            }
            else {
                rp--;
            }
            // check the current size
            int curr = min(height[lp], height[rp])*(abs(lp-rp));
            curr_best = max(curr, curr_best);
        }
        return curr_best;
    }
};

int main() {
    Solution sol;
    return 0;
}

