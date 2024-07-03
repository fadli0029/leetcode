#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int binary_search(vector<int> nums, int t) {
        int low = 0;
        int high = nums.size() - 1;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (t > nums[mid]) {
                low = mid + 1;
            }
            else if (t < nums[mid]) {
                high = mid-1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.size();
        for (int i=0; i<m; i++) {
            // perform binary search on row m
            if (binary_search(matrix[i], target)!=-1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}

