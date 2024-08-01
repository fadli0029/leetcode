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
    TreeNode* invertTree(TreeNode* root) {
      dfs(root);
      return root;
    }

    void dfs(TreeNode* node) {
      if (node == nullptr) return;

      // swap left child with right child, or vice versa
      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;

      dfs(node->left);
      dfs(node->right);
    }
};

int main() {
    Solution sol;
    return 0;
}

