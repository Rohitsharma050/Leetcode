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
void inorder(TreeNode* root,vector<int>&temp)
{
    if(root)
    {
        inorder(root->left,temp);
        temp.push_back(root->val);
         inorder(root->right,temp);
    }
}
TreeNode* createBst(int s,int e,vector<int>temp)
{
    if(s>e)
    return NULL;
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(temp[mid]);
    root->left = createBst(s,mid-1,temp);
    root->right = createBst(mid+1,e,temp);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
       return createBst(0,temp.size()-1,temp);

    }
};
