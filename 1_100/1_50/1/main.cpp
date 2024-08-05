#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for (size_t i=0; i<nums.size(); i++) {
            int comp = target - nums[i];

            auto it = ranges::find(v, comp);
            if (it!=v.end()) {
                return {int(distance(v.begin(), it)), int(i)};
            }
            else {
                v.push_back(nums[i]);
            }
        }
        return {};
    }
    // Below is a faster solution with the same logic
    // bcoz ranges::find on vector is performing linear
    // search which is O(n) whereas unordered_map.find is doing hash
    // table lookup which is O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> v_idx; // key: value, value: index
    //     for (size_t i=0; i<nums.size(); i++) {
    //         int comp = target - nums[i];

    //         if (v_idx.find(comp)!=v_idx.end()) {
    //             return {v_idx[comp], int(i)};
    //         }
    //         v_idx.insert({nums[i], i});
    //     }
    //     return {};
    // }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> res = sol.twoSum(nums, target);
    printVector(res);
    return 0;
}

