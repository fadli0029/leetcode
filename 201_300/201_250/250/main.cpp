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
    int countUnivalSubtrees(TreeNode *root) {
        int count = 0;
        dfs(root, count);
        return count;
    }

    bool dfs(TreeNode *node, int &count) {
        if (node == nullptr)
            return true;

        bool leftsubtree_univalue = dfs(node->left, count);
        bool rightsubtree_univalue = dfs(node->right, count);

        if (leftsubtree_univalue && rightsubtree_univalue) {
            if (node->left != nullptr && node->val != node->left->val) {
                return false;
            }
            if (node->right != nullptr && node->val != node->right->val) {
                return false;
            }

            count++;
            return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}
