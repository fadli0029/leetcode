#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int operate(string op, int op1, int op2) {
        if (op == "+") {
            return op1 + op2;
        }
        else if (op == "-") {
            return op1 - op2;
        }
        else if (op == "*") {
            return op1 * op2;
        }
        else {
            return op1 / op2;
        }
    }

    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        unordered_set<string> ops = {"+", "-", "/", "*"};
        stack<string> st;
        for (const string& tok : tokens) {
            if (ops.find(tok) != ops.end()) {
                int operand1 = stoi(st.top());
                st.pop();
                int operand2 = stoi(st.top());
                st.pop();
                st.push(to_string(operate(tok, operand2, operand1)));
            }
            else {
                st.push(tok);
            }
        }
        return stoi(st.top());
    }
};

int main() {
    Solution sol;
    return 0;
}

