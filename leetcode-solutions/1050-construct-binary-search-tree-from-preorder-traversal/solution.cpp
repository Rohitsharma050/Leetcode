class Solution {
public:
    TreeNode* createBst(vector<int> preorder, int &i, int min, int max) {
        // Base case: Stop if index is out of range or value is out of bounds
        if (i == preorder.size() || preorder[i] <= min || preorder[i] >= max) {
            return nullptr;
        }

        // Create the current node
        TreeNode* root = new TreeNode(preorder[i]);
        i++; // Move to the next index

        // Recursively build the left and right subtrees
        root->left = createBst(preorder, i, min, root->val); // Left subtree with updated max
        root->right = createBst(preorder, i, root->val, max); // Right subtree with updated min

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return createBst(preorder, i, INT_MIN, INT_MAX);
    }
};

