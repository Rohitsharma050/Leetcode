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
    int minDepth(TreeNode* root) {
        if (root==NULL)
        return 0;
        if (root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        //if left subtree of the root is NULL than calculate right subtree depth

        if(root->left==NULL)
        {
            return minDepth(root->right)+1;
        }
        
 //if right subtree of the root is NULL than calculate left subtree depth
        if(root->right==NULL)
        {
            return minDepth(root->left)+1;
        }

        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return min(l,r)+1;
    }
};
