#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    // The key of solving this problem is first to notice
    // that we (i.e.: the target) can either be in the left
    // sorted portion of `nums` or the right sorted portion of
    // `nums`. Depending on which case we fall into, we need
    // to apply different update condition on the low and high
    // pointers of the binary search algorithm.

    // The way to identify if an item in `nums` is in the left sorted
    // portion or right sorted portion is trivial:
    //    if nums[k] >= nums[low_i]:
    //        then item at index k must be in the left sorted portion.
    //    else:
    //        then item at index k must be in the right sorted portion.

    // If our mid is currently in the left sorted portion but
    // our target is smaller than mid then there are two possibilities:
    // 1. target can be anywhere below mid
    // 2. target can be anywhere above mid
    // Ex: [4, 5, 6, 7, 0, 1, 2], target=0
    //    Iteration 1: low=4, mid=7, high=2
    // Since target < mid and we are on the left sorted portion,
    // 4, 5, 6, 0, 1, 2 are all < mid.
    // But, we can check if low > target, then of course we don't need
    // to search over 4,5,6 anymore since if 4 is bigger than target than 5, 6 also.
    // This is how we deal with 1. and 2.
    int search(vector<int>& nums, int target) {
        int low_i = 0;
        int high_i = nums.size() - 1;
        while (low_i <= high_i) {
            int mid_i = low_i + (high_i - low_i)/2;

            // Base case
            if (target == nums[mid_i]) {
                return mid_i;
            }

            // Left sorted portion
            if (nums[mid_i] >= nums[low_i]) {
                // You can condense these two if-else bcoz with
                // or statement bcoz they do the same thing.
                // I keep it here for readability.
                if (target > nums[mid_i]) {
                  low_i = mid_i + 1;
                }
                else if (target < nums[low_i]) {
                  low_i = mid_i + 1;
                }
            }
            // Right sorted portion
            else {
                // You can condense these two if-else bcoz with
                // or statement bcoz they do the same thing.
                // I keep it here for readability.
                if (target < nums[mid_i]) {
                  high_i = mid_i - 1;
                }
                else if (target > nums[high_i]) {
                  high_i = mid_i - 1;
                }
            }
        }
        return -1;
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

