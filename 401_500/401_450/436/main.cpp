#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    // vector<int> findRightInterval(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end());

    //     for (int i=0; i<intervals.size(); i++) {
    //         int curr_target = intervals[i][1];

    //         int low = 0;
    //         int h
    //     }
    // }
};

int main() {
    // Solution sol;
    vector<vector<int>> intervals = {{3, 4}, {2, 3}, {1, 2}};
    int n = intervals.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        arr.emplace_back(intervals[i][0], i);
    }
    for (const auto& pair : arr) {
        cout << "[" << pair.first << ", " << pair.second << "]" << endl;
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    for (const auto& pair : arr) {
        cout << "[" << pair.first << ", " << pair.second << "]" << endl;
    }

    // for (const auto& pair : intervals) {
    //     cout << "[" << pair.first << ", " << pair.second << "]" << endl;
    // }
    // sort(intervals.begin(), intervals.end());
    // printVector(intervals);
    // sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0]<b[0];});
    // printMatrix(intervals);
    return 0;
}

