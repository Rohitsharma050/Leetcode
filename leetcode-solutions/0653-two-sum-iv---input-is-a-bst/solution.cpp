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
void inorder(TreeNode* root,vector<int>&temp)
{
    if(root==NULL)
    return ;
    inorder(root->left,temp);
    temp.push_back(root->val);
    inorder(root->right,temp);
}
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        {
            return false;
        }
        vector<int>temp;
        inorder(root,temp);
        int n = temp.size();
        int j = n-1;
        int i = 0;
        while(i<j)
        {
            if(temp[i]+temp[j]==k)
            return true;
            else if(temp[i]+temp[j]>k)
            j--;
            else
            i++;
        }
        return false;

    }
};
