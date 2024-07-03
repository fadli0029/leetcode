#include "binary_tree.h"
// Note that the following is defined as private:
//    TreeNode* root;
//    unsigned int num_nodes;
//
// And the following is the TreeNode struct definition:
//    struct TreeNode {
//        int val;
//        TreeNode* left;
//        TreeNode* right;

//        // Default constructor
//        TreeNode() : val(0), left(nullptr), right(nullptr) {}

//        // Other constructors
//        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//    };


BinaryTree::BinaryTree() : root(nullptr), num_nodes(0) {}
BinaryTree::~BinaryTree() {
    clear();
}

bool BinaryTree::search(const int& query) {
}

void BinaryTree::insert(int val) {
}

void BinaryTree::remove(int val) {
}

void BinaryTree::clear() {
}

unsigned int BinaryTree::size() const {
}

// Print the preorder traversal of the binary tree nodes' values starting from the root
void BinaryTree::preorder() {
}

// Print the inorder traversal of the binary tree nodes' values starting from the root
// see: leetcode, 144
void BinaryTree::inorder() {
}

// Print the postorder traversal of the binary tree nodes' values starting from the root
void BinaryTree::postorder() {
}

// Print the level order traversal of the binary tree nodes' values starting from the root
void BinaryTree::levelorder() {
}

void BinaryTree::invert() {
}

int BinaryTree::diameter() const {
}

int BinaryTree::max_depth() const {
}

bool BinaryTree::is_height_balanced() const {
}

bool BinaryTree::is_same_tree(TreeNode* other_root) const {
}

bool BinaryTree::is_subtree(TreeNode* other_root) const {
}
