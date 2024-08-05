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
    int diameterOfBinaryTree(TreeNode *root) {
        int curr_max = 0;
        dfs(root, curr_max);
        return curr_max;
    }

    int dfs(TreeNode *node, int &curr_max) {
        if (node == nullptr)
            return 0;

        int depth_lst = dfs(node->left, curr_max);
        int depth_rst = dfs(node->right, curr_max);

        curr_max = max(curr_max, depth_lst + depth_rst);
        return max(depth_lst, depth_rst) + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}
