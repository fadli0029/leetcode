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

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        bool search(const int& query);
        void insert(int val);
        void remove(int val);
        void clear();
        TreeNode* get_leftmost_node();
        unsigned int size() const;

        void print();

    private:
        TreeNode* root;
        unsigned int num_nodes;
};
