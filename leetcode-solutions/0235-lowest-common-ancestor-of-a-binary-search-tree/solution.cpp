class Solution {
public:
    // TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == NULL)
    //         return NULL;

    //     // If both nodes are smaller than the root, move to the left subtree
    //     if (root->val > p->val && root->val > q->val)
    //         return find(root->left, p, q);

    //     // If both nodes are larger than the root, move to the right subtree
    //     if (root->val < p->val && root->val < q->val)
    //         return find(root->right, p, q);

    //     // If the nodes are on opposite sides, root is the LCA
    //     return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        while(root)
        {
            if(root->val>p->val && root->val>q->val)
            {
                root = root->left;
            }
            else if(root->val<p->val && root->val<q->val)
            {
                root = root->right;
            }
            else
            return root;
        }
        return root;
    }
};

