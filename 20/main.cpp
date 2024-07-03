#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren_stack;

        unordered_map<char, char> data;
        data.insert(pair<char, char>(')', '('));
        data.insert(pair<char, char>('}', '{'));
        data.insert(pair<char, char>(']', '['));

        for (const auto& ch : s) {
            if (data.find(ch)!=data.end()) {
                if (paren_stack.empty()) {
                    return false;
                }
                else {
                    char top = paren_stack.top();
                    if (top == data[ch]) {
                        paren_stack.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                paren_stack.push(ch);
            }
        }
        return paren_stack.empty();
    }
};

int main() {
    Solution sol;
    return 0;
}

