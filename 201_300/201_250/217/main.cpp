#include "bits/stdc++.h"
#include "helpers.cpp"
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> count;
        for (const auto &num : nums) {
            count[num]++;
            if (count[num] >= 2)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    sol.containsDuplicate(nums);
    return 0;
}
