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
void inorder(TreeNode* root,unordered_map<int,int>&mp)
{
    if(root)
    {
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);

    }
}
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        inorder(root,mp);
        int maxfreq = 0;
        for(auto it:mp)
        {
            maxfreq = max(maxfreq,it.second);
        }
        vector<int>ans;
        for(auto it : mp)
        {
            if(it.second==maxfreq)
            ans.push_back(it.first);
        }
        return ans;

    }
};
