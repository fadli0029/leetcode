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
    vector<int> inorderTraversal(TreeNode* root) {
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

        // We should not push the root to the stack since
        // this is inorderTraversal, so we must completely finish traversing
        // left subtree first.
        TreeNode* curr_node_ptr = root;
        while (curr_node_ptr!=nullptr || !s.empty()) {
            // Traverse until we reach leftmost node of the current node
            while (curr_node_ptr!=nullptr) {
                s.push(curr_node_ptr);
                curr_node_ptr = curr_node_ptr->left;
            }

            // curr_node_ptr now is pointing to nullptr.
            // we pop (remove) the top element in the stack which
            // should not be the nullptr. If your tree is:
            //     1
            //    / \
            //   2   5
            //  / \
            // 3   4
            // Then in the first iteration of the outer while loop,
            // after the inner while loop finishes, the stack should be:
            // [  3  ]
            // [  2  ]
            // [  1  ]
            // so curr_node_ptr now points to 3.
            curr_node_ptr = s.top();
            s.pop();

            if (!h.contains(curr_node_ptr)) {
                h.insert(curr_node_ptr);
                result.push_back(curr_node_ptr->val);
            }

            // Now we visit right subtree, if it exists, of the current node.
            curr_node_ptr = curr_node_ptr->right;
        }
        return result;
    }

    // Recursive implementation:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     dfs(root, result);
    //     return result;
    // }

    // void dfs(TreeNode* node, vector<int>& result) {
    //     if (node == nullptr) {
    //         return;
    //     }

    //     dfs(node->left, result);
    //     result.push_back(node->val);
    //     dfs(node->right, result);
    // }
};

int main() {
    Solution sol;
    return 0;
}

