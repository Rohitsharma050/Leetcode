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
bool preorder(TreeNode* root,int x)
{
    if(root==NULL)
    return true;
    if(root->val!=x)
    return false;
    return preorder(root->right,x) &&  preorder(root->left,x);
    return true;
}
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
        return true;
        return preorder(root,root->val);
    }
};
