/* This TreeNode definition is borrowed from Leetcode problem definitions */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Other constructors
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        bool search(const int& query);
        void insert(int val);
        void remove(int val);
        void clear();
        unsigned int size() const;

        // Traversal methods
        // 1. DFS variants (all of these 3 are DFS)
        void preorder();
        void inorder();
        void postorder();
        // 2. BFS
        void levelorder();

        void invert();

        int diameter() const;
        int max_depth() const;
        bool is_height_balanced() const;

        bool is_same_tree(TreeNode* other_root) const;
        bool is_subtree(TreeNode* other_root) const;

    private:
        TreeNode* root;
        unsigned int num_nodes;
};
