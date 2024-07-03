// NEED TO REDO
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
    int diameterOfBinaryTree(TreeNode* root) {
        // Claim:
        //  The two end nodes of the longest
        //  path must be leaf nodes.
        // Proof:
        //  Suppose one of the end nodes, n1, is
        //  not a leaf node, then we can always
        //  make the path longer: extend the path
        //  by taking the child of n1.

        // Strategy:
        //  For every node n, run dfs on the left subtree
        //  and on the right subtree, while tracking how many
        //  edges in both dfs run and summing them.
        //  Then we can keep updating the longest
        //  path (i.e.: diameter) along the way.
        int curr_max = 0;
        dfs(root, curr_max);
        return curr_max;
    }

    int compute_path_length(TreeNode* node) {
        int left_path_length = 0;
        search_left_leaf(node, left_path_length);

        int right_path_length = 0;
        search_left_leaf(node, right_path_length);

        int path_length = left_path_length + right_path_length;
        return path_length;
    }

    void dfs(TreeNode* node, int& curr_max) {
        if (node==nullptr) {
            return;
        }

        // -----------------------------------------
        // If necessary, do something with the node
        // before proceeding.
        int path_length = compute_path_length(node);
        if (path_length > curr_max) {
            curr_max = path_length;
        }
        // -----------------------------------------

        dfs(node->left, curr_max);
        dfs(node->right, curr_max);
    }

    void search_left_leaf(TreeNode* node, int& count) {
        if (node==nullptr) {
            return;
        }

        // If necessary, do something with the node
        // before proceeding.
        count++;
        search_left_leaf(node->left, count);
    }

    void search_right_leaf(TreeNode* node, int& count) {
        if (node==nullptr) {
            return;
        }

        // If necessary, do something with the node
        // before proceeding.
        count++;
        search_right_leaf(node->left, count);
    }
};

int main() {
    Solution sol;
    return 0;
}

