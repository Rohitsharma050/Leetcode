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
void index(unordered_map<int,int>&findPosition,vector<int>& inorder,int size)
{
    for(int i =0;i<size;i++)
    {
        findPosition[inorder[i]] = i;
    }
}
TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &preindex,int instart,int inend,int size,unordered_map<int,int>&findPosition)
{
    //base case
    if(preindex>=size || instart>inend)
    {
        return NULL;
    }
    int element = preorder[preindex];
    TreeNode * root = new TreeNode(element);
    int position = findPosition[element];
    preindex++;
    root->left = build(preorder,inorder,preindex,instart,position-1,size,findPosition);
    root->right= build(preorder,inorder,preindex,position+1,inend,size,findPosition);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preindex = 0;
        int instart = 0;
        int inend = size-1;
        unordered_map<int ,int>findPosition;
        index(findPosition,inorder,size);
        return build(preorder,inorder,preindex,instart,inend,size,findPosition);
    }
};
