/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class box {
    public:
        int sum; // Maximum sum of BST in the current subtree
        int min; // Minimum value in the current subtree
        int max; // Maximum value in the current subtree
        bool isBST; // Whether the current subtree is a valid BST

        box(int sum, int min, int max, bool isBST) {
            this->sum = sum;
            this->min = min;
            this->max = max;
            this->isBST = isBST;
        }
    };

    // Helper function to calculate the max sum of BST in the tree
    box solve(TreeNode* root, int &maxSum) {
        if (!root) {
            // Base case: Return an empty subtree with sum 0, min INT_MAX, max INT_MIN
            return box(0, INT_MAX, INT_MIN, true);
        }

        // Recursively process the left and right subtrees
        box left = solve(root->left, maxSum);
        box right = solve(root->right, maxSum);

        // Check if the current subtree rooted at 'root' is a BST
        if (left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
            // Calculate the sum, min, and max for the current BST
            int currentSum = left.sum + right.sum + root->val;
            maxSum = std::max(maxSum, currentSum);
            return box(
                currentSum,
                std::min(root->val, left.min),
                std::max(root->val, right.max),
                true // Current subtree is a BST
            );
        }

        // If not a BST, return invalid values and propagate the largest valid BST sum
        return box(
            std::max(left.sum, right.sum), // Maximum sum of valid BSTs in subtrees
            INT_MIN,                       // Mark this subtree as invalid
            INT_MAX,                       // Mark this subtree as invalid
            false                          // Current subtree is not a BST
        );
    }

    // Main function to find the maximum sum BST in the binary tree
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};

