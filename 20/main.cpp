#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return false;
        }
        unordered_map<char, char> valids =
        {
          {'}', '{'},
          {')', '('},
          {']', '['},
        };

        stack<char> st;
        for (const auto& c : s) {
            if (valids.find(c) != valids.end()) {
                if (st.empty()) {
                    return false;
                }
                else {
                    if (st.top() != valids[c]) {
                        return false;
                    }
                    st.pop();
                }
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = ")(){}";
    cout << sol.isValid(s) << endl;
    return 0;
}

