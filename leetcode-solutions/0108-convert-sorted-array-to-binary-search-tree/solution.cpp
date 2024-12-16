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
TreeNode* build(vector<int>& nums,int n,int s,int e)
{
    if(s>e)
    return NULL;
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums,n,s,mid-1);
    root->right = build(nums,n,mid+1,e);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        return build(nums,n,s,e);
    }
};
