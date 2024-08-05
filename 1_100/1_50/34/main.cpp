#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Errichto has a better solution here
        // without doing binary search twice: https://youtu.be/dVXy6hmE_0U?si=RgNmdFKgay8n7lS1
        int low = 0;
        int high = nums.size() - 1;
        vector<int> indices;
        while (low <= high) {
            // find first T (T is a number greater than target)
            int mid = low + (high - low)/2;
            if (nums[mid] < target) {
                // go right
                low = mid + 1;
            }
            else if (nums[mid] >= target) {
                // go left
                high = mid - 1;
            }
        }
        if (low == nums.size()) {
            // never found T
            return {-1, -1};
        }
        else {
            // low points to first T
            if (nums[low] != target) {
                return {-1, -1};
            }
            indices.push_back(low);
        }

        if (indices.size() == 1) {
            // find first F, now low start where you stopped
            // in the previous while loop, high start in the end
            low = indices[0];
            high = nums.size() - 1;
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (nums[mid] <= target) {
                    // go right
                    low = mid + 1;
                }
                else if (nums[mid] > target) {
                    // go left
                    high = mid - 1;
                }
            }
            // low points to first F or end of array.
            // In the former case, it means something
            // like this [x,y,z,k,k,k,k,d,e,f]
            // where our target is k, and the latter
            // case means something like this: [x,y,z,k,k,k,k].
            // In the first case, this means low < nums.size()
            // and in the second case low == nums.size().
            // But regardles, we'd want the index before low.
            // In the first example, low would point at d, and
            // in the second example, low would point at end
            // of array (out of bounds)
            indices.push_back(low-1);
        }
        return indices;
    }
};

int main() {
    Solution sol;
    return 0;
}

