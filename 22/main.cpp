#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    void recurse(int n, int open, int close, vector<string>& results, string s) {
        if (open==n && close==n) {
            results.push_back(s);
            return;
        }

        if (open < n) {
            recurse(n, open+1, close, results, s+"(");
        }

        if (open > close) {
            recurse(n, open, close+1, results, s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        recurse(n, 0, 0, results, "");
        return results;
    }
};

int main() {
    Solution sol;
    return 0;
}

