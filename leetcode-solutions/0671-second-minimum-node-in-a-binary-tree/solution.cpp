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
 int smallest; // Store the smallest value
    int second_min; // Store the second smallest value

    void dfs(TreeNode* node) {
        if (!node) return;

        // Check if the current node's value is a candidate for second smallest
        if (node->val > smallest && (second_min == -1 || node->val < second_min)) {
            second_min = node->val;
        }

        // Continue DFS traversal
        dfs(node->left);
        dfs(node->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root || !root->left || !root->right) return -1;

        smallest = root->val;
        second_min = -1;

        dfs(root);

        return second_min;
        
    }
};
