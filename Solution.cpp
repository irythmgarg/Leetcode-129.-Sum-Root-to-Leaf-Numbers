/**
 * Definition for a binary tree node.
 * Struct representing a node in the binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with only value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int mainans;  // Holds the sum of all root-to-leaf numbers

    /**
     * Recursive helper function to build numbers from root to leaf.
     * @param root: Current node
     * @param anstill: Integer representing the number formed so far
     */
    void nope(TreeNode* root, int anstill)
    {
        // Add current node's digit to the number
        anstill = anstill * 10 + root->val;

        // Recursive call to left child if exists
        if (root->left)
            nope(root->left, anstill);

        // Recursive call to right child if exists
        if (root->right)
            nope(root->right, anstill);

        // If leaf node is reached, add to total sum
        if (!root->left && !root->right)
            mainans += anstill;

        return;
    }

    /**
     * Main function that initiates recursive sum generation from root.
     * @param root: Root of the binary tree
     * @return Total sum of all root-to-leaf numbers
     */
    int sumNumbers(TreeNode* root) {
        int anstill = 0;
        nope(root, anstill);
        return mainans;
    }
};
