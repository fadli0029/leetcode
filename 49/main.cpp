#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

// NOTE: I timed myself to max 20 mins for medium leetcode problems.
// If it that 20-minute mark is reached and I have not solvedd it,
// I resolve to finding the solution.
// I gave up for this problem.
class Solution {
public:
    string encodeCount(const vector<int>& count) {
        string res = "";
        for (const auto& freq : count) {
            res += "#";
            res += to_string(freq);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) {
            return {{strs}};
        }
        else {
            // We can't do this: unordered_map<vector<int>, vector<string>> res;
            // so we'll encode character count as a string: "#0#1#3...#0" for "bccc"
            unordered_map<string, vector<string>> tracker;
            for (size_t i=0; i<strs.size(); i++) {
                vector<int> count(26, 0);
                for (const char& ch : strs[i]) {
                    count[int(ch) - int('a')]++;
                }
                string key = encodeCount(count); // encode `count`

                if (tracker.find(key) != tracker.end()) {
                    tracker[key].push_back(strs[i]);
                }
                else {
                    vector<string> val = {strs[i]};
                    tracker.insert(make_pair(key, val));
                }
            }
            vector<vector<string>> res;
            for (const auto& kv : tracker) {
                res.push_back(kv.second);
            }
            return res;
        }
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);
    for (const auto& item : res) {
        printVector(item);
    }
    return 0;
}

