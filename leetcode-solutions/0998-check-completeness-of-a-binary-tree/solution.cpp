class Solution {
public:
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    bool isCompleteTree(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool mustBeLeaf = false;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                mustBeLeaf = true;
            }
             else {
                if (mustBeLeaf) {
                    return false; // Any node after a NULL must also be NULL.
                }
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return true;
    }
};

