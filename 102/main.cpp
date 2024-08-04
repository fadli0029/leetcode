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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {{}};

        vector<vector<int>> result;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int curr_lvl_size = q.size();
            vector<int> current_result;
            for (int i = 0; i < curr_lvl_size; i++) {
                TreeNode *curr = q.front();
                q.pop();

                current_result.push_back(curr->val);

                // visit its childrens and put them in the queue
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            result.push_back(current_result);
        }
        return result;
    }
};

int main() {
    Solution sol;
    return 0;
}
