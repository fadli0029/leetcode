#include "bits/stdc++.h"
#include "helpers.cpp"
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    string encode(vector<int> count) {
        string res = "";
        for (const auto &cnt : count) {
            res += ("#" + to_string(cnt));
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // unordered_map<vector<int>, vector<string>> record;
        // ^ this won't work, so we need to create our own "hashing" method.

        // we can encode the intended vector<int> above like so:
        // #0#1#2#0#0#...#0 for bcc

        unordered_map<string, vector<string>> record;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (const auto &c : strs[i]) {
                count[int(c) - int('a')]++;
            }
            string encoded_count = encode(count);

            if (record.contains(encoded_count)) {
                record[encoded_count].push_back(strs[i]);
            } else {
                record[encoded_count] = {strs[i]};
            }
        }

        vector<vector<string>> result;
        for (const auto &kv : record) {
            result.push_back(kv.second);
        }
        return result;
    }
};

int main() {
    Solution sol;
    return 0;
}
