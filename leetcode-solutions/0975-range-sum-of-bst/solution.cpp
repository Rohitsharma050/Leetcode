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
int ans= 0;
void inorder(TreeNode* root,int l,int h)
{
    if(root==NULL)
    return ;
    inorder(root->left,l,h);
    if(root->val>=l && root->val<=h)
    {
        ans+=root->val;
    }
     inorder(root->right,l,h);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL)
        return ans;
        inorder(root,low,high);
        return ans;
    }
};
