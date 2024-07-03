#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    // [2, 4, 5, 6, 7, 0, 1] --> size = 7
    //  ^l       ^m       ^h
    //              ^l ^m ^h
    //              ^l,h,m
    //              ^h ^l
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int res = nums[low];
        while (low<=high) {
            if (nums[low] < nums[high]) {
                return min(res, nums[low]);
            }
            int mid = low + (high-low)/2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}

