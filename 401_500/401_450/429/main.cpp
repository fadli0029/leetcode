#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int n_levels = q.size();
            vector<int> curr_res;

            for (int i = 0; i < n_levels; i++) {
                Node *curr = q.front();
                q.pop();

                curr_res.push_back(curr->val);

                for (const auto &child : curr->children) {
                    q.push(child);
                }
            }
            res.push_back(curr_res);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
