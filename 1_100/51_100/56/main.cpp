#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1)
            return intervals;

        // Sort the intervals based on the starting times
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &v1, const vector<int> &v2) {
                 return v1[0] < v2[0];
             });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                // There is an overlap, merge the intervals
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // No overlap, add the interval to the result
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
