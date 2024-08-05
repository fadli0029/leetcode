#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
      // max depth of BT = height of root of BT
      return dfs(root);
    }

    int dfs(TreeNode* node) {
      if (node==nullptr) return 0;

      int left_subtree_depth = dfs(node->left);
      int right_subtree_depth = dfs(node->right);

      return max(left_subtree_depth, right_subtree_depth) + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}

