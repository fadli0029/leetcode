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
    int maxDepth(Node *root) { return dfs(root); }

    int dfs(Node *node) {
        if (node == nullptr)
            return 0;

        int max_depth = 0;
        for (const auto &child : node->children) {
            max_depth = max(max_depth, dfs(child));
        }

        return max_depth + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}
