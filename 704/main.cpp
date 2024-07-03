#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int curr_low_idx  = 0;
        int curr_high_idx = nums.size()-1;

        while (curr_low_idx<=curr_high_idx) {
            int curr_mid_idx = curr_low_idx + (curr_high_idx - curr_low_idx)/2;
            if (target > nums[curr_mid_idx]) {
                curr_low_idx = curr_mid_idx + 1;
            }
            else if (target < nums[curr_mid_idx]) {
                curr_high_idx = curr_mid_idx - 1;
            }
            else {
              return curr_mid_idx;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    return 0;
}

