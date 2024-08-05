// UNSOLVED! Need to reattempt

#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {
        int lp = 0;
        int rp = numbers.size() - 1;

        while (lp < rp) {
            int comp = target - numbers[lp];
            if (comp > numbers[rp] && (rp!=(numbers.size()-1))) {
                rp++;
                if (numbers[rp] > comp) {
                    lp++;
                }
            }
            else if (comp > numbers[rp] && (rp==(numbers.size()-1))) {
                lp++;
            }
            else if (comp < numbers[rp]) {
                rp--;
                if (numbers[rp] < comp) {
                    lp++;
                }
            }
            else {
                return {lp+1, rp+1};
            }
        }
        return {-1};
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> invalid_two_sum = {-1};

        int index_tracker = 0;
        set<int> first_num_index_tracker;

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for (auto it=nums.begin(); it!=nums.end(); it++) {
            if (!first_num_index_tracker.contains(*it)) {
                int target = -*it;

                auto it_copy = it;
                ++it_copy;
                vector<int> numbers;
                numbers.insert(numbers.begin(), it_copy, nums.end());

                vector<int> two_sum = twoSum(numbers, target);
                if (two_sum != invalid_two_sum) {
                    two_sum[0] += index_tracker;
                    two_sum[1] += index_tracker;
                    int two_sum_1 = nums[two_sum[0]];
                    int two_sum_2 = nums[two_sum[1]];

                    vector<int> ans = {*it, two_sum_1, two_sum_2};
                    if (find(res.begin(), res.end(), ans)==res.end()) {
                        res.push_back(ans);
                    }
                    first_num_index_tracker.insert(index_tracker);
                }
            }
            index_tracker++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = sol.threeSum(nums);
    for (const auto& item : res) {
        printVector(item);
    }
    return 0;
}

