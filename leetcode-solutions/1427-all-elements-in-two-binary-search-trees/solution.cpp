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
void inorder(TreeNode* root,vector<int>&v)
{
    if(!root)
    return ; 
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int>r1,r2;
       vector<int>ans;
       if(!root1 && !root2)
       return ans;
       inorder(root1,r1);
       inorder(root2,r2);
        int i = 0;
        int j = 0;
        while(i<r1.size() && j<r2.size())
        {
            if(r1[i]<r2[j])
            {
                ans.push_back(r1[i]);
                i++;
            }
            else
            {
                ans.push_back(r2[j]);
                j++;
            }
        }
        while(i<r1.size())
        {       
                ans.push_back(r1[i]);
                i++;
        }
        while(j<r2.size())
        {
            ans.push_back(r2[j]);
                j++;
        }
return ans;
    }
};
