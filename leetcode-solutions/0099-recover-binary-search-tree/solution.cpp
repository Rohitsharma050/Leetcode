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
TreeNode* first = NULL;
TreeNode* second = NULL;
void inorder(TreeNode* curr,TreeNode* &prev)
{
    if(curr)
    {
        inorder(curr->left,prev);
        if(prev!=NULL && prev->val>curr->val)
        {
            if(first==NULL)
            {
                first = prev;
                second = curr;
            }
            if(first!=NULL)
            {
                second = curr;
            }
        }
        prev = curr;
        inorder(curr->right,prev);
    }
}
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root,prev);
        swap(first->val,second->val);
    }
};
