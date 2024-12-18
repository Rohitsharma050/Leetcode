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
int solve(TreeNode* &root,int &ans)
{
    if(root==NULL)
    return 0;
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    int diff = abs(l-r);
    int sum=root->val+l+r;
    root->val = diff;

    ans += root->val;
    return sum;

}
    int findTilt(TreeNode* root) {
        if(root==NULL)
        return 0;
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
