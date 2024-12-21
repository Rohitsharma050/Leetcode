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
int findMaxElement(vector<int>& nums,int s,int e)
{
    int max = nums[s];
    int index = s;
    for(int i = s;i<e+1;i++)
    {
        if(nums[i]>max)
        {
            index = i;
            max = nums[i];
        }

    }
    return index;
}
TreeNode* build(vector<int>& nums,int s,int e)
{
    if(s>e)
    return NULL;
    int max = findMaxElement(nums,s,e);
    TreeNode* root = new TreeNode(nums[max]);
    root->right = build(nums,max+1,e);
    root->left = build(nums,s,max-1);
    return root;

}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return NULL;
        //sort(nums.begin,nums.end());
        return build(nums,0,n-1);

    }
};
