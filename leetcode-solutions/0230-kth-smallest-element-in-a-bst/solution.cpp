class Solution {
public:
    int find(TreeNode* root, int &i, int k) {
        if (root == NULL)
            return -1; // Return an invalid value if the node is NULL.

        // Recurse on the left subtree.
        int left = find(root->left, i, k);
        if (left != -1) // If the kth smallest element is found in the left subtree, return it.
            return left;

        // Visit the current node.
        i++;
        if (i == k)
            return root->val;

        // Recurse on the right subtree.
        return find(root->right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0; // Start the index from 0.
        return find(root, i, k);
    }
};

