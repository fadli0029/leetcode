#include <complex>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// ====================================================================
// Quick sort & Lomuto partitioning scheme
// ====================================================================
int lomuto(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[j], arr[i]);
            i++;
        } else {
            continue;
        }
    }

    // i currently points to where pivot should be
    swap(arr[i], arr[right]);
    return i;
}

void quick_sort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = lomuto(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}
// ====================================================================

// ====================================================================
// Array to BST
// ====================================================================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *helper(vector<int> nums, int lp, int rp) {
    if (lp > rp)
        return nullptr;

    int mid = lp + (rp - lp) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(nums, lp, mid - 1);
    node->right = helper(nums, mid + 1, rp);
    return node;
}

TreeNode *ArrayToBST(vector<int> &nums) {
    quick_sort(nums, 0, nums.size() - 1);
    return helper(nums, 0, nums.size() - 1);
}
// ====================================================================

// ====================================================================
// BST to Array
// ====================================================================
void dfs_inorder(TreeNode *node, vector<int> &result) {
    // Why inorder? Because inorder traversal visits the nodes
    // of a binary tree from left to root to right. So,
    // if the binary tree is a BST, then this is equivalent
    // to visiting in ascending order, which is what we want.
    if (node == nullptr) {
        return;
    }

    dfs_inorder(node->left, result);
    result.push_back(node->val);
    dfs_inorder(node->right, result);
}

vector<int> BSTToArray(TreeNode *root) {
    vector<int> result;
    dfs_inorder(root, result);
    return result;
}
// ====================================================================

// ====================================================================
// Tree level-order traversal (BFS)
// ====================================================================
vector<vector<int>> bfs(TreeNode *root) {
    if (root == nullptr)
        return {};

    vector<vector<int>> res;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        // number of elements in the current level
        int num = q.size();
        vector<int> curr_res;

        for (int i = 0; i < num; i++) {
            TreeNode *curr = q.front();
            q.pop();

            curr_res.push_back(curr->val);

            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        res.push_back(curr_res);
    }
    return res;
}
// ====================================================================
