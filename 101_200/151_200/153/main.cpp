#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid] > nums[n-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution sol;
    return 0;
}

