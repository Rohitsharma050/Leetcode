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
void insertNode(TreeNode* &root, TreeNode* prev,int val)
{
    if(root==NULL)
    {
        TreeNode* Node = new TreeNode(val);
        if(prev->val>val)
        {
            prev->left = Node;
            return;
        }
        else
        prev->right = Node;
        return;
    }
    if(root->val>val)
    {
        prev = root;
        insertNode(root->left,prev,val);
    }
    else
    {
        prev = root;
        insertNode(root->right,prev,val);
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
       {
            TreeNode* Node = new TreeNode(val);
            return Node;
       }
        TreeNode* prev = NULL;
        insertNode(root,prev,val);
        return root;
    }
};
