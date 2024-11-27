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
    int widthOfBinaryTree(TreeNode* root) {
        // Variable to store the maximum width of the binary tree
        long long ans = 0;

        // If the tree is empty, return 0
        if (!root)
            return ans;

        // Queue to perform level-order traversal. Each element is a pair containing the node
        // and its 'index' based on a virtual complete binary tree representation.
        queue<pair<TreeNode*, long long>> q;

        // Start with the root node at index 0
        q.push({root, 0});

        // Traverse the tree level by level
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            long long minimumIndex = q.front().second; // Base index for the current level to avoid overflow
            long long first, last; // Variables to track the first and last indices at this level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first; // Current node
                long long currIndex = q.front().second - minimumIndex; // Normalize index to prevent large values
                q.pop(); // Remove the processed node from the queue

                // Store the first index of the level
                if (i == 0)
                    first = currIndex;

                // Store the last index of the level
                if (i == size - 1)
                    last = currIndex;

                // Add the left child to the queue with its computed index
                if (node->left) {
                    q.push({node->left, 2 * currIndex + 1});
                }

                // Add the right child to the queue with its computed index
                if (node->right) {
                    q.push({node->right, 2 * currIndex + 2});
                }
            }

            // Update the maximum width using the indices of the first and last nodes
            ans = max(ans, last - first + 1);
        }

        // Return the maximum width of the binary tree
        return ans;
    }
};

