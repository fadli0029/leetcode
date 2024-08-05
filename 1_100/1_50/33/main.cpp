#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find pivot
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
        int ip = low; // pivot index;
        low = 0, high = n-1; // assumes not rotated, if rotated if (ip!=0) condition entered.

        if (ip != 0) {
            // Now we know the pivot, we just need to know
            // which part of the array does the target lies
            // in? Left sorted part or right sorted part?
            bool left = target > nums[n-1] ? true : false;

            // Then decide the search index range
            if (left) { low = 0, high = ip - 1; }
            else { low = ip, high = n - 1; }
        }

        // Do regular binary search since now
        // on nums within the index range only
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid] > target) {
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return n==1 && target == nums[0] ? 0 : -1;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {5, 1, 3}; // original: {1, 3, 5} --> {5, 1, 3} --> {3, 5, 1} --> {1, 3, 5}
    // int target = 5;
    vector<int> nums = {5, 7, 0, 1, 2, 3, 4};
    int target = 7;
    // vector<int> nums = {1};
    // int target = 1;

    int ans = sol.search(nums, target);
    cout << "Ans: " << ans << endl;
    return 0;
}

