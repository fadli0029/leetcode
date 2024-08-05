#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        unordered_map<char, char> validate = {
            {'}', '{'},
            {')', '('},
            {']', '['},
        };

        stack<char> st;
        for (const auto &c : s) {
            if (validate.contains(c)) {
                if (st.empty())
                    return false; // first item is closing bracket
                if (st.top() != validate[c]) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        return st.empty() ? true : false;
    }
};

int main() {
    Solution sol;
    return 0;
}
