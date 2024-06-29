#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (const auto& num : nums) {
            if (s.contains(num)) {
                return true;
            }
            else {
                s.insert(num);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> test = {1,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate(test) << endl;
    return 0;
}

