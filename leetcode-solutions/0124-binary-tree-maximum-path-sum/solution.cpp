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
int getsum(TreeNode* root,int &sum)
{
    if(root==NULL)
    return 0 ;
    int l = max(0,getsum(root->left,sum));
    int r = max(0,getsum(root->right,sum));
    sum = max(sum,root->val+r+l);
    return root->val+max(l,r);
}
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        int sum = INT_MIN;
        getsum(root,sum);
        return sum;
    }
};
