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
void solve(TreeNode* root,int &sum,int number)
{
    if(root==NULL)
    return;
    number=number*10+root->val;
    if(!root->left && !root->right)
    {
        sum+=number;
    }
    solve(root->left,sum,number);
    solve(root->right,sum,number);
}
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};
