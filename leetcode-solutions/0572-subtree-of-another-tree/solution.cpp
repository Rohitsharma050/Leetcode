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
bool check(TreeNode* r,TreeNode* s)
{
    if(r==NULL && s==NULL)
    return true;
    if(r==NULL || s==NULL)
    return false;
    
    if(r->val!=s->val)
    return false;
    return check(r->left,s->left) && check(r->right,s->right);




}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {     
        if(root==NULL)
        return false;
        if(check(root,subRoot))
        return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
