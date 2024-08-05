#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left_node, TreeNode *right_node) {
        if (left_node == nullptr && right_node == nullptr)
            return true;
        if (left_node == nullptr || right_node == nullptr)
            return false;
        if (left_node->val != right_node->val)
            return false;

        return dfs(left_node->left, right_node->right) &&
               dfs(left_node->right, right_node->left);
    }
};

int main() {
    Solution sol;
    return 0;
}
