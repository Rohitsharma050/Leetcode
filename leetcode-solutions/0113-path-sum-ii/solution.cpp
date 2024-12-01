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
vector<vector<int>> checkPath(TreeNode* root, int target, vector<vector<int>>&ans,vector<int>temp,int sum)
{
    if(root)
    {
        sum+=root->val;
        temp.push_back(root->val);
        if((!root->left && !root->right) && sum==target)
        {
            ans.push_back(temp);
        }
         checkPath(root->left,target,ans,temp,sum);
         checkPath(root->right,target,ans,temp,sum);
        
    }
    return ans;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        vector<int>temp;
        checkPath(root,targetSum,ans,temp,0);
        return ans;
    }

};
