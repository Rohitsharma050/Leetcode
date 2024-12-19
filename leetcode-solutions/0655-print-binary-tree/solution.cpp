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
int getHeight(TreeNode* root)
{
    if(root==NULL)
    return 0;
    return 1+max(getHeight(root->left),getHeight(root->right));
}
void print(TreeNode* root, vector<vector<string>>&ans,int level,int s,int e)
{
    if(root==NULL)
    return ;
    int mid = (s+e)/2;
    ans[level][mid] = to_string(root->val);
    print(root->left,ans,level+1,s,mid-1);
    print(root->right,ans,level+1,mid+1,e);

}
    vector<vector<string>> printTree(TreeNode* root) {
        int r = getHeight(root);
        int c = pow(2,r)-1;
        vector<vector<string>>ans(r,vector<string>(c,""));
        print(root,ans,0,0,c-1);
        return ans;
    }
};
