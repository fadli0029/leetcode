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
    bool isBalanced(TreeNode *root) { return dfs(root) != -1; }

    int dfs(TreeNode *node) {
        if (node == nullptr)
            return 0;

        int depth_lst = dfs(node->left);
        if (depth_lst == -1)
            return -1;

        int depth_rst = dfs(node->right);
        if (depth_rst == -1)
            return -1;

        if (abs(depth_lst - depth_rst) > 1)
            return -1;

        return max(depth_lst, depth_rst) + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}
