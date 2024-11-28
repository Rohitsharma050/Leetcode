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
//populate the map
void index(unordered_map<int,int>&findPosition,vector<int>& inorder,int size)
{
    for(int i =0;i<size;i++)
    {
        findPosition[inorder[i]] = i;
    }
}
TreeNode* build(vector<int>& inorder, vector<int>& postorder,int &postindex,int instart,int inend,unordered_map<int,int>&findPosition,int size)
{
    if(postindex<0 || instart>inend)
    return NULL;
    //collect root value from postorder
    int element = postorder[postindex];

    //create root
     TreeNode* root = new TreeNode(element);

     //decrease postindex 
     postindex--;

     //find position of the rootin inorder

     int position = findPosition[element];

     
      //recursive call for right subtree[in case of postorder we create firstly right tree]
      root->right = build(inorder,postorder,postindex,position+1,inend,findPosition,size);
      //recursive call for left subtree
      
      root->left = build(inorder,postorder,postindex,instart,position-1,findPosition,size);
      return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postindex = size-1;
        int instart = 0;
        int inend = size-1;
        //Store elements of inorder in map to access the indexin O(1)
        unordered_map<int,int>findPosition;
        index(findPosition,inorder,size);
        return build(inorder,postorder,postindex,instart,inend,findPosition,size);
    }
};
