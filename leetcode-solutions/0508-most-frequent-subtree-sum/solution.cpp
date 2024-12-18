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
unordered_map<int ,int>mp;
int postorder(TreeNode* root)
{
    if(root==NULL)
    return 0;
    int left = postorder(root->left);
    int right = postorder(root->right);
    int sum = root->val+left+right;
    mp[sum]++;
    return sum;
    
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        postorder(root);
        int mxfreq = 0;
        for(auto it:mp)
        {
            mxfreq = max(mxfreq,it.second);
        }
        for(auto it:mp)
        {
            if(it.second==mxfreq)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
