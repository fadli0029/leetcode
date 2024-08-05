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
    bool hasPathSum(TreeNode *root, int targetSum) {
        return dfs(root, targetSum);
    }

    bool dfs(TreeNode *node, int currSum) {
        if (node == nullptr)
            return false;

        currSum -= node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (currSum == 0)
                return true;
        }

        return dfs(node->left, currSum) || dfs(node->right, currSum);
    }
};

int main() {
    Solution sol;
    return 0;
}
