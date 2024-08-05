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
    // A function that does dfs and then recursively call this function
    // is implicity ly applying stack LIFO property. This is due to
    // the fact that we recursively call the function implicitly
    // which means we are leveraging the stack data structure.
    // But, for checking understanding, ill implement both using stack.
    // and recursion.

    // Stack implementation:
    vector<int> postorderTraversal(TreeNode* root) {
        // result
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        // Next nodes to potentially visit, track with a stack s.
        stack<TreeNode*> s;

        // Set of visited nodes, track with a hash set h.
        // You can't store int type (i.e.: the data type of
        // the TreeNode) bcoz what if multiple nodes have
        // same data (this can happen in general binary tree,
        // but not in binary search tree which doesn't allow duplicate).
        unordered_set<TreeNode*> h;

        // traverse until stack is empty
        s.push(root);
        while (!s.empty()) {
            // access but DON'T pop (remove) the top element in the stack yet.
            TreeNode* curr_node_ptr = s.top();

            // check if both left and right subtree is completely visited first,
            // then only we can visit the current parent (at some point, this
            // parent will be the root), this is post-order traversal by definition.
            if ((curr_node_ptr->right == nullptr || h.contains(curr_node_ptr->right)) &&
                (curr_node_ptr->left  == nullptr || h.contains(curr_node_ptr->left))) {
                h.insert(curr_node_ptr);
                s.pop();

                result.push_back(curr_node_ptr->val);
            }

            // Otherwise, we need to completely visit both left and right subtree first.
            else {
                if (curr_node_ptr->right != nullptr && !h.contains(curr_node_ptr->right)) {
                    s.push(curr_node_ptr->right);
                }
                if (curr_node_ptr->left != nullptr && !h.contains(curr_node_ptr->left)) {
                    s.push(curr_node_ptr->left);
                }
            }

        }
        return result;
    }

    // Recursive implementation:
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     dfs(root, result);
    //     return result;
    // }

    // void dfs(TreeNode* node, vector<int>& result) {
    //     if (node == nullptr) {
    //         return;
    //     }

    //     dfs(node->left, result);
    //     dfs(node->right, result);
    //     result.push_back(node->val);
    // }
};

int main() {
    Solution sol;
    return 0;
}

