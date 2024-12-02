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
void findPath(TreeNode* root, int target,int &total,long long currSum,unordered_map<long long,int>mp)
{
    if(root==NULL)
    return;
    currSum+=root->val;
    if(mp.find(currSum-target)!=mp.end())
    total +=mp[currSum-target];
    mp[currSum]++;
    findPath(root->left,target,total,currSum,mp);
    findPath(root->right,target,total,currSum,mp);

}
    int pathSum(TreeNode* root, int target) {
        if(root==NULL)
        return 0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        int total = 0;
        long long currSum = 0;
        findPath(root,target,total,currSum,mp);
        return total;
    }
};
