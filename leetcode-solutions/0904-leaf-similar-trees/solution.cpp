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
vector<int> countLeaf(TreeNode* root,vector<int>&leaf)
{
    if(root)
    {
        if(!root->left && !root->right)
        leaf.push_back(root->val);
        countLeaf(root->left,leaf);
        countLeaf(root->right,leaf);
    
    }
return leaf;
}
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {

        vector<int>l1,l2;
        countLeaf(r1,l1);
        countLeaf(r2,l2);
        return l1==l2;
        
    }
};
