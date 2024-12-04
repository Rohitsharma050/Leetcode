class Solution {
public:
    void solve(TreeNode* root, int val, int curr, int depth) {   
        if (root == NULL)
            return;

        // If the current level is just before the target depth, add the new row.
        if (curr == depth - 1) {
            TreeNode* leftChild = new TreeNode(val);
            TreeNode* rightChild = new TreeNode(val);

            leftChild->left = root->left;
            rightChild->right = root->right;

            root->left = leftChild;
            root->right = rightChild;

            return; // No need to go further.
        }

        // Recursively process the left and right children.
        solve(root->left, val, curr + 1, depth);
        solve(root->right, val, curr + 1, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: if the new row is to be added as the new root.
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        // Call the helper function to modify the tree in place.
        solve(root, val, 1, depth);

        return root;
    }
};

