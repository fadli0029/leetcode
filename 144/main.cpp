#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    vector<int> preorderTraversal(TreeNode* root) {
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
            // access and then pop (remove) the top element in the stack.
            TreeNode* curr_node_ptr = s.top();
            s.pop();

            if (!h.contains(curr_node_ptr)) {
                h.insert(curr_node_ptr);
                result.push_back(curr_node_ptr->val);

                // Iterate the neighbors via pre-order traversal policy:
                //            = traverse left-subtree first
                // i.e.: due to the nature of a stack data structure, to
                //       do this, we push right child first so that left
                //       child is processed first.
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     dfs(root, result);
    //     return result;
    // }

    // void dfs(TreeNode* node, vector<int>& result) {
    //     if (node == nullptr) {
    //         return;
    //     }

    //     result.push_back(node->val);
    //     dfs(node->left, result);
    //     dfs(node->right, result);
    // }
};

int main() {
    Solution sol;
    return 0;
}

